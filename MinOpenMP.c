#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){

srand(time(NULL));
int n = 0;
cout<<"Enter size";
cin>>n;
int **a=new int* [n];

for (int i =0; i<n; i++){
a[i]=new int [n];}

for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
	a[i][j]=rand() % 10;
	cout<<a[i][j] <<" ";
	}
	cout<<endl;}
for (int i=o; i<n; i++){
delete[] a[i];
}
delete []a;
return 0;

}
