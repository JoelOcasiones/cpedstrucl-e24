#include<iostream>
#include<iomanip>
#include<windows.h>
#include <conio.h>
using namespace std;

class LinkedList{
    struct Node {
        int x;
        Node *next;
    };

public:
    LinkedList(){
        head = NULL; // set head to NULL
    }

    void addValue(int val){
        Node *n = new Node();   
        n->x = val;             
        n->next = head;         
                               
        head = n;              
    }

    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
    }

private:
    Node *head; 
};

void mainMenu();

int main(){
	LinkedList list;
	int enteredChoice, num, value;
	
	while(enteredChoice!=4){
		mainMenu();
		cin>>enteredChoice;
		switch (enteredChoice){
			
			case 1:
				cout<<"Enter number: "<<endl;
				cin>>num;
				list.addValue(num);
				cout<<endl<<"Inserted value"<<endl;
				break;
			
			case 2:
				cout<<"Pop value is: "<<list.popValue()<<endl<<endl;
				break;
			
			case 3:
				exit(1);
				break;	
				
			case 4:
				if (value == 0)
					if
				
			default:
				cout<<"Invalid input!";
				getch();
					
		}
	}
	return 0;
}	

void mainMenu(){
	cout<<"[1] Insert into linked list"<<endl;
	cout<<"[2] Pop"<<endl;
	cout<<"[3] EXIT"<<endl;
	cout<<"[4] Display contents of the linked list"<<endl;
	cout<<"Your choice: ";
	
}

