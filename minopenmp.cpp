#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <omp.h>
#include <time.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

srand(time(NULL));
int n = 0;
int min =0;
int maxrand =0;
cout<<"Enter size: ";
cin>>n;
cout<<endl;
cout<<"Enter max rand: ";
cin>>maxrand;
int **a=new int* [n];

for (int i =0; i<n; i++){
a[i]=new int [n];}
int nthreads;
clock_t clock_timer;
double wall_timer;
ofstream fout("data.txt");
//#pragma omp parallel num_threads(4){
for (nthreads=1; nthreads <=10; ++nthreads){
clock_timer=clock();
wall_timer =omp_get_wtime();
#pragma omp for
for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
	a[i][j]=rand() % maxrand;
	cout<<a[i][j] <<" ";
	}
	cout<<endl;}
min = a[0][0];
#pragma omp for
for ( int i = 0; i <n; i++){
	for (int j=0; j<n; j++){
		if (a[i][j]<min)
			min=a[i][j];}}
cout<<endl;
cout<<"Minimum: "<<min<<endl;
cout<<"threads: "<< nthreads << "time on clock: "<<
 (double)(clock() - clock_timer)/CLOCKS_PER_SEC
<< "time on wall: "<< omp_get_wtime() - wall_timer<<"\n";
fout<<nthreads<<" "<<omp_get_wtime() - wall_timer<<"\n";
//}
}
fout.close();
for (int i=0; i<n; i++){
delete[] a[i];
}
delete []a;
return 0;

}
