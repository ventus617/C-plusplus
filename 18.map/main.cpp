#include<iostream>
#include<map>
using namespace std;

int main()
{
	//map ���Ը��ݼ�ֵ�����Զ�������,��ֵΨһ,map�� ÿ��Ԫ����һ����ֵ��,��pair��ʾ
	//ӳ���<��ֵ,ʵֵ>
	map<int, string> mm;

	//[��ֵ]=ʵֵ
	mm[1] = "11";//��ֵ������ʱ,�൱��������ݣ�����һ������
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

	mm[2] = "55";//��ֵ����ʱ,�����޸Ķ�Ӧ��ʵֵ,���¸�ֵ

	
	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;
	//1-11 2-55 3-33 4-44



	cout << "-----------------------------------------" << endl;


	ite=++mm.begin();
	ite=mm.erase(ite);//�Զ�++
	cout << ite->first << " " << ite->second << endl;
	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;


	cout << "-----------------------------------------" << endl;
	//------------------------------------------------------------
	//�ж�ĳ����ֵ�Ƿ����,�ɴ˲����޸�
	int a = mm.count(1);//�����ֵ1���� aΪ�� ��ֵ1������ aΪ��
	if (a)
	{
		cout << "����" << endl;
		mm[1] = "100";
	}
	else
	{
		cout << "������" << endl;
	}

	a = mm.count(10);
	if (a)
	{
		cout << "����" << endl;
		mm[10] = "100";
	}
	else
	{
		cout << "������" << endl;
	}

	for (pair<int, string> v : mm)
	{
		cout << v.first << "--" << v.second << "  ";
	}
	cout << endl;


	return 0;
}