#include<iostream>
#include<conio.h>
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
	
	void display(){
		Node *n;
		n = head;
		if (n == NULL){
			cout<<"There is nothing to display. Input values first.";
		}
		else{
			while(n!=NULL){
				cout<< n->x <<" ";
				n = n->next;
			}	
		}
		getch();
	}

private:
    Node *head; 
};

void mainMenu(){
	cout<<"Linked List Stacks"<<endl<<endl;
	cout<<"[1] Insert into linked list"<<endl;
	cout<<"[2] Pop"<<endl;
	cout<<"[3] EXIT"<<endl;
	cout<<"[4] Display contents of the linked list"<<endl;
	cout<<"Your choice: ";
	}

int main(){
	LinkedList list;
	int enteredChoice = 0, num, value;
	
	while(enteredChoice!=5){
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
				
			case 4:{
				list.display();
				break;
				
			default:
				cout<<"Invalid input!";
				getch();
					
			}
		}
		cout<<endl;
	}
	return 0;
}	
