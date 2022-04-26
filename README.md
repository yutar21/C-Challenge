#include<iostream>
using namespace std;
int main()
{
	int a = 3, y = 5;
    int *xPtr,x[10] = {0};
    xPtr = &x[1];
    *(xPtr + 3) = x[5] = a + y;   
	cout<<x[3]<<'\t'<<x[4]<<'\t'<<x[5];  
}
