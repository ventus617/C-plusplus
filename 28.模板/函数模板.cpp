//
//#include<iostream>
//using namespace std;
//
////int add(int a, int b)
////{
////	return a + b;
////}
//
//// template:����ģ��Ĺؼ���
//// <>:ָ��ģ��Ĳ����б�
//// typename������ģ�����͵Ĺؼ���
//
////1.ģ�����Ϳ���ͨ��ʵ�� �Զ��Ƶ������β����õ���ģ�����͵�����£�
////����Ӧ�벻ͬ���͵����ݴ���,��Ϊ�����ڼ�����һ�������ּ�����һ�����͵���������
//template<typename T>//����ģ��
//T add(T a, T b)		//ģ�庯��
//{
//	T t = a + b;//ģ�����Ϳ��Ծ͵������Ϊ �������� �Զ�ʶ�����������
//	cout<<typeid(a).name() <<" " <<t<<" " << typeid(t).name() << endl;
//	return a + b;
//}
//
////2.�ڵ��ú���ʱ����ʾ��ָ��ģ������
//template<typename T>
//void fun()
//{
//	T t = 10;
//	cout << t << " " << typeid(t).name() << endl;
//}
//
////3.ģ�����Ϳ���ָ��Ĭ�ϵ�����
//template<typename T =double>
//void fun2()
//{
//	T t = 10;
//	cout << t << " " << typeid(t).name() << endl;
//}
//
//
////ȷ��ģ�����������ַ�ʽ����ʾָ��>ʵ���Զ��Ƶ�>Ĭ��ָ��
//
//template<typename T=int>
//void fun3(T t)
//{
//	cout << t << " " << typeid(t).name() << endl;
//}
//
//
////���Զ��typename����
//template<typename T,typename K>
//void fun4(T t,K k)
//{
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//}
//
//
//
//template<typename T, typename K=short,typename M>//��ʾָ����ǿת��˳��һ��һ���� ���Իᱻ���ǵ� 
//void fun5()
//{
//	T t = 10;
//	K k = 20;
//	M m = 30;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
////���ں���ģ������ָ����Ĭ�ϵ�����,��û��ǿת��˳��Ҫ��
////һ����ԣ�����ͨ��ʵ���Զ��Ƶ���һ�����ģ������б����(�κ���������Է��Ų���)
////		  ��Ĭ�ϵ����ͷ����м䣨��Ĭ�ϵ����Ͳ�����Ĭ��ֵ��ʱ�� ����ֱ�Ӹģ���������ʽָ���ķ�����ǰ��
//template<typename T, typename K = short, typename M>
//void fun6(M m)//�����ʵ�οɹ��Ƶ�
//{
//	T t = 10;
//	K k = 20;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
//
//template<typename T,  typename M ,typename K = short>
//void fun7(M m)
//{
//	T t = 10;
//	K k = 20;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
////-------------------------------------------------------------
////��ģ��������Ͷ���ֿ�д ��ô����ü�����ʾ���� �� ���߱�ͨ����
//template<typename T>
//void fun8();
//
//template<typename T>
//void fun9(T t);
//
//
//
//int main()
//{
//	cout<<add(20, 30)<<endl;
//	/*cout << add(20, 30.1) << endl;*/
//	double a = 10.1, b = 20.2;
//	cout<<add(a, b) << endl;
//
//	//-------------------------------------
//	fun<int>();//�޷��Զ��Ƶ���ʵ�ε�����,���Ƶ������ʵ�ε�����  ��ʾָ��
//	fun<short>();
//	//-------------------------------------
//	fun2();
//	//-------------------------------------
//	
//	fun3(a);//10.1 double
//	fun3<short>(a);//10 short
//	//-------------------------------------
//
//
//	fun4('a', 12.3);
//	//-------------------------------------
//
//	fun5<int,long,int>();//û�д����ʵ�οɹ��Ƶ������� ����ʾָ��
//
//	fun6<int>('1');
//
//	//fun7<int,int*,long>('2'); //�����Զ�ƥ�����ʾָ����������ȫ������ ��˷Ƿ� ��ƥ�������
//
//	fun8<long>();
//	/*fun8<int>();*///�Ƿ�ʹ����ʾģ�����
//
//	fun9('a');//�޷��������ⲿ����"void __cdecl fun9<char>(char)" 
//
//
//
//	return 0;
//}
//
////ֻ������� long����ʵ�ֵ� ���߱�ͨ����
////void fun8<long>()//�޷��������ⲿ����"void __cdecl fun8<long>(void)"  ������<>
////{
////	cout << "fun8" << endl;
////}
//
//template<typename T>
//void fun8<T>()//<>:ָ��ģ��Ĳ����б�
//{
//	cout << "void fun8<T>" << endl;
//}
//
//
//////ֻ������� long����ʵ�ֵ� ���߱�ͨ����
////void fun9<char>(char t)//�Ƿ�ʹ����ʾģ��
////{
////	cout << "void fun9(char t)" << endl;
////}
//
//template<typename T>
//void fun9(T t)
//{
//	cout << "void fun9(T t)" << endl;
//}