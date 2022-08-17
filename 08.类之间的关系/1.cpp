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
	void Clap()//拍手
	{
		m_hand.Move();
		cout << "Clap Clap Clap" << endl;
	}

	void Coding(Ccomputer* pcom)//依赖 有它才能使用
	{
		if (pcom == nullptr) return;
		m_hand.Move();
		cout << "programming programming programming" << endl;
		pcom->Compile();
		cout << "it works" << endl;
	}
	void PlayG()
	{
		if (m_f)//有朋友
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
			//改变值用引用
			//引用是对指针类型的引用 表示是所指向的m_family空间的重命名 是指针的引用
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
			//可以不用引用 我的p1指向的就是m_family中new出来指向的空间,加&就相当于m_famliy的指针
			//不加&就相当于p1的指针,都指向那个new出来的空间,删谁都可以
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
		//组合 Chand 和 Cpeople 
		Cpeople sts1;
		sts1.Clap();
	}
	cout << "-----------" << endl;
	{  
		//依赖 Cpeople 和 Ccomputer
		Cpeople sts2;
		Ccomputer* p = new Ccomputer;
		sts2.Coding(p);

		delete p;
		p = nullptr;
	}
	cout << "-----------" << endl;
	{
		//关联 Cpeople 和 CFriend

		Cpeople sts;
		sts.PlayG();

		CFriend fri;//朋友
		sts.m_f = &fri;
		sts.PlayG();
	}
	cout << "-----------" << endl;
	{
		//聚合 Cpeople 和 CFamily
		CFamily fam;
		Ccomputer* p = new Ccomputer;
		fam.ALLCoding(p);

		delete p;
		p = nullptr;
	}
	return 0;
}