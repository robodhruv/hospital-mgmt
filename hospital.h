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
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <limits>
#include "time.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <locale>

#define TABLE_SIZE 100

using namespace std;

class patient;
class doctor;
class diagnosis;
class patientrecord;


//Each patient has relevant attributes
class patient {
    string fname, lname, ID; //Identity of the patient
    vector<diagnosis> prescription; //Diagnosed disease and corresponding treatement for the patient
public:
    vector<int> symptoms; //Symptoms displayed by the patient. Change to stack if needed
    patient();
    void getName(string &fname, string &lname);
    void getID(string &id);
    void setName(string fname, string lname);
    void setSymptoms(string symptoms);
    void addPrescription(diagnosis prescript);
    void setID(string id);
    //Add accessor and mutator function
};

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

//At the reception, the patients are assigned to a doctor based on their symptoms.
//As of now, they are assigned to one doctor, despite having multiple symptoms. This doctor then
//assigns the patient to the next doctor based on his/her other symptoms.
//Each doctor is identified by his name, ID and specialisation ID.


// Cough(0), Fever(1), Diarrhea(2) -> Physician A, Physician B
// Fracture(3), MuscleInjury (4) -> Orthopedic
// HeartPain (5) -> Cardiologist
// Alzheimer (6) -> Neurologist

vector <doctor> AllDoctors; // a vector containing all the doctors in the hospital.
queue <string> output_logs;
//Since the number of doctors is very less, hashmap for doctors is not required.
//Each doctor is identified by his name, id(remove if not needed) and specialisation
class doctor {
    string name;
    string ID;
    int fieldID; // fieldID is an int given to each field of specialization eg. 1 for general physician, 2 for Orthopaedic...
    queue<patient*> patientLine;// queue of the patient waiting to be diagnosed under the doctor.
    //..$%$%$ I am doubtful if this is how a queue of pointers to patient is implemeneted please check.$%$%$
public:
    //Add accessor and mutator functions

    void setName(string name);
    void getName(string &name);
    void setID(string id);
    void getID(string &id);
    void setFieldID(int id);
    void getFieldID(int &id);
    void addToLine(patient * p); //adds patient p to the queue of the doctor.
    void diagnose(patient *p); //Diagnose patient first in the queue and add diagnosis in patient's prescription vector.
    int areUmyDoc(patient *p);
    vector<int> whatICanCure;
    void setWhatICanCure ();
    int get_queue_length();
    //Add accessor and mutator functions
};



//Doctors diagnose the patient to identify the disease and the corresponding treatment
class diagnosis {
public:
    string disease, treatment;
};


//The heart of the database. Each patient has one entry in the database.
class patientrecord {
    string name, id;
    vector<diagnosis> record; //Contains the entire treatment history of the patient
public:
    //Add accessor and mutator functions
};

//Followed by declarations for all the search related databases

const string red("\033[0;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string blue("\033[1;34m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string reset("\033[0m");
const string bold("\033[1m");

long int clk = 5;