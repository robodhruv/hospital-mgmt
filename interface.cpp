#include "display.h"

int main() {
	initialiseDoctors();
	initialisePatients();
	generate_actions();
	begin_operation();
}

void begin_operation() {
	int action = -1;

	while (action != 0) {
		generate_actions();
loop:
		action = getchar();
		switch (action) {
		case 1:
			add_patient();
			break;
		case 2:
			search_patient();
			break;
		case 3:
			edit_patient();
			break;
		case 4:
			examine_queue();
			break;
		case 5:
			emergency();
			break;
		case 0:
			break;
		default:
			cout << "Invalid input \n";
			goto loop;
		}
	}
}

void add_patient() {
	string fname, lname, symptoms;
	cout << "Enter Patient's First Name: ";
	cin >> fname;
	generate_actions();
	cout << "Enter Patient's Last Name: ";
	cin >> lname;
	generate_actions();
	cout << "Enter Patient's Symptoms: ";
	cin >> symptoms;
	generate_actions();

	patient P;
	P.setName(fname, lname);
	P.setSymptoms(symptoms);

	hospiDB.insert_patient(&P);
}
void initialisePatients() {
	patient P1;
	P1.setName("Dhruv", "Shah");
	P1.setID("1");
	P1.setSymptoms("Alzheimer");

	patient P2;
	P2.setName("Pranav", "Kulkarni");
	P2.setID("2");
	P2.setSymptoms("Cough");

	patient P3;
	P3.setName("Shashwat", "Shukla");
	P3.setID("3");
	P3.setSymptoms("Fracture");

	patient P4;
	P4.setName("Parth", "Jatakia");
	P4.setID("4");
	P4.setSymptoms("Fever");


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
}
