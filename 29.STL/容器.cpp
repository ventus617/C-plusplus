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
//	list<int> lst(3);		//指定链表的长度，且有默认的初始值
//	list<int> lst(3, 2);	//指定链表的长度，且指定初始值
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
//	lst.remove(2);//删除链表中值为2的所有元素
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
//	lst.unique();//移除连续且想同的节点
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
//	lst.sort();//自动排序,默认升序  
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(&rule);//自动排序,降序  a>b的顺序（用户指定的比较操作）
//
//	/*template <class Traits>
//	void sort(Traits comp); comp是用于排列连续元素的比较运算符 
//	成员模板函数 根据类Traits的 用户指定的比较操作 comp 对元素进行排序。*/
//
//
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(less<int>()); //升序 创建一个临时的less 一个二进制谓词，对其参数执行小于运算 （ ）
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//	lst.sort(greater<int>());//降序 创建一个临时的greater 一个二元谓词，对其参数执行大于运算 （ ）
//	for (int v : lst)
//	{
//		cout << v << "  ";
//	}
//	cout << endl;
//
//
//	lst.reverse();//翻转操作
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
//	lst.splice(++lst.begin(), lst2);//剪切操作 lst2就没了 在第一个lst的位置了
//	 
//	lst.splice(++lst.begin(), lst2, ++lst2.begin());//将lst2链表的第二个节点剪切过来
//
//	lst.splice(++lst.begin(), lst2, lst2.begin(), --lst2.end());//前面是闭区间[lst2.begin(),--lst2.end()) 后面是开区间 截取这一段范围的节点剪切
//
//	ite = lst.end();
//	::advance(ite, -3);//移动节点 往前是负 往后是加 将ite 向前移动3位
//
//	lst.splice(++lst.begin(), lst, ite, lst.end()); //剪切自己的
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
//	lst.merge(lst2);//将lst2 剪切合并到lst中,并且整体做一个排序(默认升序)
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
//	lst.merge(lst2,greater<int>());//指定降序 不指定的话 规格不一样 会报错
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
//	lst.swap(lst2);//交换操作 两个链表的节点交换 数量不同也能交换
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