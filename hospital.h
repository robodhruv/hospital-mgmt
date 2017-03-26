/*
Implementation of IITB Hospital Management System in C++.
This file contains declarations for all classes, structs 
and stl containers used.
Function definitions will be enumerated in separate files.
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay                                                        |
 -------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

#define TABLE_SIZE 100

using namespace std;

class patient;
class doctor;
class diagnosis;
class patientrecord;

//Patients arrive and queue up at the reception.
queue<patient> Reception;

//Each patient has relevant attributes  
class patient{
    string name, ID; //Identity of the patient
    vector<string> symptoms; //Symptoms displayed by the patient. Change to stack if needed
    stack<string> doctors; //Doctors the patient must visit based on his symptoms. Keep popping docs till empty
    vector<diagnosis> prescription; //Diagnosed disease and corresponding treatement for the patient
public:
    string getName();
    string getID();
    string setName(string name);
    //Add accessor and mutator functions
};

//At the reception, the patients are assigned to a doctor based on their symptoms.
//As of now, they are assigned to one doctor, despite having multiple symptoms. This doctor then 
//assigns the patient to the next doctor based on his/her other symptoms.
doctor assigndoc(patient p);

//Each doctor is identified by his name, id(remove if not needed) and specialisation
class doctor{
    string name, id, field; //field refers to the doctor's specialisation
public:
    diagnosis diagnose(patient p); //Diagnose patient p and prescribe a treatment
    //Add accessor and mutator functions
};

//Doctors diagnose the patient to identify the disease and the corresponding treatment
class diagnosis{
    string disease, treatment;
};


//The heart of the database. Each patient has one entry in the database.
class patientrecord{
    string name, id;
    vector<diagnosis> record; //Contains the entire treatment history of the patient
public:
    //Add accessor and mutator functions
};

//Followed by declarations for all the search related databases