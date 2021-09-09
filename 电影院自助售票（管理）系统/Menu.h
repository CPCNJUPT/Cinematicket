#pragma once
/*�˵����*/
#include<iostream>
#include"Sign.h"
#include"Film.h"
using namespace std;

//User p;

//�˵���
class Menu
{
public:
	//���ò���
	void main_Menu();             //�����
	void register_Menu();         //ע�����
	void login_Menu();            //��¼���
	void help_Menu();             //ϵͳ����
	void exit_Menu();             //�˳�

	//�û�Ȩ�޲���
	void user_Menu();             //�û�
	void user_buy_Menu();         //��Ʊ���û���
	void user_collection_Menu();  //ȡƱ���û���
	void user_refund_Menu();      //��Ʊ���û���
	void user_history();          //��ʷ��Ʊ��¼

	//����ԱȨ�޲���
	void manager_Menu();          //����Ա
	void manager_input_Menu();    //ӰƬ��Ϣ¼�루����Ա��
	void manager_output_Menu();   //ӰƬ��Ϣ��ʾ������Ա��
	void manager_find_Menu();     //ӰƬ��Ϣ��ѯ������Ա��
	void manager_update_Menu();   //ӰƬ��Ϣ�޸ģ�����Ա��
	void manager_delate_Menu();   //ӰƬ��Ϣɾ��������Ա��
	void manager_boxoffice();     //����Ʊ�����򣨹���Ա��
};

//�����
void Menu::main_Menu()
{

	while (1)
	{
		system("cls");//����
		//cout << endl;
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��              1.��    ��              ��\t\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��              2.�� �� Ա              ��\t\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��              3.ϵͳ����              ��\t\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��              0.��    ��              ��\t\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << endl;
		int choice = -1;
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0-3)��";
		cin >> choice;
		if (choice < -1 || choice>3)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:user_Menu(); break;//�û��˵�����
		case 2:manager_Menu(); break;//����Ա�˵�����
		case 3:help_Menu(); break;//ϵͳ��������
		case 0:exit_Menu(); break;//�˳�
		}
	}
}

//ע�����	
void Menu::register_Menu()
{
	system("cls");//����
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ע    ��              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	p.Registers();//ע�����

}
//��¼���	
void Menu::login_Menu()
{
	system("cls");//����
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    ¼              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	p.Login();//��¼����
}

//ϵͳ����
void Menu::help_Menu()
{
	system("cls");
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                �û�ָ��              ��\t\n";
	cout << "\t\t\t�ǩ�����������������������������������������������������������������������������\n";
	cout << "\t\t\t�� ��ܰ��ʾ��                           ��\t\n";
	cout << "\t\t\t��     Ϊȷ��������������У��������� ��\t\n";
	cout << "\t\t\t�� ��Ҫ�ı��������û��ϸ���ϵͳ��ʾ�� ��\t\n";
	cout << "\t\t\t�� �в�����                             ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t�� ������Ա�˺���Ϣ��                   ��\t\n";
	cout << "\t\t\t�� ��ʼ����Ա�˺ţ�18851187568          ��\t\n";
	cout << "\t\t\t�� ��ʼ����Ա���룺123456               ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��ϵͳ��ʾ�����أ�0��: ";
	int choose = -1;
	cin >> choose;
	if (choose > 0)
	{
		cout << "\t\t\t��ϵͳ��ʾ�������ʽ��������������: ";
		cin >> choose;
	}
	switch (choose)
	{

	case 0:system("cls");
		main_Menu(); break;
	}
}

//�˳�
void Menu::exit_Menu()
{
	exit(0);
}

//�û�
void Menu::user_Menu()
{
	system("cls");//����
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              1.��    ¼              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              2.ע    ��              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              0.��    ��              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	int choice = -1;
	cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0-2)��";
	cin >> choice;
	if (choice < -1 || choice>2)
	{
		cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:login_Menu(); //��¼����
		system("cls");//����
		break;//ע�����
	case 2:register_Menu(); //ע�����
		login_Menu(); //��¼����
		break;//��¼����
	case 0:main_Menu();
		break;//������һ��
	}
	while (1)
	{
		system("cls");//����
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��                   1.�� Ʊ            ��\t\n";
		cout << "\t\t\t��                   2.ȡ Ʊ            ��\t\n";
		cout << "\t\t\t��                   3.�� Ʊ            ��\t\n";
		cout << "\t\t\t��                   4.��ʷ��Ʊ         ��\t\n";
		cout << "\t\t\t��                   0.����             ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << endl;
		int choice = -1;
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0-4)��";
		cin >> choice;
		if (choice < -1 || choice>5)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:user_buy_Menu(); break;//��Ʊ�˵�����
		case 2:user_collection_Menu(); break;//ȡƱ�˵�����
		case 3:user_refund_Menu(); break;//��Ʊ�˵�����
		case4:user_history(); break;    //��ʷ��Ʊ����
		case 0:main_Menu(); break;//�������˵�
		}
	}
}

//��Ʊ���û���
void Menu::user_buy_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    Ʊ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.sell();//��Ʊ����
}

//ȡƱ���û���
void Menu::user_collection_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ȡ    Ʊ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.ticketout();//ȡƱ����
}

//��Ʊ���û���
void Menu::user_refund_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    Ʊ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.refund();//��Ʊ����
}
//��ʷ��Ʊ���û���
void Menu::user_history()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��Ʊ��ʷ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.history();//��Ʊ��ʷ����
}

//����Ա
void Menu::manager_Menu()
{
	system("cls");//����

	login_Menu();//��¼����
	int choice = -1;
	while (1)
	{
		system("cls");//����
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��      1.¼��ӰƬ     2.��ʾӰƬ       ��\t\n";
		cout << "\t\t\t��      3.����ӰƬ     4.�޸�ӰƬ       ��\t\n";
		cout << "\t\t\t��      5.ɾ��ӰƬ     0.��    ��       ��\t\n";
		cout << "\t\t\t��      6.����Ʊ������                  ��\t\n";
		cout << "\t\t\t��                                      ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << endl;
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��0-6���� ";
		cin >> choice;
		if (choice < 0 || choice>5)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:manager_input_Menu(); break;//����˵�����
		case 2:manager_output_Menu(); system("pause"); break;//��ʾ�˵�����
		case 3:manager_find_Menu(); system("pause"); break;//��ѯ�˵�����
		case 4:manager_update_Menu(); break;//�޸Ĳ˵�����
		case 5:manager_delate_Menu(); break;//ɾ���˵�����
		case 6:manager_boxoffice(); break; //Ʊ�������˵�����
		case 0:main_Menu(); break;
		}
	}

}

//ӰƬ��Ϣ¼�루����Ա��
void Menu::manager_input_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ¼    ��              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	//cout << endl;
	tick.input();//�������
}

//ӰƬ��Ϣ��ʾ������Ա��
void Menu::manager_output_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    ʾ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.show();
}

//ӰƬ��Ϣ��ѯ������Ա��
void Menu::manager_find_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    ѯ              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.search();//��ѯ����
}

//ӰƬ��Ϣ�޸ģ�����Ա��
void Menu::manager_update_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ��    ��              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.change();//�޸ĵ���
}

//ӰƬ��Ϣɾ��������Ա��
void Menu::manager_delate_Menu()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ɾ    ��              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.del();//ɾ������
}
//����Ʊ������������Ա��
void Menu::manager_boxoffice()
{
	system("cls");//����
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��                ɾ    ��              ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
	tick.rate();//��������
}