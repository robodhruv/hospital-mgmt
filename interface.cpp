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

	while (action != '0') {
		generate_actions();
		clk++;
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
		case '3':
			examine_queue();
		 	getchar();
		 	break;
		case '4':
		 	getchar();
		 	break;
		case '5':
			emergency();
			break;
		case '0':
			break;
		default:
			cout << action;
			cout << "Invalid input \n";
			goto loop;
		}

		if (clk % 3 == 0) {
			for (int i = 0; i < AllDoctors.size(); i++) {
				AllDoctors[i].diagnose();
			}
		}
	}
}

void search_patient() {
	generate_display();
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
	case '3':
	    search_by_disease();
	    break;
	default:
		cout << "Invalid Input!" << endl;
		goto loop;
	}
}

void examine_queue()
{
	cout << "Enter Doctors's ID: ";
	string id;
	cin >> id;
	generate_display();

	for (int i=0; i<AllDoctors.size(); i++)
	{
		string ID;
		AllDoctors[i].getID(ID);
		if (id ==ID)
		{
			string docname;
			AllDoctors[i].getName(docname);
			int ql = AllDoctors[i].get_queue_length();
			cout<< docname <<" : "<< ql <<" patients waiting : ";
			queue<patient*> newPatientLine;

			while (! AllDoctors[i].patientLine.empty())
			{
			    patient * q = AllDoctors[i].patientLine.front();
			    newPatientLine.push(q);
			    string a,b;
			    q -> getName(a,b);
			    cout<< a<<" ";
			    AllDoctors[i].patientLine.pop();
			}
			cout<< endl;
			AllDoctors[i].patientLine = newPatientLine;
			return;
		}
	}
}

void emergency()
{
	patient *PEmer = new patient;
	PEmer->setName("Emerg", "Pat");
	PEmer->setID("-1");

	correctEntry:
	generate_display();
	cout << "Enter Patient's Symptoms: ";
	string symptoms;
	cin >> symptoms;
	int sizeOld = PEmer->symptomsSize();
	PEmer->setSymptoms(symptoms);
	int sizeNew = PEmer->symptomsSize();
	if(sizeOld==sizeNew) goto correctEntry;

	generate_display();
	Emergency (PEmer);
}

void search_by_ID() {
	generate_display();
	int ID;
ID_enter:
	cout << "Enter Patient ID: ";
	cin >> ID;
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

void search_by_name() {
	generate_display();
	int choice;
	string fname, lname, name;
	vector<string> IDs;
	vector<patient*> patients;
	cout << "Search by:" << endl;
	cout << bold << "1. " << reset << " Full Name" << endl;
	cout << bold << "2. " << reset << " First name" << endl;
	cout << bold << "3. " << reset << " Last Name" << endl;
	cout << bold << "4. " << reset << " Substring" << endl;
	cin >> choice;
	generate_display();
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
		break;
	case 2:
		cout << "Enter first name of patient: ";
		cin >> fname;
		hospiDB.search_patient_fname(fname, IDs, patients);
		for (int i = 0; i < patients.size(); i++) {
			string fname1, lname1, id;
			cout << bold << "ID: " << reset << patients[i] -> ID << endl;
			cout << bold << "Name: " << reset << patients[i] -> fname << " " << patients[i] -> lname << endl;
		}
		getchar();
		getchar();
		break;
	case 3:
		cout << "Enter last name of patient: ";
		cin >> lname;
		hospiDB.search_patient_lname(lname, IDs, patients);
		for (int i = 0; i < patients.size(); i++) {
			string fname1, lname1, id;
			cout << bold << "ID: " << reset << patients[i] -> ID << endl;
			cout << bold << "Name: " << reset << patients[i] -> fname << " " << patients[i] -> lname << endl;
		}
		getchar();
		getchar();
		break;
	case 4:
		cout << "Enter the first few letters of the name: " << endl; //It is extremely important that only the first part of the name is searched.
		cin >> name;
		patients = hospiDB_tries.searchPatient(name);
		for (int i = 0; i < patients.size(); i++) {
			string fname1, lname1, id;
			cout << bold << "ID: " << reset << patients[i] -> ID << endl;
			cout << bold << "Name: " << reset << patients[i] -> fname << " " << patients[i] -> lname << endl;
		}
		getchar();
		getchar();
		break;

	}

}

void search_by_disease() {

	int c;
	cout << "Enter disease to search with: " << endl;
	cout << "0. Cough" << endl;
	cout<< "1. Fever" << endl;
    cout<< "2. Diarrhea" << endl;
    cout<< "3. Fracture" << endl;
    cout<< "4. MuscleInjury" << endl;
    cout<< "5. HeartPain" << endl;
    cout<< "6. Alzheimer" << endl;
    cin >> c; getchar();

    generate_display();
    cout << blue << "Patients with " << toSympString(c) << reset << endl;
    for(int i=0; i<disease_list[c].size(); i++){
    	string fname, lname, id;
    	disease_list[c][i]->getName(fname, lname);
    	disease_list[c][i]->getID(id);
    	cout<< bold << "ID: " << reset << id << bold << "\t Name: " << reset << fname << " " << lname << endl;
    }
    getchar();
}


void display_details(patient * pat) {
	string fname, lname;
	pat -> getName(fname, lname);
	generate_display();
	cout << cyan << bold << "Name: " << reset << cyan << fname << " " << lname << endl;
	cout << bold << "Logs::" << reset << endl << endl;
	for (int i = 0; i < (pat -> prescription).size() ; i++) {
		cout << bold << pat->prescription[i].disease << ": " << reset << pat->prescription[i].treatment << endl;
	}
	getchar();
}

