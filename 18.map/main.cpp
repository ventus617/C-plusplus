#include<iostream>
#include<map>
using namespace std;

int main()
{
	//map 可以根据键值进行自动的排序,键值唯一,map里 每个元素是一个键值对,用pair表示
	//映射表<键值,实值>
	map<int, string> mm;

	//[键值]=实值
	mm[1] = "11";//键值不存在时,相当于添加数据，新增一条数据
	mm[2] = "22";
	mm[3] = "33";
	mm[4] = "44";

	map<int, string>::iterator ite = mm.begin();
	while (ite != mm.end())
	{
		cout << ite->first<<"--"<<ite->second << "  ";
		ite++;
	} 
	cout << endl;
	//1-11 2-22 3-33 4-44

	mm[2] = "55";//键值存在时,则是修改对应的实值,重新赋值

	
	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;
	//1-11 2-55 3-33 4-44



	cout << "-----------------------------------------" << endl;


	ite=++mm.begin();
	ite=mm.erase(ite);//自动++
	cout << ite->first << " " << ite->second << endl;
	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;


	cout << "-----------------------------------------" << endl;
	//------------------------------------------------------------
	//判断某个键值是否存在,由此才能修改
	int a = mm.count(1);//如果键值1存在 a为真 键值1不存在 a为假
	if (a)
	{
		cout << "存在" << endl;
		mm[1] = "100";
	}
	else
	{
		cout << "不存在" << endl;
	}

	a = mm.count(10);
	if (a)
	{
		cout << "存在" << endl;
		mm[10] = "100";
	}
	else
	{
		cout << "不存在" << endl;
	}

	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;


	return 0;
}