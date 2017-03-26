/*
This file stores the accessor and mutator functions for the classes declared
in the header file "hospital.h"
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay                                                        |
 -------------------------------------------------------------------
*/

#include "hospital.h"

void patient::getName(string &fname, string &lname) {
	fname = patient::fname;
	lname = patient::lname;
}

void patient::getID(string &id) {
	id = patient::ID;
}

void patient::setName(string fname, string lname) {
	patient::fname = fname;
	patient::lname = lname;
}