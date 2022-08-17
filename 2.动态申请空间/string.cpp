#include<iostream>
#include<string>//字符串头文件
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
	//数组的输出，在C++中可以不用for循环，直接把首地址带入即可
	cout << arr << endl;


	char* pstr = (char*)"5678";
	pstr = (char*)"efgh";
	cout << pstr << endl;
	//-------------------------------------------
	char arr1[5] = "abcd";
	if (strcmp(arr1,arr)==0)//判断两个字符串是否相等
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	//--------------------------------------------

	string str;//空字符串

	str = "abcd";
	//C++可直接修改,不用strcpy
	str = "efgh";
	str[1] = 'a';
	cout << str << endl;
	//---------拼接----------
	str += arr;
	str += pstr;
	str += "yuio";
	cout << str << endl;
	string str2 = string("123") + arr + "---" + pstr;
	cout << str2 << endl;
	//--------比较-----------
	char arr4[4] = "123";
	char arr5[4] = "123";
	str = arr4;
	str2 = arr5;
	if (str2 == str)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	//--------截取---------
	str = "12345678";
	string str3=str.substr(1, 4);//从哪个下标开始，截取多少个

	cout << str3 << endl;
	//------------------------------------
	str3 = str.substr(1, 40);
	//自动识别到'\0'然后停止，相当于返回有效长度
	cout << str3 << endl;
	/*
	str3 = str.substr(20, 4);
	cout << str3 << endl;
	下标越界 out_of_range,程序崩溃
	*/
	cout<<str.size()<<" "<<str.length()<<endl;
	//string 可以用char赋值 但是string赋值char必需通过str.c_str()转换
	//str.c_str(); 将string转换成const char*,通过返回值返回
	fun(str.c_str());
	return 0;
}