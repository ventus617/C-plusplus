#include<iostream>
using namespace std;

class CTest
{
public:
	int m_a;
	int* m_p;
	CTest()
	{
		m_a = 10;
		m_p = nullptr;
	}
	CTest(int a)
	{
		m_a = a;
		m_p = new int(a);
	}
	
	
	/*
	* 
	��ʹ��һ�����ƿ��������,����������Ĭ���ṩһ���������캯����������Ϊ��ǰ������������Ϊ��ǰ������ **����**
	��������벻Ϊ�գ��βζ����еĳ�Ա��this�����еĳ�Ա���ν��г�ʼ������
	

	һ���ֶ��ع��˿������캯��,�������Ͳ����ṩĬ�ϵ���
	��һ��ͬ���еĶ������һ��������г�ʼ������ʱ�����ÿ������캯�� CTest tst3(tst2);

	��һ�����ƿ���������ṩ��Ĭ�ϵĿ������캯����һ��ǳ����,���ܻ���ǳ���������⡣
	1.��һ������ͨ��ָ���޸���ָ��ռ��������ʱ����һ��������ʹ��ʱ,ʹ�õ����޸�֮���ֵ��
	2.�ڻ��տռ�ʱ��ͬһ���ڴ���ܱ��������Σ���ɷǷ����ʲ������Լ��Ŀռ䣨������һ��֮��Ͳ������Լ��ˣ�


	���ǳ�����취��1.���  2.����ǳ���� ����ں�������Ϊ�������ͣ��ṹ����ࣩ ������ָ������ô���
	*/


	//CTest(const CTest& tst):m_a(tst.m_a) //��ǰ���������� 
	//{
	//	cout << "CTest(const CTest& tst)" << endl;
	//}

		CTest(const CTest& tst):m_a(tst.m_a)/*,m_p(tst.m_p)*/ //��ǰ���������� 
	{
		cout << "CTest(const CTest& tst)" << endl;
		
		m_p = nullptr;
		if (tst.m_p)
		{
			this->m_p = new int(*tst.m_p);//��������һ���µ�m_pָ��Ŀռ�
		}
		
	}
	~CTest()
	{
		if (m_p)//�ж�ָ��
		{
			delete m_p;//���տռ�
			m_p = nullptr;
		}
	}

	//��ʹ�ڿ����ж���Ĭ���ṩһ�� operator= �ĺ���,����Ϊ��ǰ������*����*������ֵΪ��������ã���������벻Ϊ��

	//�βζ����еĳ�Ա��this�����еĳ�Ա���ν��и�ֵ;

	//һ���ֶ��ع��� operator= �ĺ������������Ͳ����ṩĬ�ϵ���,

	//��ͬ���е�һ���������һ��������и�ֵ������operator= ����
	//Ĭ�ϵ�operator= �ĺ��� Ҳ��һ��ǳ������Ҳ����ǳ��������������

	//CTest& operator=(const CTest& tst)//����CTest���� ������&����
	//{
	//	this->m_a = tst.m_a;
	//	this->m_p = tst.m_p;

	//	return *this;//����ָ��ָ��Ŀռ� �����õĿռ�

	//}



	//����취:���

	CTest& operator=(const CTest& tst)//����CTest���� ������&����
	{
		if (this != &tst)//�ж��ǲ����Լ�
		{

			this->m_a = tst.m_a;
			//this->m_p = tst.m_p;
			if (tst.m_p)
			{
				if (this->m_p)//�����Ͳ����������� ������Ϊ�ʼnew�ĳ��ȿ��ܲ�ͬ ������������newһ����ͬ��С�Ŀռ� �ٸ�ֵ
				{
					*this->m_p = *tst.m_p;
				}
				else
				{
					this->m_p = new int(*tst.m_p);
				}
			}
			else
			{
				if (this->m_p)
				{
					delete this->m_p;
					this->m_p = nullptr;
				}
				else
				{
					//��Ϊ�� û��Ҫ��ֵ����
				}
			}
			return *this;//����ָ��ָ��Ŀռ� �����õĿռ�
			//return (CTest&)tst;// ��ǿת ��Ϊ���ص�������CTest& ������const CTest&

			//�������·�����

			//const CTest& operator=(const CTest & tst)//����CTest���� ������&����
			//{
			//	if (this != &tst)//�ж��ǲ����Լ�
			//	{

			//		this->m_a = tst.m_a;
			//		//this->m_p = tst.m_p;
			//		if (tst.m_p)
			//		{
			//			if (this->m_p)//�����Ͳ����������� ������Ϊ�ʼnew�ĳ��ȿ��ܲ�ͬ ������������newһ����ͬ��С�Ŀռ� �ٸ�ֵ
			//			{
			//				*this->m_p = *tst.m_p;
			//			}
			//			else
			//			{
			//				this->m_p = new int(*tst.m_p);
			//			}
			//		}
			//		else
			//		{
			//			if (this->m_p)
			//			{
			//				delete this->m_p;
			//				this->m_p = nullptr;
			//			}
			//			else
			//			{
			//				//��Ϊ�� û��Ҫ��ֵ����
			//			}
			//		}
			//		return tst; //���������ͱ��const ��Ȼ������������Ҳ��Ĭ��const Ҳ����ʵ������ �������ز������ı����� CTest���͵�
		}
	}
};

//void fun(CTest &tst) //������ָ�� ���� ����
//{
//	cout << tst.m_a << " " << *tst.m_p << endl;
//}


int main()
{
	CTest tst;

	CTest tst2(10);
	
	tst2 = tst; //��ֵ 

	cout << tst2.m_a << endl;

	CTest tst3(30);
	CTest tst4;
	tst4 = tst3;
	cout << tst4.m_a << " " << *tst4.m_p << endl;


	{

	//CTest tst;

	//CTest tst2(20);

	//CTest tst3(tst2);
	//cout << tst3.m_a << endl;


	}
	
	//CTest tst2(20);

	//CTest tst3(tst2);
	//cout << tst3.m_a <<" " <<*tst3.m_p<< endl;

	//*tst2.m_p = 30;
	//cout << tst3.m_a << " " << *tst3.m_p << endl;

	{
		/*CTest tst2(20);

		CTest tst3(tst2);
		cout << tst3.m_a << " " << *tst3.m_p << endl;

		*tst2.m_p = 30;
		cout << tst3.m_a << " " << *tst3.m_p << endl;*/
	}
	{
		//CTest tst4(40);
		//fun(tst4);//����֮�� �βλᱻ���� �����β�֮�� ָ��ָ��Ŀռ䱻���� ���Գ������ �൱��ǳ����
		////��û���ʹ��ָ�루���յ����β�ָ�루�൱�ڻ���һ������ ����ĵ�ַ�� �ռ䣩 ���ǻ���ָ��Ŀռ䣩�������ã�������ڶ�ԭ�ռ���������������ᱻ����
	}
	

	return 0;

}

/*
	һ�����ƿ���Ŀ�����Ҳ�е� ��ЩĬ�ϵĺ�����4������
	//ʵ���ϵĿ�����û�����ݳ�Ա��û�к������࣬���� class Empty { };
	//

	Ĭ�ϵ��޲ι��캯��
	��������
	�������캯��
	Ĭ�ϵ�operator=



*/