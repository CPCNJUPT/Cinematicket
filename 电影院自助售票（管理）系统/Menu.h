#pragma once
/*菜单面板*/
#include<iostream>
#include"Sign.h"
#include"Film.h"
using namespace std;

//User p;

//菜单类
class Menu
{
public:
	//公用部分
	void main_Menu();             //主面板
	void register_Menu();         //注册面板
	void login_Menu();            //登录面板
	void help_Menu();             //系统帮助
	void exit_Menu();             //退出

	//用户权限部分
	void user_Menu();             //用户
	void user_buy_Menu();         //购票（用户）
	void user_collection_Menu();  //取票（用户）
	void user_refund_Menu();      //退票（用户）
	void user_history();          //历史购票记录

	//管理员权限部分
	void manager_Menu();          //管理员
	void manager_input_Menu();    //影片信息录入（管理员）
	void manager_output_Menu();   //影片信息显示（管理员）
	void manager_find_Menu();     //影片信息查询（管理员）
	void manager_update_Menu();   //影片信息修改（管理员）
	void manager_delate_Menu();   //影片信息删除（管理员）
	void manager_boxoffice();     //当日票房排序（管理员）
};

//主面板
void Menu::main_Menu()
{

	while (1)
	{
		system("cls");//清屏
		//cout << endl;
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃              1.用    户              ┃\t\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃              2.管 理 员              ┃\t\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃              3.系统帮助              ┃\t\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃              0.退    出              ┃\t\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << endl;
		int choice = -1;
		cout << "\t\t\t【系统提示】请输入你的选择项(0-3)：";
		cin >> choice;
		if (choice < -1 || choice>3)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:user_Menu(); break;//用户菜单调用
		case 2:manager_Menu(); break;//管理员菜单调用
		case 3:help_Menu(); break;//系统帮助调用
		case 0:exit_Menu(); break;//退出
		}
	}
}

//注册面板	
void Menu::register_Menu()
{
	system("cls");//清屏
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                注    册              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	p.Registers();//注册调用

}
//登录面板	
void Menu::login_Menu()
{
	system("cls");//清屏
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                登    录              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	p.Login();//登录调用
}

//系统帮助
void Menu::help_Menu()
{
	system("cls");
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                用户指南              ┃\t\n";
	cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	cout << "\t\t\t┃ 温馨提示：                           ┃\t\n";
	cout << "\t\t\t┃     为确保软件的正常运行，避免引起不 ┃\t\n";
	cout << "\t\t\t┃ 必要的崩溃，请用户严格按照系统提示进 ┃\t\n";
	cout << "\t\t\t┃ 行操作！                             ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃ 【管理员账号信息】                   ┃\t\n";
	cout << "\t\t\t┃ 初始管理员账号：18851187568          ┃\t\n";
	cout << "\t\t\t┃ 初始管理员密码：123456               ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << "\t\t\t【系统提示】返回（0）: ";
	int choose = -1;
	cin >> choose;
	if (choose > 0)
	{
		cout << "\t\t\t【系统提示】输入格式错误，请重新输入: ";
		cin >> choose;
	}
	switch (choose)
	{

	case 0:system("cls");
		main_Menu(); break;
	}
}

//退出
void Menu::exit_Menu()
{
	exit(0);
}

//用户
void Menu::user_Menu()
{
	system("cls");//清屏
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              1.登    录              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.注    册              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.返    回              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	int choice = -1;
	cout << "\t\t\t【系统提示】请输入你的选择项(0-2)：";
	cin >> choice;
	if (choice < -1 || choice>2)
	{
		cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:login_Menu(); //登录调用
		system("cls");//清屏
		break;//注册调用
	case 2:register_Menu(); //注册调用
		login_Menu(); //登录调用
		break;//登录调用
	case 0:main_Menu();
		break;//返回上一级
	}
	while (1)
	{
		system("cls");//清屏
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃                   1.购 票            ┃\t\n";
		cout << "\t\t\t┃                   2.取 票            ┃\t\n";
		cout << "\t\t\t┃                   3.退 票            ┃\t\n";
		cout << "\t\t\t┃                   4.历史购票         ┃\t\n";
		cout << "\t\t\t┃                   0.返回             ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << endl;
		int choice = -1;
		cout << "\t\t\t【系统提示】请输入你的选择项(0-4)：";
		cin >> choice;
		if (choice < -1 || choice>5)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:user_buy_Menu(); break;//购票菜单调用
		case 2:user_collection_Menu(); break;//取票菜单调用
		case 3:user_refund_Menu(); break;//退票菜单调用
		case4:user_history(); break;    //历史购票调用
		case 0:main_Menu(); break;//返回主菜单
		}
	}
}

//购票（用户）
void Menu::user_buy_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                购    票              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.sell();//购票调用
}

//取票（用户）
void Menu::user_collection_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                取    票              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.ticketout();//取票调用
}

//退票（用户）
void Menu::user_refund_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                退    票              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.refund();//退票调用
}
//历史购票（用户）
void Menu::user_history()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                购票历史              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.history();//购票历史调用
}

//管理员
void Menu::manager_Menu()
{
	system("cls");//清屏

	login_Menu();//登录调用
	int choice = -1;
	while (1)
	{
		system("cls");//清屏
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┃      1.录入影片     2.显示影片       ┃\t\n";
		cout << "\t\t\t┃      3.查找影片     4.修改影片       ┃\t\n";
		cout << "\t\t\t┃      5.删除影片     0.返    回       ┃\t\n";
		cout << "\t\t\t┃      6.今日票房排名                  ┃\t\n";
		cout << "\t\t\t┃                                      ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << endl;
		cout << "\t\t\t【系统提示】请输入你的选择（0-6）： ";
		cin >> choice;
		if (choice < 0 || choice>5)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:manager_input_Menu(); break;//输入菜单调用
		case 2:manager_output_Menu(); system("pause"); break;//显示菜单调用
		case 3:manager_find_Menu(); system("pause"); break;//查询菜单调用
		case 4:manager_update_Menu(); break;//修改菜单调用
		case 5:manager_delate_Menu(); break;//删除菜单调用
		case 6:manager_boxoffice(); break; //票房排名菜单调用
		case 0:main_Menu(); break;
		}
	}

}

//影片信息录入（管理员）
void Menu::manager_input_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                录    入              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	//cout << endl;
	tick.input();//输入调用
}

//影片信息显示（管理员）
void Menu::manager_output_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                显    示              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.show();
}

//影片信息查询（管理员）
void Menu::manager_find_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                查    询              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.search();//查询调用
}

//影片信息修改（管理员）
void Menu::manager_update_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                修    改              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.change();//修改调用
}

//影片信息删除（管理员）
void Menu::manager_delate_Menu()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                删    除              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.del();//删除调用
}
//当日票房排名（管理员）
void Menu::manager_boxoffice()
{
	system("cls");//清屏
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃                删    除              ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
	tick.rate();//排名调用
}