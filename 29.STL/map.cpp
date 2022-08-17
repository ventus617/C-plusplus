//
//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//int main()
//{
//	map<string, int> mm;
//	mm["aa"] = 10;
//	mm["bb"] = 20;
//	mm["cc"] = 30;
//	mm["ff"] = 40;
//	mm["hh"] = 50;
//	mm["jj"] = 60;
//
//	map<string, int>::iterator ite = mm.begin();
//	while (ite != mm.end())
//	{
//		//first:键值 second:实值
//		cout << ite->first << " " << ite->second << " ";
//
//		ite++;
//	}
//	cout << endl;
//
//	mm.insert(pair<string, int>("dd",50));
//	for (pair<string, int>pr : mm)
//	{
//		cout << pr.first << "-" << pr.second << " ";
//	}
//	cout << endl;
//
//	mm["dd"] = 60;//如果键值存在,则修改实值
//
//
//
//	//复合类型 实值是复合的bool类型
//	pair<map<string, int>::iterator, bool>ret = mm.insert(pair<string, int>("dd", 70));
//
//	if (ret.second)
//	{
//		cout << "插入成功" << endl;
//	}
//	else
//	{
//		cout << "插入失败" << endl;
//	}
//	//插入失败,返回的是已存在的元素的迭代器
//	cout << ret.first->first << "--" << ret.first->second << endl;//dd--60
//
//	ret = mm.insert(pair<string, int>("EE", 70));
//
//	if (ret.second)
//	{
//		cout << "插入成功" << endl;
//	}
//	else
//	{
//		cout << "插入失败" << endl;
//	}
//	//插入成功,返回的是插入的元素的迭代器
//	cout << ret.first->first << "--" << ret.first->second << endl;//dd--60
//
//	////会失败 因为存在了dd的键值
//	//mm.insert(pair<string, int>("dd", 70));
//	//for (pair<string, int>pr : mm)
//	//{
//	//	cout << pr.first << "-" << pr.second << " ";
//	//}
//	//cout << endl;
//
//	
//	for (pair<string, int>pr : mm)
//	{
//		cout << pr.first << "-" << pr.second << " ";
//	}
//	cout << endl;
//
//	ite = mm.erase(ret.first);//会指向下一个节点
//	cout << ite->first << "-" << ite->second << endl;
//
//	//--------------------------------------------------
//	//cout << mm.size() << endl;
//	//mm.clear();//清空map
//	//cout << mm.size() << endl;
//	//if (mm.empty())
//	//{
//	//	cout << "map为空" << endl;
//	//}
//	//else
//	//{
//	//	cout << "map 不为空" << endl;
//	//}
//
//	ite = mm.find("dd");//按照key查看
//	cout << ite->first << "-" << ite->second << endl;
//	ite = mm.find("DDD");
//	if (ite == mm.end())
//	{
//		cout << "没找到" << endl;
//	}
//
//	ite=mm.upper_bound("gg");//大于该键值的下一个 则是hh
//	cout << ite->first << "-" << ite->second << endl;
//
//	ite = mm.lower_bound("ee");//大于等于该键值的下一个 则是ff
//	cout << ite->first << "-" << ite->second << endl;
//
//	return 0;
//}