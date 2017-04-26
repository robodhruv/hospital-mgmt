#include "display.h"

HashMap_2D hospiDB;
trie hospiDB_tries;

int main() {
	initialiseDoctors();
	initialisePatients();
	generate_actions();
	begin_operation();
}

void begin_operation() {
	char action = -1;

	while (action != 0) {
		generate_actions();
loop:
		cout << "Choose an action to perform. ";
		action = getchar();
		switch (action) {
		case '1':
			add_patient();
			break;
		case '2':
			search_patient();
			break;
		// case 3:
		// 	edit_patient();
		// 	break;
		// case 4:
		// 	examine_queue();
		// 	break;
		// case 5:
		// 	emergency();
		// 	break;
		case '0':
			break;
		default:
			cout << action;
			cout << "Invalid input \n";
			goto loop;
		}
	}
}

void search_patient() {
	cout << "Search by:" << endl;
	cout << bold << "1. " << reset << " ID" << endl;
	cout << bold << "2. " << reset << " Name" << endl;
	cout << bold << "3. " << reset << " Disease" << endl;

loop:
	getchar();
	char action = getchar();
	switch (action) {
	case '1':
		search_by_ID();
		break;
	case '2':
		search_by_name();
		break;
	// case '3':
	// 	search_by_disease();
	// 	break;
	default:
		cout << "Invalid Input!" << endl;
		goto loop;
	}
}

void search_by_ID() {
	generate_display();
	int ID;
ID_enter:
	cout << "Enter Patient ID: ";
	cin >> ID;
	cout << DB_compl.size();
	if (ID >= DB_compl.size()) {
		cout << "Invalid ID!";
		goto ID_enter;
	} else {
		// patient * pat;
		// pat = (DB_compl[ID]);
		display_details(DB_compl[ID]);
	}

	getchar();
}

void search_by_name() { //Complete it!
	generate_display();
	int choice;
	string fname, lname;
	vector<string> IDs;
	vector<patient *> patients;
	cout << "Search by:" << endl;
	cout << bold << "1. " << reset << " Full Name" << endl;
	cout << bold << "2. " << reset << " First name" << endl;
	cout << bold << "3. " << reset << " Last Name" << endl;
	cout << bold << "4. " << reset << " Substring" << endl;
	cin >> choice;
	switch (choice) {
	case 1: //Complete it!
		cout << "Enter first name of patient: " << endl;
		cin >> fname;
		cout << "Enter last name of patient: " << endl;
		cin >> lname;
		hospiDB.search_patient(fname, lname, IDs, patients);
		for (int i = 0; i < patients.size(); i++) {
			string fname1, lname1, id;
			cout << bold << "ID: " << reset << patients[i] -> ID << endl;
			cout << bold << "Name: " << reset << patients[i] -> fname << " " << patients[i] -> lname << endl;
		}
		getchar();
		getchar();
		break;
	case 2:
		break;
	}

}

void display_details(patient * pat) {
	string fname, lname;
	pat -> getName(fname, lname);
	generate_display();
	cout << bold << "Name: " << reset << fname << " " << lname;
	getchar();
}

void insert_DB(patient * pat) {
	hospiDB.insert_patient(pat);
	hospiDB_tries.insertPatient(pat);
	DB_compl.push_back(pat);
}

void add_patient() {
	generate_display();
	string fname, lname, symptoms;
	cout << "Enter Patient's First Name: ";
	cin >> fname;
	generate_display();
	cout << "Enter Patient's Last Name: ";
	cin >> lname;
	generate_display();
	patient *P = new patient;
	P->setName(fname, lname);
	cout << "Enter Patient's Symptoms: ";
	cin >> symptoms;
	P->setSymptoms(symptoms);

	generate_display();

	assignDoc(P);
	insert_DB(P);
	getchar();
}

void initialisePatients() {
	patient *P1 = new patient;
	P1->setName("Dhruv", "Shah");
	P1->setID("0");
	P1->setSymptoms("Alzheimer");
	P1->setSymptoms("Fever");

	patient *P2 = new patient;
	P2->setName("Pranav", "Kulkarni");
	P2->setID("1");
	P2->setSymptoms("Cough");
	P2->setSymptoms("Fever");

	patient *P3 = new patient;
	P3->setName("Shashwat", "Shukla");
	P3->setID("2");
	P3->setSymptoms("Fracture");
	P3->setSymptoms("Cough");

	patient *P4 = new patient;
	P4->setName("Parth", "Jatakia");
	P4->setID("3");
	P4->setSymptoms("Fever");

	insert_DB(P1);
	insert_DB(P2);
	insert_DB(P3);
	insert_DB(P4);

	assignDoc(P1);
	generate_display();
	getchar();
	assignDoc(P2);
	generate_display();
	getchar();
	assignDoc(P3);
	generate_display();
	getchar();
	assignDoc(P4);
	getchar();
	generate_display();

}
