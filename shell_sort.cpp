#include<iostream> 

using namespace std;

void shell_sort(int *a, int n){
	int count(0);
	int h, i, j, f;
	for(h=n; h/=2;){
		for(i=h; i<n; i++){
			f=a[i];
			for(j=i; j>=h && f<a[j-h]; j-=h){
				a[j] = a[j-h];
			}
			a[j]=f;
			cout << "PASS: " <<++count<<endl;  
        	for(int f=0;f<5;++f)
        		cout<<a[f]<<endl;     
		}
	}
}

int main(int ac, char **av){
    int a[]= {40, 30, 20, 50, 10}; 
	int n = 5;
	shell_sort(a,n);  
    return 0;
}
