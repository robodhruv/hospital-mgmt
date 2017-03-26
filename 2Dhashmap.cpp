#include "hospital.h"

class HashNode {
// A node in the 2D hash table. Note that the input does not
// require an extra key as the name is a part of the value.
public:
    HashNode (patient *person):
    person(person), next(NULL) {
    }
    void getName(string &fname, string &lname) {
        person -> getName(fname, lname);
    }
    patient getPatient() {
        return *person;
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
        vector<vector<HashNode *>> hash_table(TABLE_SIZE, vector<HashNode *>
            (TABLE_SIZE, NULL));
    }
    ~HashMap_2D() {
        // Do we need a destructor?
        // Anyways, since we have just the pointers, and we don't need
        // patients to get deleted this arrangement works!
    }

    void insert_patient (patient * pat) {
        string fname, lname;
        pat -> getName(fname, lname);

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
private:
    vector<vector<HashNode *>> hash_table ;
    HashingFn hash_funct;
};

int main() {
    return 0;
}