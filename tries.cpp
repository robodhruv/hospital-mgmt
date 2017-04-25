/*
Implementation of IITB Hospital Management System in C++.
This file contains implementation Of Tries for quick searching of 
patients whose full names are not known. 
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay                                                        |
 -------------------------------------------------------------------
*/
//#include "hospital.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <limits>

//The name inputted should contain no spaces and if there are they will be removed by the code

#define letterSet 26
#define origin 'a'
#define MAX 25

using namespace std;

class patient {
    string fname, lname, ID; //Identity of the patient
public:
    void getName(string &fname, string &lname);
    void getID(string &id);
    void setName(string fname, string lname);
    void setID(string id);
    //Add accessor and mutator functions
};

void patient::getName(string &fname, string &lname)
{
    fname = patient::fname;
    lname = patient::lname;
}

void patient::getID(string &id)
{
    id = patient::ID;
}

void patient::setName(string fname, string lname)
{
    patient::fname = fname;
    patient::lname = lname;
}

void patient::setID(string id)
{
    patient::ID = id;
}

struct node
{
    struct node * parent;
    struct node * children[letterSet];
    vector<patient*> list;
};

class trie 
{
        node root;

    public:
        void insertPatient(patient * newpatient)
        {
            node * treeNode = &(trie :: root);
            string fname, lname, name; 
            newpatient->getName(fname, lname);
            name = fname+lname;
            cout<<name<<endl;
            int i = 0 ;
            while (name[i]!='\0')
            {     
                if (treeNode->children[name[i] - origin] == NULL) {
                    treeNode->children[name[i] - origin] = (struct node *) malloc(sizeof(struct node));
                    treeNode->children[name[i]-origin]->parent = treeNode;  // Assigning parent
            }
            cout<<i<<endl;
            treeNode = treeNode->children[name[i]-origin];
            i++;
            }

            treeNode->list.push_back(newpatient);  
            cout<<"insertion successfull"<<endl;
        }

        vector<patient*> searchPatient(string name)
        {
            vector<patient*> result;
            struct node * treeNode = &(trie :: root);
            int i = 0;
            bool found = 1;
            while (name[i] != '\0') 
            {
                if (treeNode->children[name[i] - origin] != NULL) 
                {
                    treeNode = treeNode->children[name[i] - origin];
                    i++;
                } 
                else 
                {
                    found = 0;
                    break;
                }
            }

            if (found)
            {
                queue<node*> BFSnodes;
                BFSnodes.push(treeNode);
                while(!BFSnodes.empty())
                {
                    struct node* treeNode = BFSnodes.front();
                    BFSnodes.pop();
                    result.insert(std::end(result),std::begin(treeNode->list),std::end(treeNode->list));
                    for(int j = 0; j< 26;j++)
                        {
                        if(treeNode->children[i]!= NULL)
                        {
                            BFSnodes.push(treeNode->children[i]);
                        }
                    }
                }
                return result;
            } 
            else {
                return result;
            }
        }

        void removePatient(patient *Rpatient)
        {
            string fname, lname, name; 
            Rpatient->getName(fname, lname);
            name = fname+lname;

            struct node * treeNode = &(trie :: root);
            int i = 0;
            bool found = 1;
            while (name[i] != '\0') 
            {
                if (treeNode->children[name[i] - origin] != NULL) {
                    treeNode = treeNode->children[name[i] - origin];
                    i++;
                } 
                else 
                {
                    found = 0;
                    break;
                }
            }

            if (found)
            {
                for(vector<patient*>::iterator itr = treeNode->list.begin(); itr != treeNode->list.end(); itr++)
                {
                    string ID1, ID2;
                    Rpatient->getID(ID1);
                    patient *temp = *itr;
                    temp->getID(ID2);
                    if(ID1 == ID2)
                    {
                        treeNode->list.erase(itr);
                    }
                }
            }
        }

};

int main()
{
    patient person1;
    person1.setName("parth","jatakia");
    person1.setID("1");
    cout<<"1"<<endl;
    trie mytrie;
    cout<<"2"<<endl;
    mytrie.insertPatient(&person1);
    cout<<"2"<<endl;
    vector<patient*> returnSearch(mytrie.searchPatient("parth"));
    cout<<"3"<<endl;
    //cout<<"returnSearch Size = "<<returnSearch.size()<<endl;
    for (int i = 0; i < returnSearch.size(); ++i)
    {   
        cout<<i<<endl;
        string lname,fname;
        returnSearch[i]->getName(fname,lname);
        cout<<fname<<" "<<lname<<endl;
        
    }
    return 0;
}