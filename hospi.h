/*
This file stores the accessor and mutator functions for the classes declared
in the header file "hospital.h"
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay.                                                        |
 -------------------------------------------------------------------
*/

#include "hospital.h"

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

//.......Doctor Functions..........//
void doctor::addToLine(patient &p)
{
	doctor::patientLine.pushback(p);
	cout<<"Patient added to waiting line for Dr. " << doctor::name << endl;
}

void doctor::diagnose(bool cured, int fieldIDNextDoc)
{
	if(cured)
	{
		cout<<"Patient has been cured"<<endl; // Patients name must also be displayed for this patients getName function should be changed
		doctor::patientLine.pop();
	}
	else
	{
		cout << "Patient is not yet cured send to another Doctor" << endl;
		assignDoc(patientLine.top(), fieldIDNextDoc);
	}
}

int doctor::areUmyDoc(int fieldID)
{
	if(fieldID == doctor::fieldID)
	{
		return doctor::patientLine.size();
	}
	else
	{
		return numeric_limits<int>::max();
	}
}

void assigndoc(patient p, int fieldID)
{
	int least_waiting = numeric_limits<int>::max(); // set to max initially
	docotr myDoctor;
	
 	for (int i=0; i<= AllDoctors.size(), i++) // iterating over all doctors to find the docotr with matching fieldID and minimun waiting
	{
	 	int curr_waiting = AllDoctors[i].areUmyDoc(fieldID);
		if (curr_waiting < least_waiting) 
		{	least_waiting = curr_waiting;
			myDocotor = AllDoctors[i]; 
		}
	 }
	
	myDoctor.addToLine (p);

}
