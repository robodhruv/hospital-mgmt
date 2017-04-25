#include "2Dhashmap.h"

void generate_line(doctor doc);
string get_color(int len);

int main() {


	num_docs = AllDoctors.size();
	for (int i = 0; i < num_docs; i++) {
		generate_line(AllDoctors[i]);
	}
}

void generate_line(doctor doc) {
	string color = get_color(doc.get_queue_length());

	cout <<"[ " << color;
	for (int i = 0; i < doc.get_queue_length(); i++) {
		cout << " | ";
	}
	cout << reset << " ]";
}

string get_color(int len) {
	if (len < 3) return green;
	else if (len < 5) return blue;
	else return red;
}