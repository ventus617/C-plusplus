#include<iostream>
using namespace std;

class CHand
{
public:
	void Move()
	{
		cout << "Wave Wave Wave" << endl;
	}
};


class Ccomputer
{
public:
	void Compile()
	{
		cout << "programming to make files" << endl;
	}
};

class CFriend
{
public:
	void playing()
	{
		cout << "my friends are playing games" << endl;
	}
};





class Cpeople
{
public:
	CHand m_hand;
	CFriend* m_f;
public:
	Cpeople()
	{
		m_f = nullptr;
	}
	~Cpeople()
	{

	}
	void Clap()//����
	{
		m_hand.Move();
		cout << "Clap Clap Clap" << endl;
	}

	void Coding(Ccomputer* pcom)//���� ��������ʹ��
	{
		if (pcom == nullptr) return;
		m_hand.Move();
		cout << "programming programming programming" << endl;
		pcom->Compile();
		cout << "it works" << endl;
	}
	void PlayG()
	{
		if (m_f)//������
		{
			cout << "I am ready to play games" << endl;
			m_f->playing();
		}
		else
		{
			cout << "I play games alone" << endl;
		}
	}
};

class CFamily
{
public:
	Cpeople* m_family[10];
	CFamily()
	{
		for (Cpeople* (&p1) : m_family)
			//�ı�ֵ������
			//�����Ƕ�ָ�����͵����� ��ʾ����ָ���m_family�ռ�������� ��ָ�������
		{
			p1 = nullptr;
		}
		m_family[0] = new Cpeople;
		m_family[1] = new Cpeople;
		m_family[2] = new Cpeople;
	}
	~CFamily()
	{
		for (Cpeople* p1 : m_family)
			//���Բ������� �ҵ�p1ָ��ľ���m_family��new����ָ��Ŀռ�,��&���൱��m_famliy��ָ��
			//����&���൱��p1��ָ��,��ָ���Ǹ�new�����Ŀռ�,ɾ˭������
		{
			if (p1)
			{
				delete p1;
				p1 = nullptr;
			}
		}
	}
public:
	void ALLCoding(Ccomputer* pcom)
	{
		for (Cpeople* p1 : m_family)
		{
			if (p1) p1->Coding(pcom);
		}
	}
};


int main()
{
	{
		//��� Chand �� Cpeople 
		Cpeople sts1;
		sts1.Clap();
	}
	cout << "-----------" << endl;
	{  
		//���� Cpeople �� Ccomputer
		Cpeople sts2;
		Ccomputer* p = new Ccomputer;
		sts2.Coding(p);

		delete p;
		p = nullptr;
	}
	cout << "-----------" << endl;
	{
		//���� Cpeople �� CFriend

		Cpeople sts;
		sts.PlayG();

		CFriend fri;//����
		sts.m_f = &fri;
		sts.PlayG();
	}
	cout << "-----------" << endl;
	{
		//�ۺ� Cpeople �� CFamily
		CFamily fam;
		Ccomputer* p = new Ccomputer;
		fam.ALLCoding(p);

		delete p;
		p = nullptr;
	}
	return 0;
}