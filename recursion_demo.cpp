#include<iostream>
using namespace std;
long fact(int n)
{
  if(n>0)	
    return (n*fact(n-1));
  else
    return (1);
}
//5!=5*4*3*2*1=120
int main()
{
	printf("Factorial of 6 is %ld",fact(6));
	return 0;
}
