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
//		//first:��ֵ second:ʵֵ
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
//	mm["dd"] = 60;//�����ֵ����,���޸�ʵֵ
//
//
//
//	//�������� ʵֵ�Ǹ��ϵ�bool����
//	pair<map<string, int>::iterator, bool>ret = mm.insert(pair<string, int>("dd", 70));
//
//	if (ret.second)
//	{
//		cout << "����ɹ�" << endl;
//	}
//	else
//	{
//		cout << "����ʧ��" << endl;
//	}
//	//����ʧ��,���ص����Ѵ��ڵ�Ԫ�صĵ�����
//	cout << ret.first->first << "--" << ret.first->second << endl;//dd--60
//
//	ret = mm.insert(pair<string, int>("EE", 70));
//
//	if (ret.second)
//	{
//		cout << "����ɹ�" << endl;
//	}
//	else
//	{
//		cout << "����ʧ��" << endl;
//	}
//	//����ɹ�,���ص��ǲ����Ԫ�صĵ�����
//	cout << ret.first->first << "--" << ret.first->second << endl;//dd--60
//
//	////��ʧ�� ��Ϊ������dd�ļ�ֵ
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
//	ite = mm.erase(ret.first);//��ָ����һ���ڵ�
//	cout << ite->first << "-" << ite->second << endl;
//
//	//--------------------------------------------------
//	//cout << mm.size() << endl;
//	//mm.clear();//���map
//	//cout << mm.size() << endl;
//	//if (mm.empty())
//	//{
//	//	cout << "mapΪ��" << endl;
//	//}
//	//else
//	//{
//	//	cout << "map ��Ϊ��" << endl;
//	//}
//
//	ite = mm.find("dd");//����key�鿴
//	cout << ite->first << "-" << ite->second << endl;
//	ite = mm.find("DDD");
//	if (ite == mm.end())
//	{
//		cout << "û�ҵ�" << endl;
//	}
//
//	ite=mm.upper_bound("gg");//���ڸü�ֵ����һ�� ����hh
//	cout << ite->first << "-" << ite->second << endl;
//
//	ite = mm.lower_bound("ee");//���ڵ��ڸü�ֵ����һ�� ����ff
//	cout << ite->first << "-" << ite->second << endl;
//
//	return 0;
//}