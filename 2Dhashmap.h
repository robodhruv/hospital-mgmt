/*
This file has the implementation of the 2D Hash Map, for storing and
querying patient data from a database efficiently.
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay                                                        |
 -------------------------------------------------------------------
*/

#include "hospi.h"

class HashNode {
// A node in the 2D hash table. Note that the input does not
// require an extra key as the name is a part of the value.
public:
    HashNode (patient * pat) {
            person = pat;
            next = NULL;
    }
    void getName(string &fname, string &lname) {
        person -> getName(fname, lname);
    }
    patient * getPatient() {
        return person;
    }
    void getID(string &ID) {
        person -> getID(ID);
    }

    void setName(string fname, string lname) {
        person -> setName(fname, lname); 
    }
    void setPatient(patient * pat) {
        person = pat;
    }
    HashNode * getNext() {
        return HashNode::next;
    }
    void setNext (HashNode * next) {
        next = next;
    }

private:
	patient * person;
	HashNode * next;
};

struct HashingFn {
	// This is the hashing function. Can improve upon this.
	int operator() (string name) {
		int sum = accumulate(name.begin(), name.end(), 0);
		return sum % TABLE_SIZE;
	}
};

class HashMap_2D {
public:
	HashMap_2D() {
		vector<vector<HashNode *> > table(TABLE_SIZE, vector<HashNode *>
		                                       (TABLE_SIZE, NULL));
        hash_table = table;
	}
	~HashMap_2D() {
		// Do we need a destructor?
		// Anyways, since we have just the pointers, and we don't need
		// patients to get deleted this arrangement works!
	}

	void insert_patient (patient * pat) {

        patient person = *pat;
		string fname, lname;
		person.getName(fname, lname);
		int index_f = hash_funct(fname);
		int index_l = hash_funct(lname);

		HashNode * entry = hash_table[index_f][index_l];
		HashNode * prev = NULL;

		while (entry != NULL) {
			prev = entry;
			entry = entry -> getNext();
		} // Getting to the terminal node, considering chaining

		entry = new HashNode(pat); // Reached end, entry was NULL.
		if (prev == NULL) {
			// First Element of the bucket
			hash_table[index_f][index_l] = entry;
		} else {
			prev -> setNext(entry);
		}

	}

	void search_patient_fname (string fname, vector<string> &IDs, vector<patient *> &patients) {
		int index_f = hash_funct(fname);

		for (int i = 0; i < TABLE_SIZE; i++) {
			HashNode * entry = hash_table[index_f][i];
			while (entry != NULL) {
				string Fname, Lname, ID;
				hash_table[index_f][i] -> getName(Fname, Lname);
				hash_table[index_f][i] -> getID(ID);
				patients.push_back(hash_table[index_f][i] -> getPatient());
				// if (Fname == fname) cout << Fname << " " << Lname << " - " << ID;
				IDs.push_back(ID);
				entry = entry -> getNext();
			}
		}
	}

	void search_patient_lname (string lname, vector<string> &IDs, vector<patient *> &patients) {
		int index_l = hash_funct(lname);

		for (int i = 0; i < TABLE_SIZE; i++) {
			HashNode * entry = hash_table[i][index_l];
			while (entry != NULL) {
				string Fname, Lname, ID;
				hash_table[i][index_l] -> getName(Fname, Lname);
				hash_table[i][index_l] -> getID(ID);
				patients.push_back(hash_table[i][index_l] -> getPatient());
				// if (Lname == lname) cout << Fname << " " << Lname << " - " << ID;
				IDs.push_back(ID);
				entry = entry -> getNext();
			}
		}
	}

	void search_patient (string fname, string lname,  vector<string> &IDs, vector<patient *> &patients) {
		int index_f = hash_funct(fname);
		int index_l = hash_funct(lname);

		HashNode * entry = hash_table[index_f][index_l];

        while (entry != NULL) {
			string Fname, Lname, ID;
			hash_table[index_f][index_l] -> getName(Fname, Lname);
			hash_table[index_f][index_l] -> getID(ID);
			patients.push_back(hash_table[index_f][index_l] -> getPatient());
			// if (Fname == fname) cout << Fname << " " << Lname << " - " << ID;
			IDs.push_back(ID);
			entry = entry -> getNext();
		}
	}


private:
	vector<vector<HashNode *> > hash_table;
	HashingFn hash_funct;
};