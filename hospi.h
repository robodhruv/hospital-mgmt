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
//Public Functions
string toSympString(int i)
{
    if ( i == 0) return "Cough";
    else if ( i == 1) return "Fever";
    else if ( i == 2) return "Diarrhea";
    else if ( i == 3) return "Fracture";
    else if ( i == 4) return "MuscleInjury";
    else if ( i == 5) return "HeartPain";
    else if ( i == 6) return "Alzheimer";
}

int toSympInt (string s)
{
    if ( s == "Cough") return 0;
    else if (s == "Fever") return 1;
    else if (s == "Diarrhea") return 2;
    else if (s == "Fracture") return 3;
    else if (s == "MuscleInjury") return 4;
    else if (s == "HeartPain") return 5;
    else if (s == "Alzheimer") return 6;

}

//Doctor Functions
void assignDoc(patient * p);

//.......Patient Functions..........//
void patient::getName(string &fname, string &lname)
{
	fname = patient::fname;
	lname = patient::lname;
}

patient::patient() {
	patient::fname = "";
	patient::lname = "";
	patient::ID = "";
}

void patient::getID(string &id)
{
	id = patient::ID;
}

void patient::setID(string id)
{
	patient::ID = id;
}

void patient::setName(string fname, string lname)
{
	string lower = "";
	locale loc;
	for (auto elem : fname)	lower.push_back(tolower(elem, loc));
	patient::fname = lower;

	lower = "";
	for (auto elem : lname)	lower.push_back(tolower(elem, loc));
	patient::lname = lower;

	stringstream ss;
	ss << counter;
	patient::ID = ss.str();
	counter++;
}

void patient::setSymptoms (string symp)
{
	patient::symptoms.push_back(toSympInt(symp));
}

void patient::getPrescriptionLenght()
{
	cout<< patient::prescription.size()<<endl;
}

int patient::symptomsSize()
{
	return patient::symptoms.size();
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

void initialiseDoctors() {
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
	d4.setFieldID(3);
	d4.setWhatICanCure();
	AllDoctors.push_back(d4);

	doctor d5;
	d5.setName("Neurologist");
	d5.setID ("e");
	d5.setFieldID(4);
	d5.setWhatICanCure();
	AllDoctors.push_back(d5);
}

void doctor::addToLine(patient * p)
{
	doctor::patientLine.push(p);
	string fname, lname;
	p -> getName(fname, lname);
	output_logs.push("Patient " + fname + " added to waiting line for Dr. " + doctor::name + ".\n");
	// cout << "Patient " <<  fname << " added to waiting line for Dr. " << doctor::name << endl;
}

void doctor::setWhatICanCure ()
{
	if (doctor::fieldID == 1) {
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

void doctor::diagnose()
{
	if (doctor::patientLine.size() == 0) return;
	patient * p = doctor::patientLine.front();
	for (int i = 0; i < doctor::whatICanCure.size(); i++)
	{
		for (int j = 0; j < p->symptoms.size(); j++)
		{
			if (whatICanCure[i]==p->symptoms[j])
			{
				diagnosis diag;
				diag.disease = toSympString(p->symptoms[j]);
				diag.treatment = "Tablets given for 5 days";
				output_logs.push("Patient " + p->fname + " examined for " + toSympString(p->symptoms[j]) + ".\n");
				p -> symptoms.erase(p -> symptoms.begin() + j);
				p -> addPrescription(diag);

			}
		}
	}

	doctor::patientLine.pop();
	if (p->symptoms.size() != 0)
	{
		output_logs.push("Patient " + p->fname + " is not yet cured send to another doctor.\n");
		assignDoc(p);
	} else output_logs.push("Patient " + p->fname + " discharged.\n");
}

int doctor::areUmyDoc(patient * p)
{
	for (int i = 0; i < doctor::whatICanCure.size(); i++)
	{
		for (int j = 0; j < p -> symptoms.size(); j++)
		{
			if (doctor::whatICanCure[i] == p -> symptoms[j])
			{
				return doctor::patientLine.size();
			}
		}
	}

	return numeric_limits<int>::max();

}

int findMyDoc(patient * p)
{
	int least_waiting = numeric_limits<int>::max(); // set to max initially
	doctor myDoctor;
	int min_i = numeric_limits<int>::max();
	for (int i = 0; i < AllDoctors.size(); i++) // iterating over all doctors to find the doctor with matching fieldID and minimun waiting
	{
		int curr_waiting = AllDoctors[i].areUmyDoc(p);
		if (curr_waiting < least_waiting)
		{	least_waiting = curr_waiting;
			myDoctor = AllDoctors[i];
			min_i = i;
		}
	}
	return min_i;
}

void assignDoc(patient * p)
{
	int min_i = findMyDoc(p);
	AllDoctors[min_i].addToLine(p);
}



void Emergency (patient * p)
{
	int i = findMyDoc(p);

	queue<patient*> newPatientLine;
	newPatientLine.push(p);

	while (! AllDoctors[i].patientLine.empty())
	{
	    patient * q = AllDoctors[i].patientLine.front();
	    newPatientLine.push(q);
	    AllDoctors[i].patientLine.pop();
	}

	AllDoctors[i].patientLine = newPatientLine;
	string fname, lname,name;
	AllDoctors[i].getName( name);
	p -> getName(fname, lname);
	output_logs.push("Emergency Patient added to the front of waiting line for Dr. " + name + ".\n");
}

int doctor::get_queue_length() {
	return patientLine.size();
}
