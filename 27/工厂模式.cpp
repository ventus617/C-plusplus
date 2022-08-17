

#include<iostream>
using namespace std;
/*
	���� ʹ�øĶ�һ���ط� ʹ�õĵط�����ȥ�޸Ĵ��� ������϶�

	��϶� �Ķ�һ���ط� ʹ�õĵط� ������ȫ��Ҳ��ȥ�޸� ���Ӵ��빤����

*/

//-----------------------���-------------------------------

class CEngine 
{
public:
	virtual void working() = 0;

};

class CEngine2L:public CEngine
{
public:
	void working()
	{
		cout << "2.0 ��Ȼ�����ķ��������ڹ���" << endl;
	}
};

class CEngine2T:public CEngine
{
public:
	void working()
	{
		cout << "2.0 ������ѹ�ķ��������ڹ���" << endl;
	}
};

class CGearBox
{
public:
	virtual void working() = 0;
};

class CGearBoxaoto :public CGearBox
{
public:
	void working()
	{
		cout << "�Զ����������ڹ���" << endl;
	}
};

class CGearBoxManual :public CGearBox
{
public:
	void working()
	{
		cout << "�ֶ����������ڹ���" << endl;
	}
};




//-----------------------����-------------------------------

//------------------------�򵥹���--------------------------
//�׶ˣ����˶��� ������if else

class CFactoryEngine
{
public:
	CEngine* CreateEngine(string type)
	{
		if (type == "2.0L")
		{
			return new CEngine2L;
		}
		else if (type == "2.0T")
		{
			return new CEngine2T;
		}
		return nullptr;

	}
};

//-------------------------��������-----------------------------

//��������ģʽ ��� ������϶� ���������˴�����
class CFactoryEngine1
{
public:
	virtual CEngine* CreateEngine() = 0;
};

class CFacrotyGearBox
{
public: 
	virtual CGearBox* CreateGearBox() = 0;
};



//���幤��
class CFactoryEngine2L:public CFactoryEngine1
{
public:
	CEngine* CreateEngine()
	{
		return new CEngine2L;
	}
};

class CFactoryEngine2T :public CFactoryEngine1
{
public:
	CEngine* CreateEngine()
	{
		return new CEngine2T;
	}
};

class CFactoryGearBoxAuto :public CFacrotyGearBox
{
public:
	virtual CGearBox* CreateGearBox()
	{
		return new CGearBoxaoto;
	}
};

class CFactoryGearBoxManual :public CFacrotyGearBox
{
public:
	virtual CGearBox* CreateGearBox()
	{
		return new CGearBoxManual;
	}
};






//------------------------���󹤳�--------------------------------
//��һ�����������������Ĺ���

//2.0T aotu
class CFactory
{
public:
	virtual CGearBox* CreateGearBox() = 0;
	virtual CEngine* CreateEngine() = 0;
};

class CFactory2LAuto :public CFactory
{
	virtual CGearBox* CreateGearBox()
	{
		return new CGearBoxaoto;
	}
	virtual CEngine* CreateEngine()
	{
		return new CEngine2L;
	}
};



//------------------------��------------------------------

class CCar
{
public:
	CEngine* m_pEngine;//��Ϲ�ϵ ����϶���������϶��󴴽���ͬʱ����֮�󴴽��ģ�����϶�������֮ǰ���� ���������Ϲ�ϵ ����������
	CGearBox* m_pGearBox;
public:

	
	/*CCar()
	{
		m_pEngine = new CEngine2L;
	}
	CCar(CEngine* pEngine)
	{
		if (pEngine)
		{
			m_pEngine = pEngine;
		}
		else
		{
			m_pEngine = nullptr;
		}
	}*/



	//������� ��Ϻ����� �޸���һ���ط� ʹ��Ҳ��ȥ�޸� �ʺϱȽϹ̶���������ٵĶ���Υ������ԭ��
	//-------------------------------�򵥹���ģʽ---------------------------------------------
	//CCar(CFactoryEngine* pFac,string type) //�����ʹ������
	//{
	//	if (pFac)
	//	{
	//		m_pEngine=pFac->CreateEngine(type);
	//	}
	//	else
	//	{
	//		m_pEngine = nullptr;
	//	}

	//--------------------�������� �޸�һ���ط� ʹ�õĵط�����ȥ�޸�----------------------------------


	//��ѭ����ԭ��  ��Ҫ����� ��������ܶ��ʱ�� �����Ӵ����Ĺ��� �����˷ѿռ�
	CCar(CFactoryEngine1* pFac, CFacrotyGearBox* pFac2)//���ø���ָ�����ָ��������� ���ø��ຯ�� �����Ǵ��麯�� ��������д
	{
		if (pFac&&pFac2)
		{
			m_pEngine = pFac->CreateEngine();
			m_pGearBox = pFac2->CreateGearBox();
		}
		else
		{
			m_pGearBox = nullptr;
			m_pEngine = nullptr;
		}
	}






	//-------------------���󹤳�----------------------------------
	CCar(CFactory* pFac)
	{
		if (pFac)
		{
			m_pEngine=pFac->CreateEngine();
			m_pGearBox=pFac->CreateGearBox();
		}
		else
		{

			m_pEngine = nullptr;
			m_pGearBox = nullptr;
		}
	}

	//-------------------------------------------------------------

	~CCar()
	{
		if (m_pEngine)
		{
			delete m_pEngine;
			m_pEngine = nullptr;
		}
		if (m_pGearBox)
		{
			delete m_pGearBox;
			m_pGearBox = nullptr;
		}
	}
public:
	void drive()
	{
		if (m_pEngine&& m_pGearBox)
		{
			m_pGearBox->working();
			m_pEngine->working();
			cout << "�ҵĳ�������ʻ" << endl;
		}
	}

};







int main()
{
	//CCar auti;
	//auti.drive();
	//
	//CCar benzi(new CEngine2T);
	//benzi.drive();

	////-----------------------------------------------

	//CFactoryEngine* pFac = new CFactoryEngine;


	//CCar bmw1(pFac, "2.0L");
	//bmw1.drive();


	//CCar bmw2(pFac, "2.0T");
	//bmw2.drive();

	//delete pFac;
	//pFac = nullptr;



	//-----------------------------------------------
	//CFactoryEngine1* pFac2L = new CFactoryEngine2L;
	//CFactoryEngine1* pFac2T = new CFactoryEngine2T;
	//CCar audi(pFac2L);
	//audi.drive();

	//CCar bmw(pFac2T);
	//bmw.drive();




	////-----------------------------------------------
	//delete pFac2L;
	//delete pFac2T;
	//pFac2L = nullptr;
	//pFac2T = nullptr;

	//-------------------------------------------------

	CFactoryEngine1* pFac1 = new CFactoryEngine2T;
	CFacrotyGearBox* pFac2 = new CFactoryGearBoxAuto;
	CCar bmw(pFac1, pFac2);
	bmw.drive();


	CFactory* pFac = new CFactory2LAuto;
	CCar audi(pFac);
	audi.drive();


	return 0;
}