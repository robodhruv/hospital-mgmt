#include "display.h"

HashMap_2D hospiDB;
trie hospiDB_tries;

int main() {
	initialiseDoctors();
	initialisePatients();
	generate_actions();
	//begin_operation();
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
		case 2:
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
		case 0:
			break;
		default:
			cout << action;
			cout << "Invalid input \n";
			goto loop;
		}
	}
}

void search_patient(){
	return;
}

void add_patient() {
	generate_actions();
	string fname, lname, symptoms;
	cout << "Enter Patient's First Name: ";
	cin >> fname;
	generate_actions();
	cout << "Enter Patient's Last Name: ";
	cin >> lname;
	generate_actions();
	patient P;
	P.setName(fname, lname);
	cout << "Enter Patient's Symptoms: ";
	cin >> symptoms;
	P.setSymptoms(symptoms);

<<<<<<< HEAD
	generate_actions();

	assignDoc(&P);
	hospiDB.insert_patient(&P);
	hospiDB_tries.insertPatient(&P);
	getchar();
=======
	//hospiDB.insert_patient(&P);
>>>>>>> 101773509634b7ec6a2194096adfa4c1f15dc1a6
}

void initialisePatients() {
	patient P1;
	P1.setName("Dhruv", "Shah");
	P1.setID("1");
	P1.setSymptoms("Alzheimer");
	P1.setSymptoms("Fever");

	patient P2;
	P2.setName("Pranav", "Kulkarni");
	P2.setID("2");
	P2.setSymptoms("Cough");
	P2.setSymptoms("Fever");

	patient P3;
	P3.setName("Shashwat", "Shukla");
	P3.setID("3");
	P3.setSymptoms("Fracture");
	P2.setSymptoms("Cough");

	patient P4;
	P4.setName("Parth", "Jatakia");
	P4.setID("4");
	P4.setSymptoms("Fever");

	hospiDB_tries.insertPatient(&P1);
	hospiDB.insert_patient(&P1);
	hospiDB_tries.insertPatient(&P2);
	hospiDB.insert_patient(&P2);	
	hospiDB_tries.insertPatient(&P3);
	hospiDB.insert_patient(&P3);	
	hospiDB_tries.insertPatient(&P4);
	hospiDB.insert_patient(&P4);

	assignDoc(&P1);
	generate_display();
	getchar();
	assignDoc(&P2);
	generate_display();
	getchar();
	assignDoc(&P3);
	generate_display();
	getchar();
	assignDoc(&P4);
	getchar();
	AllDoctors[0].diagnose();
	P1.getPrescriptionLenght();
	P2.getPrescriptionLenght();
	P3.getPrescriptionLenght();
	P4.getPrescriptionLenght();
	getchar();
	AllDoctors[1].diagnose();
	P1.getPrescriptionLenght();
	P2.getPrescriptionLenght();
	P3.getPrescriptionLenght();
	P4.getPrescriptionLenght();
	getchar();
	AllDoctors[2].diagnose();
	P1.getPrescriptionLenght();
	P2.getPrescriptionLenght();
	P3.getPrescriptionLenght();
	P4.getPrescriptionLenght();
	getchar();
	AllDoctors[3].diagnose();
	P1.getPrescriptionLenght();
	P2.getPrescriptionLenght();
	P3.getPrescriptionLenght();
	P4.getPrescriptionLenght();
	getchar();
	AllDoctors[4].diagnose();
	P1.getPrescriptionLenght();
	P2.getPrescriptionLenght();
	P3.getPrescriptionLenght();
	P4.getPrescriptionLenght();
	getchar();

}
