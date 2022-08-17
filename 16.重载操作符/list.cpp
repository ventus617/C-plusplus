#include<iostream>
#include<list>//1.包含头文件
using namespace std;//2. 打开标准命名空间

int main()
{
	list<int> lst;//定义一个链表 每个节点元素是一个整形

	lst.push_back(1); //尾添加
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	//迭代器,遍历容器的 这里是遍历链表 本质上是一个类 
	list<int>::iterator  ite(lst.begin()); //begin() 获取头结点的迭代器
	ite = lst.begin();
	while (ite != lst.end())//end() 是返回尾结点的函数
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;



	lst.push_front(0);//头添加
	ite = lst.begin();
	while (ite != lst.end())//end() 是返回的list标识的尾结点 的函数
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;


	lst.push_back(5);
	lst.push_back(10);
	lst.pop_front();//出头栈
	lst.pop_back();//尾出栈
	for (int v : lst)//2.第二种遍历的方法,增强范围的for循环
	{
		cout << v << " ";
	}
	cout << endl;

	//------------------------------------------------------
	//在迭代器指向的节点的位置去插入一个元素,新插入的元素位置在其前面,且返回的是新插入的节点迭代器
	list<int>::iterator ite1=lst.insert(++lst.begin(), 10);
	cout << *ite1 << endl;//10
	for (int v : lst)//2.第二种遍历的方法,增强范围的for循环
	{
		cout << v << " ";
	}
	cout << endl;

	//-------------------------------------------------------
	//参数：要删除的节点的迭代器,返回值是删除节点的下一个节点的迭代器,自带一个ite++效果
	ite1 = ++lst.begin();
	list<int>::iterator ite2 = lst.erase(ite1);
	cout << *ite2 << endl;//2
	//cout << *ite1 << endl; //指向一个被回收的节点 程序会崩溃 参数迭代器失效
	for (int v : lst)//2.第二种遍历的方法,增强范围的for循环
	{
		cout << v << " ";
	}
	cout << endl;





	ite1 = lst.begin();
	ite1 = lst.erase(ite1);
	cout << *ite1 << endl;
	for (int v : lst)//2.第二种遍历的方法,增强范围的for循环
	{
		cout << v << " ";
	}
	cout << endl;

	//--------------------------------------------

	cout << *lst.begin() << " " << lst.front()<<" "<<lst.back() << endl;
	//cout << *lst.end() << endl;//崩溃 end() 返回的是有效尾节点的下一个无效的尾节点（尾标识节点）
	cout << *(--lst.end()) << endl;//


	lst.push_back(2);
	lst.push_back(8);
	lst.push_back(6);
	cout << lst.size() << endl;//返回链表的长度 有效个数
	for (int v : lst)//2.第二种遍历的方法,增强范围的for循环
	{
		cout << v << " ";
	}
	cout << endl;






	lst.clear(); //清空链表
	if (lst.empty())
	{
		cout << "链表为空" << endl;
	}
	cout << lst.size() << endl;
	return 0;
}