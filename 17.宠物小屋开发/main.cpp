
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
cout << "�����붯���������Ϣ(����,��ɫ,����)" << endl;\
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
	cout << "*********����С��**********" << endl;
	cout << "*" << CMD_BUY_CAT << ":��è  " << endl;
	cout << "*" << CMD_BUY_DOG << ":��  " << endl;
	cout << "*" << CMD_BUY_SNAKE << ":���� " << endl;
	cout << "*" << CMD_KILL_ANIMAL << ":ɱ��ĳ������  " << endl;
	cout << "*" << CMD_DESTORY_CAGE << ":����ĳ������  " << endl;
	cout << "*" << CMD_LOOK_ALL_ANIMAL << ":�鿴���������ж���  " << endl;
	cout << "*" << CMD_LOOK_ONE_ANIMAL << ":�鿴������ĳ������  " << endl;
	cout << "*" << CMD_SHOW_PEOPLE << ":չʾ������Ϣ  " << endl;
	cout << "*" << CMD_PLAY_ANIMAL << ":��ĳֻ������ˣ  " << endl;
	cout << "*" << CMD_QUIT << ":�˳�����  " << endl;
	cout << "*" << CMD_HELP << ":չʾ������Ϣ  " << endl;
	cout << "****************************" << endl;
}

int main()
{
	CPeople* pPeo = new CPeople;
	string name1 = "������";
	pPeo->InitPeople(name1, people_Money);//��ʼ����
	CHouse* pHouse = new CHouse;
	//---------------------------------------------
	show_help();
	
	string cmd = "";//�洢����������
	while (1)
	{
		

		getline(cin, cmd);//�Ի��з� \n Ϊ������־
		if (CMD_QUIT == cmd)
		{
			cout << "���򼴽��˳�" << endl;
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
				CCage* pCage = pPeo->CreateCage();//��������

				pPeo->PushAnimal(pCage, pAni);//��Ӷ��ﵽ������

				pPeo->PushCage(pHouse, pCage);//������ӵ�������
			}
		}

		if (CMD_KILL_ANIMAL == cmd)
		{
			int id = 0;
			cout << "������Ҫɱ���Ķ��������ID" << endl;
			cin >> id;
			pPeo->KillAnimal(pHouse, id);
		}
		if (CMD_DESTORY_CAGE == cmd)
		{
			int id = 0;
			cout << "������Ҫ���ٵ�����ID" << endl;
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
			cout << "Ҫ�鿴�Ķ��������ID" << endl;
			cin >> id;
			pPeo->LookAnimal(pHouse, id);
		}
		if (CMD_PLAY_ANIMAL == cmd)
		{
			int id = 0;
			cout << "Ҫ��ˣ�Ķ����ID" << endl;
			cin >> id;
			pPeo->PlayWithAnimal(pHouse, id);
		}
		if (CMD_SHOW_PEOPLE == cmd)
		{
			pPeo->ShowPeople();
		}
	}











	//----------------------------------------------



	//������Դ
	delete pHouse;
	pHouse = nullptr;
	delete pPeo;
	pPeo = nullptr;


	return 0;
}