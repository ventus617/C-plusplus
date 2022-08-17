#pragma once
#include<iostream>
using namespace std;


class C1 {
public:
	int m_a;
public:
	C1(int a)
	{
		m_a = a;
		cout << a << endl;
	}
	~C1()
	{
		cout << "0" << endl;
	}
};