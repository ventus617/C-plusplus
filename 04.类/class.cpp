#include<iostream>
using namespace std;
//����Ŀ�����ָһ�����ƿ������
//ʵ���ϣ�������û�����ݳ�Ա��û�к������࣬���� class Empty { };

//�� �����ݣ���Ա���ԣ�+�㷨����Ա������
//���� �����һ��ʵ��������ĸ�������������ڴ���

//������ һ���� ��C ��ͷ
//class ������Ĺؼ��� ����һ������ĸ������Ҫ����ռ�ÿռ䣬�൱������һ��class���͵ı����� 
// ���Ա�������η���Ĭ����˽�еģ�private�����������Ա����ʹ�õķ�Χ�����ʿ��ƣ�����Ȩ��
// private��ֻ�������ڳ�Ա��ʹ��
// protected������ �� ���� �п���ʹ��
// public����Լ�������κεط�ֻҪ�ܶ�����󣬶�����ʹ�ã����������ⶼ��ʹ�ã�
// 
// 
// 
// 
//��Ա��������Ա���ԣ�һ������m_��ͷ
//�������Ϊһ���ṹ�壬����Ƕ��Ӧ����
//����ʵ�ʶ������ʱ���Ż����ڴ濪�ٿռ�
class CPeople
{
//�����¼̳з������η���ֱ��������һ���������η�
public:
	string m_strName;
protected:
	int m_strAge;
private:
	bool m_sex;

public:
	//��Ա������������

	void show()
	{
		cout << "void show()" << endl;
		cout << "m_sex=" << m_sex << ",m_strAge=" << m_strAge << endl;
	}
	//������set�ӿ�
	void SetAge(int age)
	{
		m_strAge = age;
	}
	void SetSex(bool sex)
	{
		m_sex = sex;
	}	
	//������get�ӿ�
	int GetAge()
	{
		return m_strAge;
	}
	int GetSex()
	{
		return m_sex;
	}
	//--------------------------
	void Init()
	{
		m_strName = "С��";
		m_strAge = 21;
		m_sex = false;
	}
	//--------------------------
	/*
	
		��ʹ��һ�����ƿ����ж�����һ��Ĭ�ϵĺ��������캯��
		Ĭ�ϵĹ��캯��:������Ϊ��ǰ�������޲�����û�з���ֵ��������void �����û�з���ֵ�������������Ϊ�գ���δ��ʼ����ֵ
		�������ʱ,�Զ�ȥ���øú���,������ʼ�����Ա����
		���캯�����Զ�����൱�ں�������
		һ���ֶ��ع����κεĹ��캯�����������Ͳ����ṩĬ�ϵĹ��캯��


	*/
	CPeople()
	{
		cout << "Cpeople" << endl;
		m_strName = "С��";
		m_sex = false;
		m_strAge = 21;
	}
	CPeople(string name)//�������Ĺ��캯��
	{
		cout << "Cpeople" << endl;
		m_strName = name;
		m_sex = false;
		m_strAge = 21;
	}
};

int main02()
{
	CPeople peo;//���󣬲Ż����ڴ���ʵ���ٿռ�
	peo.m_strName = "ţ����";
	cout << peo.m_strName << endl;
	peo.SetAge (20);
	peo.SetSex (true);
	peo.show();

	cout << "GetAge==" << peo.GetAge() << endl;
	cout << "GetSex==" << peo.GetSex() << endl;


	CPeople peo3;
	peo3.m_strName = "ţ����";
	peo3.SetAge(20);
	peo3.SetSex(true);

	CPeople peo2;
	peo2.m_strName = "������";
	peo2.SetAge(20);
	peo2.SetSex(false);
	CPeople peo4;
	cout << peo4.m_strName << endl;
	cout << peo4.GetAge()<< endl;
	cout << peo4.GetSex() << endl;

	CPeople peo5;//�Զ����ô������Ĺ��캯��
	cout << peo5.m_strName << endl;
	cout << peo5.GetAge() << endl;
	cout << peo5.GetSex() << endl;

	return 0;
}