//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	//vector<int> vec(3);//0 0 0 ���� ����ֵ��Ĭ��Ϊ0
//	vector<int> vec(3, 4);//vector �൱��һ����̬���� ָ����ʼ�������Ĵ�С��������ʹ������,��ָ����ʼ��������ֵ
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//
//
//	vec.push_back(1);//������֮�� ���� ����һƬ��������� ��ԭ�ȵĿ�����ȥ ���ͷŵ���ǰ��
//	vec.push_back(2);
//	vec.push_back(4);
//	vec.push_back(5);
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	vec.pop_back();//����ֻ������Ҫ���ݵ�ʱ��Ż�仯 ɾ�����߳�ջ��Ӱ��
//	vec.pop_back();
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	//�������� ���ǵ�Ч������ �����Ƕ�̬���� �������ͷλ��ӻ���ɾ�� ��Ҫ���±�����ֵ Ч�ʼ��� ���û���ṩfront�Ĳ���
//	//vec.push_front();
//	//vec.pop_front();
//
//	//�ṩ�˲������ ������Ҫ��Ϊ�˱�����ͨ��ͷλ���� ���µ�Ч�ʼ���
//	vec.insert(vec.begin(), 10);
//
//	vector<int>::iterator ite = vec.begin();
//	while (ite!= vec.end())
//	{
//		cout << *ite << " ";
//		ite++;
//	}
//	cout << endl;
//
//	ite = vec.begin();
//	//::advance(ite, 4);
//	ite += 4;//vectoe֧�� ����֧�� ��begin��λ���������ĵ�4��
//	ite=vec.erase(ite);//ite��ʧЧ,һ�㷵��ֵ��һ�£�����ɾ������һ��
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << *ite << endl;
//
//	//---------------------------------------------
//	cout << vec.front() << endl;//��ȡ��Ԫ��ֵ
//	cout << vec.back() << endl;//��ȡβԪ��ֵ
//
//	//vec.clear();//��գ�ʹ������
//	if (vec.empty())
//	{
//		cout << "vector Ϊ��" << endl;
//	}
//	else
//	{
//		cout << vec.size() << endl;
//	}
//
//	//----------------------------------------------
//	vec.resize(3);//�����趨ʹ���� �ӿ�ͷ��ʼ�� ����Ǽ���ʹ���� ��������ı�
//	for (int i=0;i<vec.size();i++)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//
//	vec.resize(6);
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//
//	vec.resize(10, 5);//�����ʹ������5����
//	for (int i = 0; i < vec.size(); i++)//����������һ��ȥ���� Ѱ�� ʹ��
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//
//
//	vector<int>vec2{ 1,2,3,4,5,6,7,8,9 };
//	vec.swap(vec2);//������ͬҲ�ܽ���
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";//����������һ��ȥ���� Ѱ�� ʹ��
//	}
//	cout << endl;
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//
//
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		cout << vec2[i] << " ";//����������һ��ȥ���� Ѱ�� ʹ��
//	}
//	cout << endl;
//	cout << "ʹ����" << vec2.size() << " ,���� " << vec2.capacity() << endl;
//
//
//	//-----------------------------------------------------------------
//
//	cout << "�����е�0����7" << endl;
//	
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		if (vec2[i] == 0)//����������һ��ȥ���� Ѱ�� ʹ��
//		{
//			vec2[i] = 7;
//		}
//	}
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		cout << vec2[i] << " ";//����������һ��ȥ���� Ѱ�� ʹ��
//	}
//	cout << endl;
//
//	vec.reserve(100);//Ϊ������������С�Ĵ洢���ȣ���ҪʱΪ�����ռ䡣
//	cout << "ʹ����" << vec.size() << " ,���� " << vec.capacity() << endl;
//
//
//	return 0;
//}