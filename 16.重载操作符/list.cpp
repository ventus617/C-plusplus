#include<iostream>
#include<list>//1.����ͷ�ļ�
using namespace std;//2. �򿪱�׼�����ռ�

int main()
{
	list<int> lst;//����һ������ ÿ���ڵ�Ԫ����һ������

	lst.push_back(1); //β���
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	//������,���������� �����Ǳ������� ��������һ���� 
	list<int>::iterator  ite(lst.begin()); //begin() ��ȡͷ���ĵ�����
	ite = lst.begin();
	while (ite != lst.end())//end() �Ƿ���β���ĺ���
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;



	lst.push_front(0);//ͷ���
	ite = lst.begin();
	while (ite != lst.end())//end() �Ƿ��ص�list��ʶ��β��� �ĺ���
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;


	lst.push_back(5);
	lst.push_back(10);
	lst.pop_front();//��ͷջ
	lst.pop_back();//β��ջ
	for (int v : lst)//2.�ڶ��ֱ����ķ���,��ǿ��Χ��forѭ��
	{
		cout << v << " ";
	}
	cout << endl;

	//------------------------------------------------------
	//�ڵ�����ָ��Ľڵ��λ��ȥ����һ��Ԫ��,�²����Ԫ��λ������ǰ��,�ҷ��ص����²���Ľڵ������
	list<int>::iterator ite1=lst.insert(++lst.begin(), 10);
	cout << *ite1 << endl;//10
	for (int v : lst)//2.�ڶ��ֱ����ķ���,��ǿ��Χ��forѭ��
	{
		cout << v << " ";
	}
	cout << endl;

	//-------------------------------------------------------
	//������Ҫɾ���Ľڵ�ĵ�����,����ֵ��ɾ���ڵ����һ���ڵ�ĵ�����,�Դ�һ��ite++Ч��
	ite1 = ++lst.begin();
	list<int>::iterator ite2 = lst.erase(ite1);
	cout << *ite2 << endl;//2
	//cout << *ite1 << endl; //ָ��һ�������յĽڵ� �������� ����������ʧЧ
	for (int v : lst)//2.�ڶ��ֱ����ķ���,��ǿ��Χ��forѭ��
	{
		cout << v << " ";
	}
	cout << endl;





	ite1 = lst.begin();
	ite1 = lst.erase(ite1);
	cout << *ite1 << endl;
	for (int v : lst)//2.�ڶ��ֱ����ķ���,��ǿ��Χ��forѭ��
	{
		cout << v << " ";
	}
	cout << endl;

	//--------------------------------------------

	cout << *lst.begin() << " " << lst.front()<<" "<<lst.back() << endl;
	//cout << *lst.end() << endl;//���� end() ���ص�����Чβ�ڵ����һ����Ч��β�ڵ㣨β��ʶ�ڵ㣩
	cout << *(--lst.end()) << endl;//


	lst.push_back(2);
	lst.push_back(8);
	lst.push_back(6);
	cout << lst.size() << endl;//��������ĳ��� ��Ч����
	for (int v : lst)//2.�ڶ��ֱ����ķ���,��ǿ��Χ��forѭ��
	{
		cout << v << " ";
	}
	cout << endl;






	lst.clear(); //�������
	if (lst.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	cout << lst.size() << endl;
	return 0;
}