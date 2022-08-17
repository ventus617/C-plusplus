
#include<iostream>
using namespace std;
#include"CPeople.h"
#include"config.h"
#include"CCat.h"
#include"CDog.h"
#include"CSnake.h"
#include<Windows.h>

#define BUY_ANIMAL(ANI_CLASS,ANI_KIND)\
 pAni = new ANI_CLASS;\
cout << "请输入动物的属性信息(名字,颜色,年龄)" << endl;\
cin >> name;\
cin >> color;\
cin >> age;\
pAni->InitAnimal(name, color, age);\
if (!pPeo->BuyAnimal(pAni, ANI_KIND))\
{\
	delete pAni;\
	pAni = nullptr;\
}\
pPeo->ShowPeople();


void show_help()
{
	cout << "*********宠物小屋**********" << endl;
	cout << "*" << CMD_BUY_CAT << ":买猫  " << endl;
	cout << "*" << CMD_BUY_DOG << ":买狗  " << endl;
	cout << "*" << CMD_BUY_SNAKE << ":买蛇 " << endl;
	cout << "*" << CMD_KILL_ANIMAL << ":杀死某个动物  " << endl;
	cout << "*" << CMD_DESTORY_CAGE << ":销毁某个笼子  " << endl;
	cout << "*" << CMD_LOOK_ALL_ANIMAL << ":查看房子里所有动物  " << endl;
	cout << "*" << CMD_LOOK_ONE_ANIMAL << ":查看房子里某个动物  " << endl;
	cout << "*" << CMD_SHOW_PEOPLE << ":展示人物信息  " << endl;
	cout << "*" << CMD_PLAY_ANIMAL << ":和某只动物玩耍  " << endl;
	cout << "*" << CMD_QUIT << ":退出程序  " << endl;
	cout << "*" << CMD_HELP << ":展示命令信息  " << endl;
	cout << "****************************" << endl;
}

int main()
{
	CPeople* pPeo = new CPeople;
	string name1 = "马西西";
	pPeo->InitPeople(name1, people_Money);//初始化人
	CHouse* pHouse = new CHouse;
	//---------------------------------------------
	show_help();
	
	string cmd = "";//存储操作的命名
	while (1)
	{
		

		getline(cin, cmd);//以换行符 \n 为结束标志
		if (CMD_QUIT == cmd)
		{
			cout << "程序即将退出" << endl;
			Sleep(2000);
			break;
		}
		if (CMD_HELP == cmd)
		{
			show_help();
		}

		{
			CAnimal* pAni = nullptr;
			string name = "";
			string color = "";
			int age = 0;

			if (CMD_BUY_CAT == cmd)
			{
				BUY_ANIMAL(CCat, Ani_cat)
			}
			if (CMD_BUY_DOG == cmd)
			{
				BUY_ANIMAL(CDog, Ani_dog)
			}
			if (CMD_BUY_SNAKE == cmd)
			{
				BUY_ANIMAL(CSnake, Ani_snake)
			}
			if (pAni)
			{
				CCage* pCage = pPeo->CreateCage();//建造笼子

				pPeo->PushAnimal(pCage, pAni);//添加动物到笼子里

				pPeo->PushCage(pHouse, pCage);//添加笼子到房子里
			}
		}

		if (CMD_KILL_ANIMAL == cmd)
		{
			int id = 0;
			cout << "请输入要杀死的动物的笼子ID" << endl;
			cin >> id;
			pPeo->KillAnimal(pHouse, id);
		}
		if (CMD_DESTORY_CAGE == cmd)
		{
			int id = 0;
			cout << "请输入要销毁的笼子ID" << endl;
			cin >> id;
			pPeo->DestoryCage(pHouse, id);
		}
		if (CMD_LOOK_ALL_ANIMAL == cmd)
		{
			pPeo->LookAnimal(pHouse);
		}
		if (CMD_LOOK_ONE_ANIMAL == cmd)
		{
			int id = 0;
			cout << "要查看的动物的笼子ID" << endl;
			cin >> id;
			pPeo->LookAnimal(pHouse, id);
		}
		if (CMD_PLAY_ANIMAL == cmd)
		{
			int id = 0;
			cout << "要玩耍的动物的ID" << endl;
			cin >> id;
			pPeo->PlayWithAnimal(pHouse, id);
		}
		if (CMD_SHOW_PEOPLE == cmd)
		{
			pPeo->ShowPeople();
		}
	}











	//----------------------------------------------



	//回收资源
	delete pHouse;
	pHouse = nullptr;
	delete pPeo;
	pPeo = nullptr;


	return 0;
}