#include<iostream>
#include<string>//�ַ���ͷ�ļ�
using namespace std;

void fun(const char* p1)
{
	cout << p1 << endl;
}

int main()
{
	char arr[5] = "1234";
	arr[0] = 'a';
	arr[1] = 'b';

	strcpy_s(arr,5, "abcd");
	//������������C++�п��Բ���forѭ����ֱ�Ӱ��׵�ַ���뼴��
	cout << arr << endl;


	char* pstr = (char*)"5678";
	pstr = (char*)"efgh";
	cout << pstr << endl;
	//-------------------------------------------
	char arr1[5] = "abcd";
	if (strcmp(arr1,arr)==0)//�ж������ַ����Ƿ����
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
	//--------------------------------------------

	string str;//���ַ���

	str = "abcd";
	//C++��ֱ���޸�,����strcpy
	str = "efgh";
	str[1] = 'a';
	cout << str << endl;
	//---------ƴ��----------
	str += arr;
	str += pstr;
	str += "yuio";
	cout << str << endl;
	string str2 = string("123") + arr + "---" + pstr;
	cout << str2 << endl;
	//--------�Ƚ�-----------
	char arr4[4] = "123";
	char arr5[4] = "123";
	str = arr4;
	str2 = arr5;
	if (str2 == str)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}

	//--------��ȡ---------
	str = "12345678";
	string str3=str.substr(1, 4);//���ĸ��±꿪ʼ����ȡ���ٸ�

	cout << str3 << endl;
	//------------------------------------
	str3 = str.substr(1, 40);
	//�Զ�ʶ��'\0'Ȼ��ֹͣ���൱�ڷ�����Ч����
	cout << str3 << endl;
	/*
	str3 = str.substr(20, 4);
	cout << str3 << endl;
	�±�Խ�� out_of_range,�������
	*/
	cout<<str.size()<<" "<<str.length()<<endl;
	//string ������char��ֵ ����string��ֵchar����ͨ��str.c_str()ת��
	//str.c_str(); ��stringת����const char*,ͨ������ֵ����
	fun(str.c_str());
	return 0;
}