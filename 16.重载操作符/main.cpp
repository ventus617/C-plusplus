//#include<iostream>
//using namespace std;
//
//class C1
//{
//public:
//	int m_a;
//
//	char* m_p;
//	C1()
//	{
//		m_a = 10;
//		m_p = new char('b');
//	}
//public:
//	int add(int a)
//	{
//		return m_a + a;
//	}
//
//	//operator ���ز������Ĺؼ���,��������һ������,ͨ�������������չ�������Ĺ���
//	//������Ϊ: operator ����Ҫ���صĲ����� ����ӱ������ص����������� �൱�ڰѺ���������˲�����
//	//�������ȸ��� ������ ��ʹ�÷����й�,����˳�򣨺�д��˳���йأ�������������Ͳ��������������ƥ�䣩�����͵���ͬ, Ȼ������ڵĳ�Ա�����й�
//	//����ֵ:һ����Ҫ�з���ֵ��,Ϊ�˺ͺ����Ĳ�������������
//	int operator+(int a)
//	{
//		return m_a + a;
//	}
//
//	int operator=(int a)
//	{
//		m_a = a;
//		return m_a;
//	}
//	int operator+=(int a)
//	{
//		m_a += a;
//		return m_a;
//	}
//	//int operator++(/* C1 const * this */)
//	//{
//	//	//��++
//	//	return ++m_a;
//	//}
//	//int operator++(int)
//	//{
//	//	//��++ C++��׼�ڶ����һ����ʽ ����++��ָ��һ�����εĲ���,ֻ��Ϊ������,û�������ĺ���
//	//	return m_a++;
//	//}
//	char operator*()
//	{
//		return *m_p;
//	}
//	int operator* (int a)
//	{
//		return a * m_a;
//	}
//};
//
////10+tst;
////����,��������ͬһ����������
////��������,���ڵ����ز�����������Ĭ�ϵ�thisָ�����ڵ�һ������λ��,���Ա�������һ������,��������˳������һ����thisָ��
////������Ե�������˳��
//int operator +(int a, C1& tst)//����������
//{
//	return a + tst.m_a;
//}
//int operator +( C1& tst,int a)//����������
//{
//	return a + tst.m_a;
//}
//
//int operator++(C1&tst)
//{
//	//��++
//	return ++tst.m_a;
//}
//int operator++(C1&tst,int)
//{
//	//��++ C++��׼�ڶ����һ����ʽ ����++��ָ��һ�����εĲ���,ֻ��Ϊ������,û�������ĺ���
//	return tst.m_a++;
//}
//
////�����������
//ostream& operator<<(ostream& os, C1& tst)
//{
//	os << tst.m_a;
//	return os;
//}
//
//istream& operator>>(istream& is, C1& tst)
//{
//	is >> tst.m_a;
//	return is;
//}
//
////���������Ա����,�������������ء�=�������������ڰ�ȫ��ԭ��
////int operator=(int &a, C1& tst)
////{
////	a = tst.m_a;
////	return a;
////}
////�������������صĲ�����:= () [] ->
//
//
////���ܸı��������ʹ�ù���,������ʹ��Ĭ�ϲ���
//char operator +( C1& tst,char a/*='a'*/)//����������
//{
//	return a + *tst.m_p;
//}
////����������ٰ���һ���Զ�������(�ࡢ�ṹ��),�����ڶԲ��������ܵ���չ,�����ض�������¶���
////int operator+(int a, int b)
////{
////	return a + b;
////}
//
//
//int main()
//{
//	////C1 tst;
//	//////tst + 10;//tst.m_a+10;
//	////int a = tst.add(10);
//	////cout << a << endl;//20
//
//	////int b = tst.operator+(10);
//	////cout << b << endl;//20
//	////
//	////int c = tst + 10;
//	////cout << c << endl;//20
//	//////int d = 10 + tst;//˳����� ����ʹ��
//
//	////tst = 20;
//	////cout << tst.m_a << endl;
//
//	////C1 tst2;
//	////tst2 = tst = 30;//�з���ֵ�Ϳ��Խ������Ȳ���
//	////cout << tst.m_a << " " << tst2.m_a << endl;
//	////
//	////tst2 = tst += 20;//50
//
//	////cout << tst2.m_a << " " << tst.m_a << endl;
//
//	////int d = ++tst;
//	////cout << d << " " << tst.m_a << endl;//51 51
//	////int e = tst++;
//	////cout << e << " " << tst.m_a << endl;//51 52
//	//C1 tst;
//
//	////int f = 10 + tst;
//	////cout << f << endl;
//
//	//////int g=tst+10; //�����ڵ�ע�͵�,ƥ��һ�������
//	////cout << tst.operator+(10) << endl;//����
//	////cout << ::operator+(tst, 10) << endl;//����ȫ��
//
//	////int h = tst++;//��������ͬʱ����,���������;
//	////cout << h << " " << tst.m_a << endl;
//	////h = ++tst;
//	////cout << h << " " << tst.m_a << endl;
//
//	//cin >> tst;
//
//	//cout << tst;
//
//	//int a = 10;
//
//	////��������=�Ĵ���ʾ��
//	////a = tst;
//
//	////10 = tst;
//
//	////int& aa = 10;
//	C1 tst;
//	cout << *tst << endl;//b
//
//	cout << tst * 20 << endl;;//200
//
//	cout << tst + 'a' << endl;
//	//�������Ĳ�������ʹ��Ĭ�ϵ�
//	//��ô�͸ı��� + �ŵ�ʹ�ù��� ��ɣ�
//	//tst +; //�÷�����
//	return 0;
//}