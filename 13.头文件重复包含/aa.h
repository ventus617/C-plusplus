//
//#ifndef  __AA_H__
//#define  __AA_H__
//class CAA {
//public:
//	int m_a;
//	CAA();
//};
//
//#endif //  __AA_H__
//

/*

1.基于逻辑宏的判断
#ifndef  宏
#define  宏


    自己的有效代码


#endif //  宏
宏的名字可能会重复,会导致程序错误
基于逻辑宏的判断,当出现大量头文件时,编译速度会变慢


2. #pragma once

不会有重复的问题
*/

//告诉编译器，当前这个头文件在其他源文件中只包含一次
#pragma once

class CAA
{
public:
	int m_a;
	CAA();
};