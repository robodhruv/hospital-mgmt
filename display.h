#include "tries.h"

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
void insert_DB(patient * pat);
void search_by_ID();
void search_by_name();
void display_details(patient * pat);
string get_color_log(string log);

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
		string color = get_color_log(output_logs.front());
		cout << color << output_logs.front() << reset;
		output_logs.pop();
	}

	cout << "\n\n\n\n\n\n";
}

string get_color_log(string log){
	size_t found = log.find("discharged");
	if (found != string::npos) return green;
	else {
		found = log.find("examined");
		if (found != string::npos) return cyan;
		else {
			found = log.find("Tablets");
			if (found != string::npos) return cyan;
			else {
				found = log.find("Emergency");
				if (found != string::npos) return red;
			}
		}
	}
	return yellow;
}

void generate_actions() {
	generate_display();
	cout << bold << "1. " << reset << " Add a patient." << endl;
	cout << bold << "2. " << reset << " Search for a patient." << endl;
	cout << bold << "3. " << reset << " Edit patient details." << endl;
	cout << bold << "4. " << reset << " Examine a queue." << endl;
	cout << reset << bold << "5. " << red << " Emergency!" << reset << endl;
	cout << "\n\n";
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
