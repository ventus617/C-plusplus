#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 1||n==2) return 1;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n = 10;
	for(n;n>0;n--)
	cout << fibonacci(n) << endl;
	return 0;
}