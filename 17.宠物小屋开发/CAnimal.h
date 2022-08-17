#pragma once
#include<string>
using namespace std;
class CAnimal
{
public:
	string m_strName;

	string m_strColor;

	int m_nAge;
public:
	CAnimal();
	virtual ~CAnimal();
public:
	void InitAnimal(string& name, string& color, int age);
	void ShowAnimal();

	virtual void PlayAnimal() = 0;//´¿Ðéº¯Êý
};