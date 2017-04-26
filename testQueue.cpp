#include "hospital.h"
#include "hospi.h"
#include <iostream>

using namespace std;


int main()
{
	initialiseDoctors();

	patient patient1;
	patient1.setID("1");
	patient1.setName("parth","jatakia");
	patient1.setSymptoms("Fracture");
	patient patient2;
	patient2.setID("2");
	patient2.setName("pranav","kulkarni");
	patient2.setSymptoms("Cough");
	patient2.setSymptoms("Alzheimer");
	patient patient3;
	patient3.setID("3");
	patient3.setName("dhruv","shah");
	patient3.setSymptoms("Fever");
	patient3.setSymptoms("Cough");
	patient patient4;
	patient4.setID("4");
	patient4.setName("aaa","sss");
	patient4.setSymptoms("HeartPain");
	assignDoc(&patient1);
	char a = getchar();

	assignDoc(&patient2);
	char b = getchar();

	assignDoc(&patient3);
	char c = getchar();

	assignDoc(&patient4);
	char d = getchar();
	for(int j = 0; j < AllDoctors.size();j++ )
	{
		cout<<"Doctor "<<j<<" - ";
		cout<<AllDoctors[j].get_queue_length();
		cout<<endl;
	}
	for(int i = 0; i<10;i++)
	{
		AllDoctors[i/2].diagnose();
		a = getchar();
		for(int j = 0; j < AllDoctors.size();j++ )
		{
			cout<<"Doctor "<<j<<" - ";
			cout<<AllDoctors[j].get_queue_length();
			cout<<endl;
		}
		

	}
}
