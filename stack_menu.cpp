#include <iostream>
#include <conio.h>
using namespace std;

class Stack {
  public:
    Stack(int num) {
      top = 0;
      maxelem = num;
      s = new int[maxelem];
    }
    
  void push(int t) {
  	cout << "Push "<<t<<": \n";
    if (top == maxelem) 
		return;
    s[top++] = t;
  }
  
  int pop() {
  	cout << "Pop: \n";
    if (top == 0) 
		return -1;
    return s[--top];
  }
  
  void display() {
    if (top == 0) {
      cout << "(empty)\n";
      return;
    }
    for (int t = 0; t < top; t++) 
		cout << s[t] << " ";
    cout << "\n";
  }
  
  int empty() {
    return top == 0;
  }
  
  private:
    int * s;
  	int top;
  	int maxelem;
};

void menu(){
	Stack * s = new Stack(100);
	int enteredChoice, pushNumber;
	while(enteredChoice!=4)
	cout << "What would you like to do?: "<<endl;
	cout << "1: Push"<<endl;
	cout << "2: Pop"<<endl;
	cout << "3: Display"<<endl;
	cout << "4: Exit"<<endl;
	cout << "Enter choice: ";
	cin>>enteredChoice;

	switch (enteredChoice){
		
		case 1:
			cout<<"Enter input: "<<endl;
			cin>>pushNumber;
			cout<<"Press Enter"<<endl;
			s -> push(pushNumber);
			break;
		
		case 2:
			s -> pop();
			break;
		
		case 3:
			s -> display();
			break;
		
		case 4:
			exit(0);
			break;	
				
		default:
			cout<<"Wrong input!";
			getch();
	}
}
int main(){
	menu();
	return 1;
}
