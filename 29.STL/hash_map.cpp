//
//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<int, string> un_map;
//
//	un_map.insert(pair<int, string>(12, "845k"));
//	un_map.insert(pair<int, string>(23, "24g"));
//	un_map.insert(pair<int, string>(56, "tu2"));
//	un_map.insert(pair<int, string>(72, "29k"));
//	un_map.insert(pair<int, string>(7, "5hn"));
//
//	unordered_map<int, string>::iterator ite = un_map.begin();
//	while (ite != un_map.end())
//	{
//		cout << ite->first << "-" << ite->second <<"  ";
//		ite++;
//	}
//	cout << endl;
//	ite = ++un_map.begin();
//	ite=un_map.erase(ite);//删除第二个节点 指向第三个节点
//	cout << ite->first << "-" << ite->second << endl;
//	for (pair<int, string>pr : un_map)
//	{
//		cout << pr.first << "-" << pr.second << "  ";
//	}
//	cout << endl;
//
//	ite = un_map.find(72);//通过查找的方法来获得节点
//	if (ite != un_map.end())
//	{
//		ite = un_map.erase(ite);
//		cout << ite->first << "-" << ite->second << endl;
//	}
//	for (pair<int, string>pr : un_map)
//	{
//		cout<<pr.first << "-" << pr.second << " ";
//	}
//	cout << endl;
//	return 0;
//}