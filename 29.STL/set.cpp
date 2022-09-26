//
//#include<iostream>
//#include<set>
//using namespace std;
//
//int main()
//{
//	set<int> st;
//	st.insert(2);
//	st.insert(4);
//	st.insert(3);
//	st.insert(1);
//
//	set<int>::iterator ite = st.begin();
//	while (ite != st.end())
//	{
//		cout << *ite << endl;
//		ite++;
//	}
//	cout << endl;
//
//	pair<set<int>::iterator, bool>ret = st.insert(1);
//	if (!ret.second)
//	{
//		cout << "插入失败" << endl;
//		cout << *ret.first << endl;//返回已存在的元素的迭代器
//	}
//	ite = ++st.begin();
//	ite = st.erase(ite);//返回删除的下一个节点
//	cout << *ite << endl;
//	for (int v : st)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	ite=st.find(3);
//	if (ite!=st.end())
//	{
//		cout << "找到了" <<" " <<*ite<< endl;
//	}
//	else
//	{
//		cout << "没找到" << endl;
//	}
//
//	//统计有多少个2 多少个3
//	cout << st.count(2) << endl;
//	cout << st.count(3) << endl;
//
//	return 0;
//}