

#include<iostream>
using namespace std;
/*
	解耦 使得改动一个地方 使用的地方不用去修改代码 减少耦合度

	耦合度 改动一个地方 使用的地方 甚至是全局也得去修改 增加代码工程量

*/

//-----------------------物件-------------------------------

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
		cout << "2.0 自然吸气的发动机正在工作" << endl;
	}
};

class CEngine2T:public CEngine
{
public:
	void working()
	{
		cout << "2.0 涡轮增压的发动机正在工作" << endl;
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
		cout << "自动变速箱正在工厂" << endl;
	}
};

class CGearBoxManual :public CGearBox
{
public:
	void working()
	{
		cout << "手动变速箱正在工作" << endl;
	}
};




//-----------------------工厂-------------------------------

//------------------------简单工厂--------------------------
//弊端：加了东西 得增加if else

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

//-------------------------工厂方法-----------------------------

//工厂方法模式 拆分 减少耦合度 但是增加了代码量
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



//具体工厂
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






//------------------------抽象工厂--------------------------------
//将一堆零件东西组合起来的工厂

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



//------------------------车------------------------------

class CCar
{
public:
	CEngine* m_pEngine;//组合关系 被组合对象是在组合对象创建的同时或者之后创建的，在组合对象销毁之前销毁 因此满足组合关系 而不是依赖
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



	//以下情况 耦合很严重 修改了一个地方 使用也得去修改 适合比较固定且种类较少的对象（违背开闭原则）
	//-------------------------------简单工厂模式---------------------------------------------
	//CCar(CFactoryEngine* pFac,string type) //如果仅使用引擎
	//{
	//	if (pFac)
	//	{
	//		m_pEngine=pFac->CreateEngine(type);
	//	}
	//	else
	//	{
	//		m_pEngine = nullptr;
	//	}

	//--------------------工厂方法 修改一个地方 使用的地方不用去修改----------------------------------


	//遵循开闭原则  需要就添加 但是种类很多的时候 会增加大量的工厂 过于浪费空间
	CCar(CFactoryEngine1* pFac, CFacrotyGearBox* pFac2)//利用父类指针可以指向子类对象 调用父类函数 由于是纯虚函数 被子类重写
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






	//-------------------抽象工厂----------------------------------
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
			cout << "我的车正在行驶" << endl;
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