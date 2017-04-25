#include "2Dhashmap.h"

void generate_line(doctor doc);
string get_color(int len);
void initialisePatients();

int main() {
	initialiseDoctors();
	initialisePatients();
	int num_docs = AllDoctors.size();
	system("clear");
	
	cout << cyan << "Welcome to the Hospital Management System!\n\n\n" << reset;

	for (int i = 0; i < num_docs; i++) {
		string name;
		AllDoctors[i].getName(name);
		cout << blue << name << reset << ":\t\t";
		generate_line(AllDoctors[i]);
	}
	cout << "\n\n\n\n\n\n";
}

void generate_line(doctor doc) {
	string color = get_color(doc.get_queue_length());
	int max_length = 7;
	cout <<"[ " << color;
	for (int i = 0; i < max_length; i++) {
		if (i < doc.get_queue_length())	cout << " + ";
		else cout << "   ";
	}
	cout << reset << " ]" << endl;
}

string get_color(int len) {
	if (len < 3) return green;
	else if (len < 5) return blue;
	else return red;
}

void initialisePatients() {
	patient P1;
	P1.setName("Dhruv", "Shah");
	P1.setID("42");
	P1.setSymptoms("Alzheimer");

	patient P2;
	P2.setName("Pranav", "Kulkarni");
	P2.setID("11");
	P2.setSymptoms("Cough");

	patient P3;
	P3.setName("Shashwat", "Shukla");
	P3.setID("69");
	P3.setSymptoms("Fracture");

	patient P4;
	P4.setName("Parth", "Jatakia");
	P4.setID("007");
	P4.setSymptoms("HeartPain");

	assignDoc(&P1);
	assignDoc(&P1);
	assignDoc(&P1);


	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);
	assignDoc(&P2);

	assignDoc(&P3);

	assignDoc(&P4);
	assignDoc(&P4);

}