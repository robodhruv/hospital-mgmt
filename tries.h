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
#include "2Dhashmap.h"

//The name inputted should contain no spaces and if there are they will be removed by the code

#define letterSet 26
#define origin 'a'
#define MAX 25

struct node
{
    struct node * parent;
    struct node * children[letterSet];
    vector<patient*> entries;
};

class trie
{
    node root;

public:

    trie() {
        root.parent = NULL;
        for (int i = 0; i < letterSet; i++) {
            root.children[i] = NULL;
        }
    }
    void insertPatient(patient * newpatient)
    {
        node * treeNode = &(trie :: root);
        string fname, lname, name;
        newpatient->getName(fname, lname);
        name = fname + lname;
        cout << name << endl;
        int i = 0 ;
        while (i < name.length())
        {
            if (treeNode->children[name[i] - origin] == NULL) {
                treeNode->children[name[i] - origin] = new node;
                treeNode->children[name[i] - origin]->parent = NULL;
                for (int j = 0; j < letterSet; j++) {
                    treeNode->children[name[i] - origin]->children[j] = NULL;
                }
                treeNode->children[name[i] - origin]->parent = treeNode; // Assigning parent
            }

            treeNode = treeNode->children[name[i] - origin];
            i++;
        }

        treeNode->entries.push_back(newpatient);
        cout << "Insertion Successful" << endl;
    }

    vector<patient*> searchPatient(string name)
    {
        vector<patient*> result;
        struct node * treeNode = &root;
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
            while (!BFSnodes.empty())
            {
                struct node* Nodes = BFSnodes.front();
                BFSnodes.pop();
                for (int i = 0; i < Nodes->entries.size(); i++) {
                    result.push_back(Nodes->entries[i]);
                }
                //result.insert(end(result),begin(Nodes->entries),end(Nodes->entries));
                for (int i = 0; i < letterSet; i++)
                {
                    if (Nodes->children[i] != NULL)
                    {
                        BFSnodes.push(Nodes->children[i]);
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
        name = fname + lname;

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
            for (vector<patient*>::iterator itr = treeNode->entries.begin(); itr != treeNode->entries.end(); itr++)
            {
                string ID1, ID2;
                Rpatient->getID(ID1);
                patient *temp = *itr;
                temp->getID(ID2);
                if (ID1 == ID2)
                {
                    treeNode->entries.erase(itr);
                }
            }
        }
    }

};