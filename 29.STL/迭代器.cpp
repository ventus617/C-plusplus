//
//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	list<int> lst{ 1,2,3,4 };
//	//list<int>::const_iterator ite = lst.begin();
//	//�����Զ��Ƶ�
//	auto ite = lst.begin();
//	while (ite!=lst.end())
//	{
//		cout << *ite << " ";
//		ite++;
//	}
//	cout << endl;
//	//-------------------------------
//	ite = --lst.end();
//	while (ite != lst.begin())
//	{
//		cout << *ite << "  ";
//		ite--;
//	}
//	cout << endl;
//
//	ite = lst.end();
//	while (ite != lst.begin())
//	{
//		cout << *(--ite)<< "  ";
//	}
//	cout << endl;
//	//-------------------------------
//	list<int>::reverse_iterator iteRev = lst.rbegin();//���巴���������ָ�����ͷ
//	while (iteRev != lst.rend())
//	{
//		cout << *iteRev << " ";
//		iteRev++;
//	}
//	cout << endl;
//	
//	iteRev = lst.rbegin();//���巴���������ָ�����ͷ
//	while (iteRev != lst.rend())
//	{
//		if (*iteRev == 2)
//		{
//			//iteRev תΪ��������� ���ƫ��,����ȥ
//			lst.erase(--iteRev.base());// iteRev().base �����������ת��Ϊ��������� ��ƫ��һ����λ�������������rbeginָ���β���������е�ͷ������һ��rend��ƫ�ƹ���ʱ������ƣ�
//			break;
//		}
//		iteRev++;
//	}
//	for (int v : lst)
//	{
//		cout << v << " "  ;//1,3,4
//	}
//	cout << endl;
//
//	return 0;
//}