#include "2Dhashmap.h"

int main() {
	patient person1;
	person1.setName("parth", "jatakia");
	person1.setID("1");
	patient person2;
	person2.setName("parth", "jataki");
	person2.setID("2");

	HashMap_2D hospiDB;

	hospiDB.insert_patient(&person1);
	hospiDB.insert_patient(&person2);

	vector<string> IDs;
	vector<patient *> patients;
	hospiDB.search_patient_fname ("parth", IDs, patients);

	cout << IDs.size();
}