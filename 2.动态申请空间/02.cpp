#include<iostream>
using namespace std;

void fun(int)
{

}
int main02()
{
    //new 整形的指针 
    //返回指针的地址
    int** p1 = new int*;
    delete p1;
    p1 = NULL;
    //返回的是int*的地址 根据多级嵌套，所以需要二级指针指向



    //整形数组指针
    //由C可知，由高级指针（*）来指向整个单行地址
    int(**p3)[5] = new (int(*)[5]);
    //指向的类型即 int(*)[5] 的基础上再加上一个* 即int(**)[5]
    delete p3;
    p3 = NULL;


    //利用typedef优化数组指针
    typedef int(*P_ARR)[5];
    P_ARR* p33 = new P_ARR;
    delete p33;
    p33 = NULL;





    //函数指针,做法类似于
    //void fun(int)是函数-->void (int)-->void (*)(int)-->(void (*)(int))
    void (**p5)(int) = new (void (*)(int));
    delete p5;
    p5 = NULL;

    //----------------------------数组-----------------------------------




    //一维数组,直接返回一个首元素地址
    int* p6 = new int[2];
    delete[]p6;
    p6 = NULL;





    //多维数组,返回二维数组的首地址
    //其实是指向行，也就是第一个大行，内覆盖了列元素
    //由C可知，由高级指针（*）来指向整个单行地址
    int(*p4)[3] = new int[2][3];
    delete[]p4;
    p4 = NULL;






    //整形指针数组
    int** p2 = new int* [5];
    delete[]p2;
    p2 = NULL;
    //返回的是int*[0]的地址 根据多级嵌套，所以同理需要二级指针指向






    return 0;
}