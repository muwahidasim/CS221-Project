/*

M.MUWAHID ASIM  2019352
M.SAAIM QURESHI 2019444

*/

#include <iostream>
#include <string>
#include <math.h>

#define SIZE 10

using namespace std;



class Contacts_Database {
private:
  
     
    struct Node
    {
        int key;
        string name, pri_contact, sec_contact, address;
        Node* next;
    };
    Node* head[SIZE];
    int hash_function(string name_entered)
    {
        int hash_number = 0;
        int count = 0;
        int length = name_entered.size();
        for (int i = length; i > 0; i--)
        {

            hash_number = hash_number + (int(name_entered[count]) * pow(2, i));
            count++;

        }
        return hash_number;
    }



    void add_node_at_tail(int hash,string name, string pri_contact, string sec_contact, string address)
    {
        Node* ptrnew=new Node;
        ptrnew->name = name;
        ptrnew->pri_contact = pri_contact;
        ptrnew->sec_contact = sec_contact;
        ptrnew->address = address;
        ptrnew->key = ++counter;
        
        ptrnew->next = NULL;
        if (head[hash] == NULL)
        {
            head[hash] = ptrnew;
        }
        else
        {
            Node* temp = head[hash];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptrnew;
        }
        cout << "\n****ADDED SUCCESSFULLY****\n";
    }

    void displayNode(Node *temp)
    {
        cout << "\nKey: " << temp->key;
        cout << "\nName: " << temp->name;
        cout << "\nPrimary Contact: " << temp->pri_contact;
        cout << "\nSecondary Contact: " << temp->sec_contact;
        cout << "\nAddress: " << temp->address << endl;
    }

    int counter;
public:
    Contacts_Database()
    {
        for(int i=0;i<SIZE;i++)
            head[i] = NULL;
        counter = 0;
    }
    void insert()
    {
        
        string name, pri_contact, sec_contact, address;

        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "\nEnter Primary Contact: ";
        cin >> pri_contact;
        cout << "\nEnter Secondary Contact: ";
        cin >> sec_contact;
        cin.ignore();
        cout << "\nEnter address: ";
        getline(cin, address);
        int location = hash_function(name) % SIZE;
        add_node_at_tail(location, name, pri_contact, sec_contact, address);

    }
    void display()
    {
        for (int i = 0;i < SIZE;i++)
        {
            Node* temp = head[i];
            while (temp != NULL)
            {
                displayNode(temp);
                temp = temp->next;
            }
        }
    }

    void search()
    {
        string name;
        cout << "\nPlease kindly enter the name you want to search: ", getline(cin, name), cout << endl;

        int index = hash_function(name) % SIZE;

        if(head[index])
        {
            Node *tempNode = head[index];
            bool isFound = false;
            
            cout << "\nFound:\n\n";
            while(tempNode)
            {
                if(tempNode->name == name) // A contact found
                {
                    displayNode(tempNode);
                    isFound = true;
                }
                tempNode = tempNode->next;
            }

            if(!isFound) // Contact NOT found
                cout << "None\n"; 

        }
        else // Contact NOT found
            cout << "\nNo contact exist with this name!\n";

    }

    void deleteNode()
    {
        string name;
        int key;

        cout << "\nPlease kindly enter the name of the contact, you want to delete: ", getline(cin, name);
        cout << "\nPlease enter the key of the contact: ", cin >> key, cout << endl;

        int index = hash_function(name) % SIZE;

        if(head[index])
        {
            Node *prevNode = NULL, *currentNode = head[index];

            while(currentNode && (currentNode->key != key || currentNode->name != name))
            {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }

            if(currentNode) // Contact found
            {
                if(prevNode) // Middle or last contact in the chain
                    prevNode->next = currentNode->next;
                else // Contact in the chain
                    head[index] = currentNode->next;

                cout << "\nContact with key " << key << " and name " << name << " deleted\n";    
                delete currentNode;
            }
            else // Key and name don't match
                cout << "\nContact with this key and name not found!\n";
        }
        else // Contact doesn't exist
            cout << "\nContact with this key and name not found!\n";
    }

};

int main()
{
    Contacts_Database contact_table;

    for (int i = 0;i < 3;i++)
    {
        contact_table.insert();
        
    }
    contact_table.display();

    contact_table.search();
    contact_table.deleteNode();
    contact_table.display();

    
    
    return 0;
}


