#include<iostream>
using namespace std;

void fun(int)
{

}
int main02()
{
    //new ���ε�ָ�� 
    //����ָ��ĵ�ַ
    int** p1 = new int*;
    delete p1;
    p1 = NULL;
    //���ص���int*�ĵ�ַ ���ݶ༶Ƕ�ף�������Ҫ����ָ��ָ��



    //��������ָ��
    //��C��֪���ɸ߼�ָ�루*����ָ���������е�ַ
    int(**p3)[5] = new (int(*)[5]);
    //ָ������ͼ� int(*)[5] �Ļ������ټ���һ��* ��int(**)[5]
    delete p3;
    p3 = NULL;


    //����typedef�Ż�����ָ��
    typedef int(*P_ARR)[5];
    P_ARR* p33 = new P_ARR;
    delete p33;
    p33 = NULL;





    //����ָ��,����������
    //void fun(int)�Ǻ���-->void (int)-->void (*)(int)-->(void (*)(int))
    void (**p5)(int) = new (void (*)(int));
    delete p5;
    p5 = NULL;

    //----------------------------����-----------------------------------




    //һά����,ֱ�ӷ���һ����Ԫ�ص�ַ
    int* p6 = new int[2];
    delete[]p6;
    p6 = NULL;





    //��ά����,���ض�ά������׵�ַ
    //��ʵ��ָ���У�Ҳ���ǵ�һ�����У��ڸ�������Ԫ��
    //��C��֪���ɸ߼�ָ�루*����ָ���������е�ַ
    int(*p4)[3] = new int[2][3];
    delete[]p4;
    p4 = NULL;






    //����ָ������
    int** p2 = new int* [5];
    delete[]p2;
    p2 = NULL;
    //���ص���int*[0]�ĵ�ַ ���ݶ༶Ƕ�ף�����ͬ����Ҫ����ָ��ָ��






    return 0;
}