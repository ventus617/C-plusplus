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
//		cout << "����ʧ��" << endl;
//		cout << *ret.first << endl;//�����Ѵ��ڵ�Ԫ�صĵ�����
//	}
//	ite = ++st.begin();
//	ite = st.erase(ite);//����ɾ������һ���ڵ�
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
//		cout << "�ҵ���" <<" " <<*ite<< endl;
//	}
//	else
//	{
//		cout << "û�ҵ�" << endl;
//	}
//
//	//ͳ���ж��ٸ�2 ���ٸ�3
//	cout << st.count(2) << endl;
//	cout << st.count(3) << endl;
//
//	return 0;
//}