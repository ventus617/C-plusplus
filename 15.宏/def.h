//#pragma once
//
////�������:"�滻"
//
//
//// \; ���ӵ�ǰ�к���һ��,һ�����һ�в���\,������Ҫ������һ������ ��б�ܺ��治Ҫ���κε��ַ����ո�,TAB,ע��Ҳ���У�
//
//#define NN 10
//#define AA for(int i=0;i<NN;i++){\
//cout << i << endl;\
//}
//
////int a;
//
// 
////����Դ�����,����Ҳ��һ���滻������,����Ҳ����ֻ��һ���滻����,����ȥ�Զ��������,Ҳ���������ʽ���
//#define BB(COUNT)\
//	for(int i=0;i<COUNT;i++){\
//	cout << i << endl;\
//	}
//
//
//
//#define CC(A,B) A*B
//
//#define DD(A,B)  (A)*(B)
//
//#define EE(A,B)  ((A)*(B))
//
////---------------------------------
//
//// #:����Ĳ���ת��Ϊ�ַ���,�൱�ڼ��� ˫����
//
//#define FF(PARAM) #PARAM
//
//
////#@������Ĳ���ת��Ϊ�ַ�,�൱�ڼ����� ������
//#define HH(PARAM) #@PARAM
//
//
////##��������ϳ�һ������,ƴ������
//
//#define JJ  int a##b=10;
//
//#define KK(PARAM) int a##PARAM=10;
//
//#include<iostream>
//using namespace std;
//
//class CAA {
//public:
//	void fun()
//	{
//		cout << "CAA::fun" << endl;
//	}
//	void fun2()
//	{
//		cout << "CAA::fun2" << endl;
//	}
//};
//
//class CBB {
//public:
//	void fun()
//	{
//		cout << "CBB::fun" << endl;
//	}
//	void fun2()
//	{
//		cout << "CBB::fun2()" << endl;
//	}
//};
//
//#define MM(CLASS_NAME)\
//	CLASS_NAME aa6##CLASS_NAME;\
//	aa6##CLASS_NAME.fun();\
//	aa6##CLASS_NAME.fun2();
//
//#define RR(PARAM) int a=PARAM;
////�걾�������﷨���,�����ڼ�Ż���