//
//#include<iostream>
//#include<algorithm>
//#include<list>
//#include<map>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//void fun(int a)
//{
//	cout << a<<" ";
//}
//void fun_map(pair<int, char>pr)
//{
//	cout << pr.first << "-" << pr.second << " ";
//}
//
//bool rule(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	list<int> lst{ 2,3,4,5,6,7,8,9,1 };
//	::for_each(lst.begin(), lst.end(), &fun);//��������
//	cout << endl;
//
//	map<int,char> mm;
//	mm[3] = '3';
//	mm[4] = '4';
//	mm[2] = '2';
//	mm[1] = '1';
//	::for_each(mm.begin(), mm.end(), &fun_map);//����map
//	cout << endl;
//	//--------------------------------------------------
//	lst.push_back(4);
//	int a=::count(lst.begin(), lst.end(), 4);//���ش�x��x֮���4�ĸ���
//	cout << a << endl;
//
//	//----------------------------------------
//	vector<int> vec1{ 1,2,3,4 };
//	vector<int> vec2{ 1,2,3,4,5 };
//
//	cout<<::equal(vec1.begin(), vec1.end(), vec2.begin())<<endl;//�ӵ�һ������λ�ÿ�ʼ �ڶ�������λ�ý��� ������������Ҫ�Ƚϵ�λ��
//
//	vector<int> vec3{ 1,2,3,5 };
//	cout<< ::equal(vec3.begin(), vec3.end(), vec2.begin()) << endl;//����
//
//	vector<int> vec4{ 0,1,2,3,5 };
//	cout << ::equal(vec1.begin(), --vec1.end(), ++vec4.begin()) << endl;//��
//
//	vector<int>vec5{ 0,1,2 };
//	//cout << ::equal(vec1.begin(), --vec1.end(), ++vec5.begin()) << endl;//���� ���ܺͿձȽ�
//	
//	vector<int>::iterator ite=::find(vec1.begin(), vec1.end(), 2);//����
//	
//	if(ite!=vec1.end())cout << *ite << endl;
//
//	vector<int>::iterator iteEnd = vec1.end() - 2;//�˹��趨��β��Χ
//	ite = ::find(vec1.begin(), iteEnd, 3);
//	if (ite == iteEnd)
//	{
//		cout << "û�ҵ���" << *ite << endl;
//	}
//
//	//----------------------------------------------------------------
//	vector<int> vec6{ 6,9,2,0,1,2,3,7,5 };
//	::sort(vec6.begin(), vec6.end(), &rule);
//	::for_each(vec6.begin(), vec6.end(), &fun);
//	cout << endl;
//	::sort(vec6.begin(), vec6.end(), less<int>());
//	::for_each(vec6.begin(), vec6.end(), &fun);
//	cout << endl;
//
//	//----------------------------------------------------------------
//	//unordered_map<int, char>un_map;
//	//un_map.insert(pair<int, char>(3, '3'));
//	//un_map.insert(pair<int, char>(2, '2'));
//	//un_map.insert(pair<int, char>(1, '1'));
//	//un_map.insert(pair<int, char>(4, '4'));
//	////�Ƿ� sort��Ҫ�����ܹ�ֱ��ͨ��iteʵ�ֽڵ�Ӽ��� un_map��list��ite����������ʹ��
//	//::sort(un_map.begin(), un_map.end(), less<int>());
//	//::for_each(un_map.begin(), un_map.end(), &fun_map);
//	//cout << endl;
//
//	//----------------------------------------------------------------
//	{
//		vector<int> vec1{ 1,2,3,4,5 };
//		vector<int> vec2{ 1,2,3,5,5 };
//
//		vector<int>vec3 = ::max(vec1, vec2);//��Ƚ�����
//		::for_each(vec3.begin(), vec3.end(), &fun);
//		cout << endl;
//
//		vector<int> vec4{ 1,2,3,3 };
//		vec3 = ::max(vec1, vec4);
//		::for_each(vec3.begin(), vec3.end(), &fun);
//		cout << endl;
//
//		//----------------------------------------------------------
//		map<string, int>mm1;
//		mm1["a"] = 1;
//		mm1["b"] = 2;
//		mm1["c"] = 3;
//		mm1["d"] = 4;
//		map<string, int>mm2;
//		mm2["a"] = 1;
//		mm2["b"] = 2;
//		mm2["c"] = 2;
//		mm2["d"] = 5;
//		map<string, int>mm3;
//		mm3=::max(mm1, mm2);//keyֵ��ͬ������� ʵֵ�ȸ���ĸ���
//		for (pair<string, int>pr : mm3)
//		{
//			cout << pr.first << "-" << pr.second<<" ";
//		}
//		cout << endl;
//
//		map<string, int>mm4;
//		mm4["a"] = 1;
//		mm4["b"] = 2;
//		mm4["d"] = 2;
//		mm4["e"] = 2;
//
//		mm3 = ::max(mm1, mm4);//��keyֵΪ���� �����
//		for (pair<string, int>pr : mm3)
//		{
//			cout << pr.first << "-" << pr.second << " ";
//		}
//		cout << endl;
//
//		map<string, int>mm5;
//		mm5["a"] = 1;
//		mm5["ba"] = 2;
//		mm5["d"] = 3;
//		mm5["e"] = 4;
//
//		mm3 = ::max(mm1, mm5);//��keyֵΪ���� �����(�ַ����ȵ����ַ�����
//		for (pair<string, int>pr : mm3)
//		{
//			cout << pr.first << "-" << pr.second << " ";
//		}
//		cout << endl;
//
//		mm3 = ::min(mm1, mm5);//��keyֵΪ���� ��С��(�ַ����ȵ����ַ�����
//		for (pair<string, int>pr : mm3)
//		{
//			cout << pr.first << "-" << pr.second << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}