void insert_DB(patient * pat) {
	hospiDB.insert_patient(pat);
	hospiDB_tries.insertPatient(pat);
	DB_compl.push_back(pat);
}

void add_patient() {
	generate_display();
	int choice ;
	cout << bold << "1. " << reset << "New Patient" << endl;
	cout << bold << "2. " << reset << "Old Patient" << endl;
	cin >> choice;
	switch (choice) {
	case 1:// For NEW Patients
	{	string fname, lname, symptoms;
		cout << "Enter Patient's First Name: ";
		cin >> fname;
		generate_display();
		cout << "Enter Patient's Last Name: ";
		cin >> lname;
		generate_display();
		patient *P = new patient;
		P->setName(fname, lname);

		correctEntryNew:
		generate_display();
		cout << "Enter Patient's Symptoms: ";
		cin >> symptoms;
		int sizeOld = P->symptomsSize();
		P->setSymptoms(symptoms);
		int sizeNew = P->symptomsSize();
		if(sizeOld==sizeNew) goto correctEntryNew;

		generate_display();

		assignDoc(P);
		insert_DB(P);
		for(int i=0; i < P->symptoms.size(); i++){
			int j = P->symptoms[i];
			disease_list[j].push_back(P);
		}

		getchar();
		break;
	}
	case 2:// For OLD Patients
	{	int ID;
		string symptoms;
		ID_enter:
		cout << "Enter Patient's ID :" << endl;
		cin >> ID;
		if (ID >= DB_compl.size()) {
			cout << "Invalid ID!";
			goto ID_enter;
		}
		else {
			generate_display();
			if(DB_compl[ID]->symptomsSize()==0){

				correctEntryOld:
				generate_display();
				cout << "Enter Patient's Symptoms: ";
				cin >> symptoms;
				int sizeOld = DB_compl[ID]->symptomsSize();
				DB_compl[ID]->setSymptoms(symptoms);
				int sizeNew = DB_compl[ID]->symptomsSize();
				if(sizeOld==sizeNew) goto correctEntryOld;

				DB_compl[ID]->setSymptoms(symptoms);
				assignDoc(DB_compl[ID]);
				insert_DB(DB_compl[ID]);
			}
			else
			{
				output_logs.push("Patient already in the Queue");
				getchar();
			}
		}
		patient * P = DB_compl[ID];
		for(int i=0; i < P->symptoms.size(); i++){
			int j = P->symptoms[i];
			bool flag = 1;
			for(int k=0; k<disease_list[j].size(); k++){
				string id1, id2;
				P-> getID(id1);
				disease_list[j][k] -> getID(id2);
				if(id1 == id2){
					flag = 0;
					break;
				}
			}
			if(flag){
					disease_list[j].push_back(P);
				}
		}

		break;
	}
}
}


void initialisePatients() {
	patient *P1 = new patient;
	P1->setName("Dhruv", "Shah");
	P1->setSymptoms("Alzheimer");
	P1->setSymptoms("Fever");

	patient *P2 = new patient;
	P2->setName("Pranav", "Kulkarni");
	P2->setSymptoms("Cough");
	P2->setSymptoms("Fever");

	

	patient *P3 = new patient;
	P3->setName("Shashwat", "Shukla");
	P3->setSymptoms("Fracture");
	P3->setSymptoms("Cough");

	patient *P4 = new patient;
	P4->setName("Parth", "Jatakia");
	P4->setSymptoms("Fever");

	patient *P5 = new patient;
	P5->setName("Partha", "Bhattacharya");
	P5->setSymptoms("Cough");

	patient *P6 = new patient;
	P6->setName("Donald", "Trump");
	P6->setSymptoms("Alzheimer");
	P6->setSymptoms("HeartPain");

	patient *P7 = new patient;
	P7->setName("Parnali", "Dubey");
	P7->setSymptoms("Fracture");
	P7->setSymptoms("Fever");

	insert_DB(P1);
	insert_DB(P2);
	insert_DB(P3);
	insert_DB(P4);
	insert_DB(P5);
	insert_DB(P6);
	insert_DB(P7);

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
	assignDoc(P5);
	getchar();
	generate_display();	
	assignDoc(P6);
	getchar();
	generate_display();
	assignDoc(P7);
	getchar();
	generate_display();

	for(int i=0; i < P1->symptoms.size(); i++){
			int j = P1->symptoms[i];
			disease_list[j].push_back(P1);
	}

	for(int i=0; i < P2->symptoms.size(); i++){
			int j = P2->symptoms[i];
			disease_list[j].push_back(P2);
	}

	for(int i=0; i < P3->symptoms.size(); i++){
			int j = P3->symptoms[i];
			disease_list[j].push_back(P3);
	}

	for(int i=0; i < P4->symptoms.size(); i++){
			int j = P4->symptoms[i];
			disease_list[j].push_back(P4);
	}

	for(int i=0; i < P5->symptoms.size(); i++){
			int j = P4->symptoms[i];
			disease_list[j].push_back(P4);
	}

	for(int i=0; i < P6->symptoms.size(); i++){
			int j = P4->symptoms[i];
			disease_list[j].push_back(P4);
	}

	for(int i=0; i < P7->symptoms.size(); i++){
			int j = P4->symptoms[i];
			disease_list[j].push_back(P4);
	}

}
