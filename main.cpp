/*
 * Problem Statement :-
 * Consider telephone book database of N clients.
 * Make use of a hash table implementation to
 * quickly look up client‘s telephone number.
 */

/*
 * Created by Devashish Katoriya on 11-03-2017
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10

//Class Definitions
class Entry                                                          //Book Class
{
public :
    char name[MAX];
    long telephone_no;
};

class HashTable                                                     //Hash Table Class
{
    Entry ht[MAX];
    void insert(Entry);
    void insertQ(Entry);
    inline int HashFunc(char []);
public :
    HashTable()
    {
        for(int i=0;i<MAX;i++)
        {
            strcpy(ht[i].name,"");
            ht[i].telephone_no = 0;
        }
    }
    bool isFull()
    {
        for(int i=0;i<MAX;i++)
        {
            if(ht[i].telephone_no==0)
            {
                return false;
            }
        }
        return true;
    }
    void clr()
    {
        for(int i=0;i<MAX;i++)
        {
            strcpy(ht[i].name,"");
            ht[i].telephone_no = 0;
        }
    }
    void construct();
    void display();
    void search();
};

void HashTable::construct()                                           //Function for Insertion
{
    if(isFull())
    {
        cout<<"\nSorry, the Telephone Directory is Full.";
        return;
    }
    
    int ch = 0;
    cout<<"\n\n 1 for Linear Hashing.";
    cout<<"\n 2 for Quadratic Hashing.";
    cout<<"\nEnter which Hashing Technique to use ? ";
    cin>>ch;
    if(ch==1)
    {
        Entry B;
        cout<<"\nEnter Record Details :- ";
        cout<<"\nEnter Name \t: ";
        cin>>B.name;
        cout<<"Enter Ph.No.\t: ";
        cin>>B.telephone_no;
        insert(B);
    }
    else if(ch==2)
    {
        Entry B;
        cout<<"\nEnter Record Details :- ";
        cout<<"\nEnter Name \t: ";
        cin>>B.name;
        cout<<"Enter Ph.No.\t: ";
        cin>>B.telephone_no;
        insertQ(B);
    }
    else
        cout<<"\nInvalid Option!";
}

void HashTable::insert(Entry B)                                         //Insertion using Linear Probing
{
    int pos;
    pos = HashFunc(B.name);
    if(ht[pos].telephone_no==0)
    {
        ht[pos] = B;
    }
    else
    {
        int i=pos;
        do
        {
            if(ht[i].telephone_no==0)
            {
                ht[i] = B;
                break;
            }
            i=(i+1)%MAX;
        }while(i!=pos);
    }
}

void HashTable::insertQ(Entry B)                                         //Insertion using Quadratic Probing
{
    int pos;
    pos = HashFunc(B.name);
    if(ht[pos].telephone_no==0)
    {
        ht[pos] = B;
    }
    else
    {
        for(int i=1; i<(MAX-1)/2; i++)
        {
            if(ht[(pos+(i*i))%MAX].telephone_no==0)
            {
                ht[(pos+(i*i))%MAX] = B;
                break;
            }
        }
    }
}

inline int HashTable::HashFunc(char key[MAX])                                 //Hash Function
{
    int i,total = 0;
    for(i=0;key[i]!='\0';i++)
        total += key[i];
    return total % MAX;
}

void HashTable::display()                                               //Display
{
    cout<<"\n\t\tTelephone Directory";
    cout<<"\n---------------------------------------------";
    cout<<"\nPos.\tName\t\tPh.No.";
    cout<<"\n---------------------------------------------";
    for(int i=0;i<MAX;i++)
    {
        cout<<"\n"<<i<<"\t"<<ht[i].name<<"\t\t"<<ht[i].telephone_no;
    }
    cout<<"\n---------------------------------------------";
    cout<<"\nMAX is "<<MAX;
}

void HashTable::search()                                                //Search
{
    char name[MAX];
    int pos;
    cout<<"\nEnter Name to search : ";
    cin>>name;
    pos = HashFunc(name);
    if(strcmp(ht[pos].name,name)==0)
    {
        cout<<"\nName\t: "<<ht[pos].name;
        cout<<"\nPh.No.\t: "<<ht[pos].telephone_no;
        return;
    }
    else
    {
        int i=pos;
        do
        {
            if(strcmp(ht[i].name,name)==0)
            {
                cout << "\nName\t: " << ht[i].name;
                cout << "\nPh.No.\t: " << ht[i].telephone_no;
                return;
            }
            i=(i+1)%MAX;
        }while(i!=pos);
        cout<<"\nRecord NOT found!";
    }
}

//main()
int main()
{
    HashTable obj;
    char choice;
    int ch;
    cout<<"\nProgram to implement Telephone Directory using Hash Table.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 to Insert new Record";
        cout<<"\n 2 to Display Telephone Directory";
        cout<<"\n 3 to Search a name";
        cout<<"\n 4 for IsFull";
        cout<<"\n -1 to Clear whole Directory";
        cout<<"\n  0 to Quit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch) {
            case 1 :
                obj.construct();
                break;
            case 2 :
                obj.display();
                break;
            case 3 :
                obj.search();
                break;
            case 4 :
                if(obj.isFull())
                    cout<<"\nYes, the Telephone Directory is Completely Full.";
                else
                    cout<<"\nNo, the Telephone Directory is Not full.";
                break;
            case -1 : cout<<"\nAre you sure you want to clear directory (y/n) ? ";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    obj.clr();
                    cout<<"\nTelephone Directory Cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
            case 0 : break;
            default : cout<<"\nInvalid Option!";
        }
        
        /*
        if(ch!=0)
        {
            cout<<"\n\n\n\n\n\n\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        */
    }while(ch!=0);
    
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}

/* OUTPUT

Program to implement Telephone Directory using Hash Table.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Record
 2 to Display Telephone Directory
 3 to Search a name
 4 for IsFull
 -1 to Clear whole Directory
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


 1 for Linear Hashing.
 2 for Quadratic Hashing.
Enter which Hashing Technique to use ? 1

Enter Record Details :-
Enter Name      :Deva
Enter Ph.No.    :123456
 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Record
 2 to Display Telephone Directory
 3 to Search a name
 4 for IsFull
 -1 to Clear whole Directory
  0 to Quit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                Telephone Directory
---------------------------------------------
Pos.    Name            Ph.No.
---------------------------------------------
0                       0
1                       0
2                       0
3                       0
4       Deva            123456
5                       0
6                       0
7                       0
8                       0
9                       0
---------------------------------------------
MAX is 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Record
 2 to Display Telephone Directory
 3 to Search a name
 4 for IsFull
 -1 to Clear whole Directory
  0 to Quit
Enter your choice : 3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Name to search : Deva

Name    : Deva
Ph.No.  : 123456

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Record
 2 to Display Telephone Directory
 3 to Search a name
 4 for IsFull
 -1 to Clear whole Directory
  0 to Quit
Enter your choice :3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Name to search : deva

Record NOT found!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Record
 2 to Display Telephone Directory
 3 to Search a name
 4 for IsFull
 -1 to Clear whole Directory
  0 to Quit
Enter your choice :0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Thank you for using this program :)

*/