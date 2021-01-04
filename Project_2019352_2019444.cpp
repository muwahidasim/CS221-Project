/*

M.MUWAHID ASIM  2019352
M.SAAIM QURESHI 2019444

*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;



class Contacts_Database {
private:
  
     
    struct Node
    {
        int key;
        string name, pri_contact, sec_contact, address;
        Node* next;
    };
    Node* head[10];
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

    int counter;
public:
    Contacts_Database()
    {
        for(int i=0;i<10;i++)
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
        cout << "\nEnter address: ";
        cin >> address;
        int location = hash_function(name) % 10;
        add_node_at_tail(location, name, pri_contact, sec_contact, address);

       
    }
    void display()
    {
        for (int i = 0;i < 10;i++)
        {
            Node* temp = head[i];
            while (temp != NULL)
            {
                cout << "\nKey: " << temp->key;
                cout << "\nName: " << temp->name;
                cout << "\nPrimary Contact: " << temp->pri_contact;
                cout << "\nSecondary Contact: " << temp->sec_contact;
                cout << "\nAddress: " << temp->address;
                temp = temp->next;
            }
        }
    }

};

int main()
{
    Contacts_Database contact_table;

    for (int i = 0;i < 10;i++)
    {
        contact_table.insert();
        cin.ignore();
    }
    contact_table.display();
    
    
    return 0;
}


