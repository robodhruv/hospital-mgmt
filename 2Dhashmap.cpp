#include "hospital.h"

class HashNode {

public:
	HashNode (patient *person):
	person(person), next(NULL) {
	}
	string getName() {
		return person -> getName();
	}
	patient getPatient() {
		return *person;
	}
	void setName(string name) {
		HashNode::person -> setName(name); 
	}
	void setPatient(patient * pat) {
		HashNode::person = pat;
	}
	HashNode * getNext() {
		return next;
	}
	void setNext (HashNode * next) {
		HashNode::next = next;
	}

private:
	patient * person;
	HashNode * next;
};

int main() {

}