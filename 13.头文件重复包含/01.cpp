#include"b.h"
#include"cc.h"
#include<iostream>
using namespace std;

//ͬһ��ͷ�ļ� �൱�ڰ����˶��
//#include"aa.h"
//#include"aa.h"
 

//���ڵ�ǰ��Դ�ļ���,�൱�ڶ����˶��

//class CAA {
//public:
//	int m_a;
//	CAA();
//};
//
//class CAA {
//public:
//	int m_a;
//	CAA();
//};



int main()
{
	CBB bb;
	cout << bb.m_aa.m_a << endl;//��һ����Ա��һ��CAA���͵Ķ��� �ڶ�����CAA����ĳ�Ա����

	CCC cc;
	cout << cc.m_aa.m_a << endl;


	return 0;
}