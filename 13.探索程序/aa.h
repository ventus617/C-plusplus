#pragma once

//��������

//����Ӧ�÷���Դ�ļ���
//int a;
////�����Ķ��嵫û�г�ʼ��
//int b = 10;
////�����Ķ��岢�ҳ�ʼ��

extern int a;//����������


//��������

void fun();//����������


//------------------------------------

//int b = 20;//���� ���ܻᵼ���ض������� �൱����aa.h�ж���һ�� ��������Դ�ļ��ж�����һ��
//error LNK2005: "int b" (?b@@3HA) �Ѿ��� aa.obj �ж���


class CTest
{
public:
	int m_a;
	static int m_b;
	const int m_c;//�ڹ��캯���ĳ�ʼ�������б��г�ʼ��
public:
	CTest() ;//���������
	~CTest() ;//����������
	void fun();
	static void fun2();
	void fun3()const;
	virtual void fun4();
};

//���ⶨ���ҳ�ʼ��
//int CTest::m_b = 30;//�ض���: error LNK2005: "public: static int CTest::m_b" (?m_b@CTest@@2HA) �Ѿ��� aa.obj �ж���