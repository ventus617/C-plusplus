
//#include<iostream>
//#include<list>
//#include<string>
//#include<map>
//using namespace std;
//
//struct Stat_Bus
//{
//	string stat;//վ��
//	int bus;//����
//
//};
//
//int main()
//{
//	list<Stat_Bus> lst;
//	lst.push_back(Stat_Bus{ "�ڴ�",100 });
//	lst.push_back(Stat_Bus{ "����",200 });
//	lst.push_back(Stat_Bus{ "����",300 });
//
//	string stat = "";
//	cin >> stat;
//	list<Stat_Bus>::iterator ite = lst.begin();
//	while (ite != lst.end())
//	{
//		
//		if (ite->stat != ""&&ite->stat==stat)
//		{
//			cout << stat << "--" << ite->bus << endl;
//			break;
//		}
//		ite++;
//	}
//
//	//------------------------------------------------------------
//	map<string, int> map_bus;
//	map_bus["����"] = 300;
//	map_bus["�ڴ�"] = 100;
//	map_bus["����"] = 100;
//
//	string stat2 = "";
//	cin >> stat2;
//	map<string, int>::iterator ite2 = map_bus.find(stat2);
//	if (ite2 != map_bus.end())
//	{
//		cout << ite2->first << "--" << ite2->second << endl;
//	}
//
//	//------------------------------------------------------
//	map<string, list<int>> map_bus2;
//	map_bus2["�ڴ�"].push_back(100);
//	map_bus2["�ڴ�"].push_back(120);
//	map_bus2["�ڴ�"].push_back(110);
//	map_bus2["�ڴ�"].push_back(140);
//	map_bus2["����"].push_back(200);
//	map_bus2["����"].push_back(210);
//	map_bus2["����"].push_back(220);
//	map_bus2["����"].push_back(230);
//	map_bus2["����"].push_back(67);
//	map_bus2["����"].push_back(78);
//	map_bus2["����"].push_back(98);
//	map_bus2["����"].push_back(104);
//
//	string stat3 = "";
//	cin >> stat3;
//
//	map<string,list<int>>::iterator ite3=map_bus2.find(stat3);
//	if (ite3 != map_bus2.end())
//	{
//		cout << ite3->first << ":";
//		for (int v : ite3->second)
//		{
//			cout << v << "  ";
//		}cout << endl;
//	}
//	
//	return 0; 
//}