//
//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	list<int> lst{ 1,2,3,4 };
//	//list<int>::const_iterator ite = lst.begin();
//	//类型自动推导
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
//	list<int>::reverse_iterator iteRev = lst.rbegin();//定义反向迭代器，指向反向的头
//	while (iteRev != lst.rend())
//	{
//		cout << *iteRev << " ";
//		iteRev++;
//	}
//	cout << endl;
//	
//	iteRev = lst.rbegin();//定义反向迭代器，指向反向的头
//	while (iteRev != lst.rend())
//	{
//		if (*iteRev == 2)
//		{
//			//iteRev 转为正向迭代器 向后偏移,减回去
//			lst.erase(--iteRev.base());// iteRev().base 将反向迭代器转换为正向迭代器 会偏移一个单位（反向迭代器的rbegin指向的尾部，在数列的头部多了一个rend，偏移过来时则会右移）
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