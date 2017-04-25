/*
This file stores the accessor and mutator functions for the classes declared
in the header file "hospital.h"
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay.                                                       |
 -------------------------------------------------------------------
*/

#include "hospital.h"

void assignDoc(patient * p);

//.......Patient Functions..........//
void patient::getName(string &fname, string &lname)
{
	fname = patient::fname;
	lname = patient::lname;
}

void patient::getID(string &id)
{
	id = patient::ID;
}

void patient::setName(string fname, string lname)
{
	patient::fname = fname;
	patient::lname = lname;
}

void patient::setSymptoms (string symp)
{
	patient::symptoms.push_back(toSympInt(symp));
}

//.......Doctor Functions..........//

void doctor::setName(string name)
{
	doctor::name = name;
}

void doctor::getName(string &name)
{
	name = doctor::name;
}

void doctor::getID(string &id)
{
	id = doctor::ID;
}

void doctor::setID(string id)
{
	doctor::ID = id;
}

void doctor::getFieldID(int &id)
{
	id = doctor::fieldID;
}

void doctor::setFieldID(int id)
{
	doctor::fieldID = id ;
}

void initialiseDoctors();
{
	doctor d1;
	d1.setName("Physician A");
	d1.setID ("a");
	d1.setFieldID(1);
	d1.setWhatICanCure();
	AllDoctors.push_back(d1);

	doctor d2;
	d2.setName("Physician B");
	d2.setID ("b");
	d2.setFieldID(1);
	d2.setWhatICanCure();
	AllDoctors.push_back(d2);

	doctor d3;
	d3.setName("Orthopedic");
	d3.setID ("c");
	d3.setFieldID(2);
	d3.setWhatICanCure();
	AllDoctors.push_back(d3);

	doctor d4;
	d4.setName("Cardiologist");
	d4.setID ("d");
	d4.setFieldID(1);
	d4.setWhatICanCure();
	AllDoctors.push_back(d4);

	doctor d5;
	d5.setName("Neurologist");
	d5.setID ("e");
	d5.setFieldID(1);
	d5.setWhatICanCure();
	AllDoctors.push_back(d5);
}

void doctor::addToLine(patient * p)
{
	doctor::patientLine.push(p);
	cout << "Patient added to waiting line for Dr. " << doctor::name << endl;
}

void doctor::setWhatICanCure ()
{
	if (doctor::fieldID == 1 ) { 
		doctor::whatICanCure.push_back(0); 
		doctor::whatICanCure.push_back(1);
		doctor::whatICanCure.push_back(2);
	}

	if (doctor::fieldID == 2) { 
		doctor::whatICanCure.push_back(3); 
		doctor::whatICanCure.push_back(4);
	}
	if (doctor::fieldID == 3) { 
		doctor::whatICanCure.push_back(5); 
	}
	if (doctor::fieldID == 4) { 
		doctor::whatICanCure.push_back(6); 
	}
}

void patient::addPrescription(diagnosis prescript) {
	patient::prescription.push_back(prescript);
}

void doctor::diagnose(patient * p)
{
	for (int i=0; i<doctor::whatICanCure.size();i++)
	{
		for (int j=0; j<p->symptoms.size(); j++)
		{
			if (i==j)
			{
				diagnosis diag;
				diag.disease = toSympString(p->symptoms[j]);
				diag.treatment = "Tablets given for 5 days";
				p -> symptoms.erase(p->symptoms.begin()+j);
				p -> addPrescription(diag);

			}
		}
	}

doctor::patientLine.pop();
if (p->symptoms.size()!=0) 
{
		cout << "Patient is not yet cured send to another Doctor" << endl;
		assignDoc(p);
	}
}

int doctor::areUmyDoc(patient * p)
{
	for (int i=0; i<doctor::whatICanCure.size(); i++)
	{
		for (int j=0; j<p->symptoms.size(); j++)
		{
			if (i==j)
			{
				return doctor::patientLine.size();
			}
		}
	}

	return numeric_limits<int>::max();
	
}

void assignDoc(patient * p)
{
	int least_waiting = numeric_limits<int>::max(); // set to max initially
	doctor myDoctor;

	for (int i = 0; i <= AllDoctors.size(); i++) // iterating over all doctors to find the doctor with matching fieldID and minimun waiting
	{
		int curr_waiting = AllDoctors[i].areUmyDoc(p);
		if (curr_waiting < least_waiting)
		{	least_waiting = curr_waiting;
			myDoctor = AllDoctors[i];
		}
	}

	myDoctor.addToLine (p);
}

int doctor::get_queue_length() {
	return patientLine.size();
}