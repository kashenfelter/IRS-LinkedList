#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
  clock_t start, end;
  double duration;

  start = clock();

  /* Your code is here */



  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;


int n=0;

while(n<100000){

cout << n << endl;

n=n*1000 +5*n+ (1/3)*n;
}













  cout<<"elapsed time: "<< duration <<'\n';



}

