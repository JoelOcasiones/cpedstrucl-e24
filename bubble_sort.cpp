#include <iostream>

using namespace std;

int main(){
	int j,f;
	int A[] = {35, 10, 55, 20, 5};
	
	//Sorting algorithm for bubble sort
	for(int i=1; i<5; ++i){

		for(int j=0; j<(5-i); ++j){

			if(A[j] > A[j+1]){
				
				int swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;		
			}
			for(int f=0; f<5; ++f )
        	cout << A[f] << endl;
		}
		
	}
}
