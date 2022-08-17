#include<iostream>
using namespace std;


int add(int a, int b)
{
	return a + b;
}

#define ADD(a,b) ((a)+(b))

//inline 定义内联函数的关键字,既要保证安全 也要提高程序运行的效率
//编译阶段进行代码的替换
//内联函数适用于：代码量少，逻辑简单的，不适合for,while,switch,递归函数...等的复杂指令体系
//因为使用一次便会替换一次,多次使用就会占用很多空间,空间消耗大,用空间换时间
//inline：建议性关键字，决定权在于编译器，递归函数、虚函数 一定不是内联函数
inline int Add(int a, int b)
{
	return a + b;
}

int main()
{

	cout << add(10, 20) << endl; //慢 调用再返回

	cout << ADD(10, 20) << endl; //快 替换

	cout << Add(10, 20) << endl; //调用内联函数  省去函数调用的开销,并且相当于宏,增加了类型安全检查
	
	//过程相当于 把函数原封不动拿过来执行 不用再跳转

	//  Add(10, 20)-> a+b-> 10+20

	int* p = nullptr;
	//cout << Add(p, 20) << endl; //类型安全检查

	return 0;
}