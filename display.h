#include "2Dhashmap.h"

void generate_line(doctor doc);
string get_color(int len);
void initialisePatients();
void generate_actions();
void generate_display();
void begin_operation();
void add_patient();
void search_patient();
void edit_patient();
void examine_queue();
void emergency();

void generate_display() {
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

	for (int i = 0; i < output_logs.size(); i++) {
		cout << yellow << output_logs.front() << reset;
		output_logs.pop();
	}

	cout << "\n\n\n\n\n\n";

}

void generate_actions() {
	generate_display();
	cout << bold << "1. " << reset << " Add a new patient." << endl;
	cout << bold << "2. " << reset << " Search for a patient." << endl;
	cout << bold << "3. " << reset << " Edit patient details." << endl;
	cout << bold << "4. " << reset << " Examine a queue." << endl;
	cout << reset << bold << "5. " << red << " Emergency!" << endl;
}

void generate_line(doctor doc) {
	string color = get_color(doc.get_queue_length());
	int max_length = 7;
	cout << "[ " << color;
	for (int i = 0; i < max_length; i++) {
		if (i < doc.get_queue_length())	cout << " + ";
		else cout << "   ";
	}
	cout << reset << " ]" << endl;
}

string get_color(int len) {
	if (len < 3) return green;
	else if (len < 5) return yellow;
	else return red;
}
