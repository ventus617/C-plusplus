#include<iostream>
template<typename T>
T add(T a, T b)
{

	return a + b;
	
}

int main()
{	
	double c = 1.1, d = 2.2;
	int a = add(10, 20);
	double e=add(c, d);
	return 0;
}