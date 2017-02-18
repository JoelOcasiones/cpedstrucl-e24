#include <iostream>

using namespace std;

int main(){
	int count(0);
	int A[] = {30, 40, 20, 50, 10};
	
	//Sorting for selection
	for(int i=0; i<5-1; i++){
		int min=A[i], index=i;
		for(int j=i+1; j<5; j++){
			if(A[j] < min){
				min=A[j];
				index=j;
			}
			A[index] = A[i];
			A[i] = min;
			cout << "Pass: " << ++count << endl;
			for(int f=0; f<5; ++f)
			cout << A[f] << endl;	
		
		}
		
		
	}
	return 0;
}
