//
//#include<iostream>
//#include<list>
//using namespace std;
//
//bool rule(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	list<int> lst(3);		//ָ������ĳ��ȣ�����Ĭ�ϵĳ�ʼֵ
//	list<int> lst(3, 2);	//ָ������ĳ��ȣ���ָ����ʼֵ
//	list<int>::iterator ite = lst.begin();		
//	while (ite != lst.end())
//	{
//		cout << *ite << " ";
//		ite++;
//	}
//	cout << endl;
//
//	lst.push_back(3);
//	lst.push_back(4);
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.remove(2);//ɾ��������ֵΪ2������Ԫ��
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.push_back(3);
//	lst.push_back(3);
//	lst.push_back(5);
//	lst.push_back(5);
//	lst.push_back(6);
//	lst.push_back(5);
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//
//	lst.unique();//�Ƴ���������ͬ�Ľڵ�
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.push_front(8);
//	lst.push_front(2);
//	lst.push_front(7);
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort();//�Զ�����,Ĭ������  
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(&rule);//�Զ�����,����  a>b��˳���û�ָ���ıȽϲ�����
//
//	/*template <class Traits>
//	void sort(Traits comp); comp��������������Ԫ�صıȽ������ 
//	��Աģ�庯�� ������Traits�� �û�ָ���ıȽϲ��� comp ��Ԫ�ؽ�������*/
//
//
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(less<int>()); //���� ����һ����ʱ��less һ��������ν�ʣ��������ִ��С������ �� ��
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(greater<int>());//���� ����һ����ʱ��greater һ����Ԫν�ʣ��������ִ�д������� �� ��
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//
//	lst.reverse();//��ת����
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	list<int> lst2{ 100,200,300 };
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//
//	lst.splice(++lst.begin(), lst2);//���в��� lst2��û�� �ڵ�һ��lst��λ����
//	 
//	lst.splice(++lst.begin(), lst2, ++lst2.begin());//��lst2����ĵڶ����ڵ���й���
//
//	lst.splice(++lst.begin(), lst2, lst2.begin(), --lst2.end());//ǰ���Ǳ�����[lst2.begin(),--lst2.end()) �����ǿ����� ��ȡ��һ�η�Χ�Ľڵ����
//
//	ite = lst.end();
//	::advance(ite, -3);//�ƶ��ڵ� ��ǰ�Ǹ� �����Ǽ� ��ite ��ǰ�ƶ�3λ
//
//	lst.splice(++lst.begin(), lst, ite, lst.end()); //�����Լ���
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	-------------------------------------------
//	lst.clear();
//	lst2.clear();
//
//	lst.push_back(4);
//	lst.push_back(14);
//	lst.push_back(6);
//	lst.push_back(7);
//	lst.push_back(24);
//	lst.push_back(54);
//	lst.push_back(74);
//
//	lst2.push_back(41);
//	lst2.push_back(23);
//	lst2.push_back(5);
//	lst2.push_back(8);
//	lst2.push_back(79);
//	lst2.push_back(89);
//
//	lst.sort(less<int>());
//	lst2.sort(less<int>());
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.merge(lst2);//��lst2 ���кϲ���lst��,����������һ������(Ĭ������)
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(greater<int>());
//	lst2.sort(greater<int>());
//	lst.merge(lst2,greater<int>());//ָ������ ��ָ���Ļ� ���һ�� �ᱨ��
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//
//	lst.swap(lst2);//�������� ��������Ľڵ㽻�� ������ͬҲ�ܽ���
//
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//	for (int v : lst2)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//	return 0;
//}