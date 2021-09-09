#pragma once
/*影片信息操作*/
#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include"Sign.h"
#include"Order.h"

using namespace std;
#pragma warning(disable : 4996)

#define N 100//可存电影总数  
User p;
UserData p1;

//电影信息结构体
struct node
{
	string name;//片名
	string type;//类型
	int min;//时长
	int year;//年
	int month;//月
	int day;//日
	int hour;//时
	int minute;//分
	int datetime[5];
	int num;//影厅
	float price;//价格
	float discount;//折扣
	int rest;//余位
	float seat[10][10];//座位信息
	string action;//状态
	float totalmoney=sum*discount;//总票款
	float sum;
};


//电影类
class ticket
{
private:
	node tic[N];
	int len;
public:
	ticket();
	~ticket();

	int sort(int i);
	void input();      //影片信息录入（管理员）
	void show();       //影片信息下显示（管理员）
	void search();     //影片信息查询（管理员）
	void change();     //影片信息修改（管理员）
	void del();        //影片信息删除（管理员）
	void sell();       //购票（用户）
	void refund();     //退票（用户）
	void save();       //影片信息保存（管理员）
	void read();       //影片信息读取（管理员）
	void sort1();      //日期比较（排序）
	void ctime();      //日期比较（判断影片播放状态）
	void ticketout();  //取票（用户）
	void history();    //查询购票历史（用户）
	void rate();        //票房排名函数
}tick;

ticket::ticket() {};
ticket::~ticket() {};

int timecmp(int a[], int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i] < b[i])
		{
			return -1;
		}
	}
	if (i == n)
	{
		return 0;
	}
}

//获取系统时间比较（判断影片播放状态）
void ticket::ctime()
{
	//获取系统时间与已输入时间进行比较
	time_t timep;
	struct tm* p;
	int in_time[5];
	int now_time[5];
	int i;

	for (i = 0; i < tick.len; i++)
	{
		//将输入时间依次赋值给输入时间数组
		in_time[0] = tick.tic[i].year;//输入时间-年
		in_time[1] = tick.tic[i].month;//输入时间-月
		in_time[2] = tick.tic[i].day;//输入时间-日
		in_time[3] = tick.tic[i].hour;//输入时间-时
		in_time[4] = tick.tic[i].minute;//输入时间-分

		time(&timep);
		p = gmtime(&timep);

		//将系统时间依次赋值给系统时间数组
		now_time[0] = 1900 + p->tm_year;//系统时间-年
		now_time[1] = 1 + p->tm_mon;//系统时间-月
		now_time[2] = p->tm_mday;//系统时间-日
		now_time[3] = 8 + p->tm_hour;//系统时间-时
		now_time[4] = p->tm_min;//系统时间-分

		//依次比较五项数据
		for (int x = 0; x < 5; x++)
		{
			if (in_time[x] > now_time[x])
			{
				tick.tic[i].action = "未播放";
				break;
			}
			else if (in_time[x] < now_time[x])
			{
				tick.tic[i].action = "已播放";
				break;
			}
		}
	}
}

//排序
void ticket::sort1()
{
	node var;
	//利用冒泡排序（升序），首先比较时间再比较日期

	//年月日+时间比较
	for (int i = 0; i < tick.len; i++)
	{
		for (int j = i + 1; j < tick.len; j++)
		{
			//比较分钟，j的分钟小于i的小时，利用冒泡排序交换i和j
			if (tick.tic[j].minute < tick.tic[i].minute)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]); 
			}
			//比较小时，j的小时小于i的小时，利用冒泡排序交换i和j
			if (tick.tic[j].hour < tick.tic[i].hour)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//比较日，j的日小于i的日，利用冒泡排序交换i和j
			if (tick.tic[j].day < tick.tic[i].day)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//比较月份，j的月份小于i的月份，利用冒泡排序交换i和j
			if (tick.tic[j].month < tick.tic[i].month)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//比较年份，j的年份小于i的年份，利用冒泡排序交换i和j	
			if (tick.tic[j].year < tick.tic[i].year)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
		}
	}
}

//保存
void ticket::save()
{
	ofstream ofile;
	ofile.open("影片数据.txt", ios::out);

	for (int i = 0; i < tick.len; i++)
	{
		ofile << endl << tick.tic[i].name << endl; //保存影片名
		ofile << tick.tic[i].type << endl;         //保存影片类型
		ofile << tick.tic[i].min << endl;          //保存影片时长
		ofile << tick.tic[i].year << endl;         //保存年
		ofile << tick.tic[i].month << endl;        //保存月份
		ofile << tick.tic[i].day << endl;          //保存日
		ofile << tick.tic[i].hour << endl;         //保存时
		ofile << tick.tic[i].minute << endl;       //保存分
		ofile << tick.tic[i].num << endl;          //保存场次
		ofile << tick.tic[i].price << endl;        //保存价格
		ofile << tick.tic[i].discount << endl;     //保存会员折扣
		ofile << tick.tic[i].rest << endl;         //保存余位

		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
			{
				ofile << tick.tic[i].seat[m][n] << endl;//保存座位信息
			}
		}
	}
	ofile.close();
}

//读取
void ticket::read()
{
	ifstream ifile;
	ifile.open("影片数据.txt", ios::in);

	tick.len = 0;

	if (!ifile.is_open())
	{
		//cout << "文件打开失败！" << endl;
		return;
	}

	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> tick.tic[i].name;
		ifile >> tick.tic[i].type;
		ifile >> tick.tic[i].min;
		ifile >> tick.tic[i].year;
		ifile >> tick.tic[i].month;
		ifile >> tick.tic[i].day;
		ifile >> tick.tic[i].hour;
		ifile >> tick.tic[i].minute;
		ifile >> tick.tic[i].num;
		ifile >> tick.tic[i].price;
		ifile >> tick.tic[i].discount;
		ifile >> tick.tic[i].rest;

		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
			{
				ifile >> tick.tic[i].seat[m][n];
			}
		}
		tick.len++;
	}
	tick.len--;
	ifile.close();
}

int ticket::sort(int i)
{
	int r, n, j;
	for (j = 0; j < i; j++)// 从首元素开始比较日期  
	{
		r = timecmp(tick.tic[i].datetime, tick.tic[j].datetime, 5);
		if (r == -1)// 找到第一个比他大的日期  , 插入其前面  
		{
			break;
		}
	}
	if (j == tick.len - 1)
	{
		return j;
	}
	if (j == i)
	{
		for (j = i + 1; j < tick.len; j++)// 从首元素开始比较日期  
		{
			r = timecmp(tick.tic[i].datetime, tick.tic[j].datetime, 5);
			if (r == -1)// 找到第一个比他大的日期  , 插入其前面  
			{
				break;
			}
		}
	}
	node temp = tick.tic[i];
	if (j < i)
	{
		for (n = i; n > j; n--)
		{
			tick.tic[n] = tick.tic[n - 1];
		}
		tick.tic[j] = temp;
		return j;
	}
	else
	{
		if (j == tick.len)
		{
			for (n = i; n < j - 1; n++)
			{
				tick.tic[n] = tick.tic[n + 1];
			}
		}
		else
		{
			for (n = i; n < j; n++)
			{
				tick.tic[n] = tick.tic[n + 1];
			}
		}
		tick.tic[n] = temp;
		return n;
	}
}

//录入信息（管理员）
void ticket::input()
{
	tick.read();
	char ch;// 接受日期中的字符"： " 
	for (int i = tick.len; i < N; i++)
	{
		cout << "\n【系统提示】影片名称：";
		cin >> tick.tic[i].name;

		cout << "\n【系统提示】影片类型（国语2D）：";
		cin >> tick.tic[i].type;

		cout << "\n【系统提示】影片时长（150）：";
		cin >> tick.tic[i].min;

		cout << "\n【系统提示】放映日期 (2011-11-11) ：";
		cin >> tick.tic[i].year >> ch >> tick.tic[i].month >> ch >> tick.tic[i].day;

		cout << "\n【系统提示】放映时间 (12:30) ：";
		cin >> tick.tic[i].hour;
		cin >> ch;
		cin >> tick.tic[i].minute;

		tick.tic[i].datetime[0] = tick.tic[i].year;
		tick.tic[i].datetime[1] = tick.tic[i].month;
		tick.tic[i].datetime[2] = tick.tic[i].day;
		tick.tic[i].datetime[3] = tick.tic[i].hour;
		tick.tic[i].datetime[4] = tick.tic[i].minute;

		cout << "\n【系统提示】放映影厅：";
		cin >> tick.tic[i].num;

		cout << "\n【系统提示】电影票价：";
		cin >> tick.tic[i].price;
		cout << "\n【系统提示】会员价：";
		cin >> tick.tic[i].discount;

		tick.tic[i].rest = 100;

		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
				tick.tic[i].seat[m][n] = 0;
		}

		tick.len++;// 个数加1
		if (i != 0)// 按时间 , 插入排序  
		{
			int j = sort(i);
		}

		tick.save();
		cout << endl;
		cout << "【系统提示】是否继续录入(Y/N)：";
		while (1)
		{
			cin >> ch;
			if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
				break;
			else
				cout << "【系统提示】输入格式错误，请重新输入：";
		}
		if (ch == 'n' || ch == 'N')
		{
			break;
		}
	}
}

//显示信息（管理员）
void ticket::show()
{
	tick.read();
	tick.sort1();
	int i = 0;
	tick.ctime();//调用时间比较函数

	cout << "【系统提示】所有电影信息如下：" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
		<< setw(9) << setiosflags(ios::left) << "|  类型"
		<< setw(10) << setiosflags(ios::left) << "|   时长"
		<< setw(13) << setiosflags(ios::left) << "|  放映日期"
		<< setw(11) << setiosflags(ios::left) << "| 放映时间"
		<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
		<< setw(7) << setiosflags(ios::left) << "| 票价"
		<< setw(9) << setiosflags(ios::left) << "| 会员价"
		<< setw(7) << setiosflags(ios::left) << "| 余票"
		<< setw(100) << setiosflags(ios::left) << "|电影票款"
		<< setw(9) << setiosflags(ios::left) << "|  状态" << "|" << endl;

	for (i = 0; i < tick.len; i++)
	{
		cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
			<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
			<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
			<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
			<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
			<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
			<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
			<< " " << setw(100) << setiosflags(ios::left) << tick.tic[i].totalmoney << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
		
	}
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	//setiosflags(ios::left) 居左对其（配合头文件#include <iomanip>使用）
	//setw(10) 如果输出内容不足10，自动补齐空格（制表用，配合头文件#include <iomanip>使用）
}

//影片信息查询（管理员）
void ticket::search()
{
	tick.read();//影片信息读取
	tick.ctime();//时间比较调用
	int i;
	int k = 0;//标记找到的次数  
	string na;

	cout << "【系统提示】请输入影片名：";
	cin >> na;
	cout << endl;

	if (tick.len == 0)
	{
		cout << "【系统提示】信息为空！";
	}
	else
	{
		cout << "【系统提示】查询结果如下：" << endl;
		cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
		cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
			<< setw(9) << setiosflags(ios::left) << "|  类型"
			<< setw(10) << setiosflags(ios::left) << "|   时长"
			<< setw(13) << setiosflags(ios::left) << "|  放映日期"
			<< setw(11) << setiosflags(ios::left) << "| 放映时间"
			<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
			<< setw(7) << setiosflags(ios::left) << "| 票价"
			<< setw(9) << setiosflags(ios::left) << "| 会员价"
			<< setw(7) << setiosflags(ios::left) << "| 余票"
			<< setw(100) << setiosflags(ios::left) << "|电影票款"
			<< setw(9) << setiosflags(ios::left) << "|  状态" << "|" << endl;
		cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
		for (i = 0; i < tick.len; i++)
		{
			if (tick.tic[i].name == na)// 找到  
			{
				k++;// 找到的记录数  

				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
					<< " " << setw(100) << setiosflags(ios::left) << tick.tic[i].totalmoney << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
				cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
			}
		}
	}
	if (k == 0)
	{
		cout << endl;
		cout << "【系统提示】未查询到相关信息，查询失败！" << endl;
	}

}
//影片信息修改（管理员）
void ticket::change()
{
	tick.read();//影片信息读取
	string name;
	int i;
	int j = 0;// 标记修改数量  

	cout << "【系统提示】请输入影片名称：";
	cin >> name;
	cout << endl;
	cout << "【系统提示】查询结果如下：" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
		<< setw(9) << setiosflags(ios::left) << "|  类型"
		<< setw(10) << setiosflags(ios::left) << "|   时长"
		<< setw(13) << setiosflags(ios::left) << "|  放映日期"
		<< setw(11) << setiosflags(ios::left) << "| 放映时间"
		<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
		<< setw(7) << setiosflags(ios::left) << "| 票价"
		<< setw(9) << setiosflags(ios::left) << "| 会员价"
		<< setw(7) << setiosflags(ios::left) << "| 余票"
		<< setw(9) << setiosflags(ios::left) << "|  状态" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == name)// 找到  
		{
			j++;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
			cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
			char a;
			int choice = -1;

			cout << endl;
			cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << "\t\t\t┃                                      ┃\t\n";
			cout << "\t\t\t┃   1.修改影片名称   2.修改影片类型    ┃\t\n";
			cout << "\t\t\t┃   3.修改影片时长   4.修改放映日期    ┃\t\n";
			cout << "\t\t\t┃   5.修改放映时间   6.修改放映影厅    ┃\t\n";
			cout << "\t\t\t┃   7.修改影片票价   8.修改会员票价    ┃\t\n";
			cout << "\t\t\t┃                                      ┃\t\n";
			cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			cout << endl;
			cout << "\t\t\t【系统提示】请输入你的选择（0-7）：";
			cin >> choice;

			if (choice < 0 || choice>7)
			{
				cout << "\t\t\t【系统提示】输入格式错误，请重新输入：" << endl;
				cin >> choice;
			}
			char ch;
			switch (choice)
			{
			case 1:cout << "\n【系统提示】影片名称：";
				cin >> tick.tic[i].name;
				break;
			case 2:cout << "\n【系统提示】影片类型（国语2D）：";
				cin >> tick.tic[i].type;
				break;
			case 3:cout << "\n【系统提示】影片时长：";
				cin >> tick.tic[i].min;
				break;
			case 4:cout << "\n【系统提示】放映日期（2020-11-11）：";
				cin >> tick.tic[i].year >> ch >> tick.tic[i].month >> ch >> tick.tic[i].day;
				tick.tic[i].datetime[0] = tick.tic[i].year;
				tick.tic[i].datetime[1] = tick.tic[i].month;
				tick.tic[i].datetime[2] = tick.tic[i].day; i = sort(i);
				break;
			case 5:cout << "\n【系统提示】放映时间（12:15）：";
				cin >> tick.tic[i].hour >> ch >> tick.tic[i].minute;
				tick.tic[i].datetime[3] = tick.tic[i].hour;
				tick.tic[i].datetime[4] = tick.tic[i].minute; i = sort(i);
				break;
			case 6:cout << "\n【系统提示】放映影厅：";
				cin >> tick.tic[i].num;
				break;
			case 7:cout << "\n【系统提示】票价：";
				cin >> tick.tic[i].price;
				break;
			case 8:cout << "\n【系统提示】会员价：";
				cin >> tick.tic[i].discount;
				break;
			case 0:break;
			}
			tick.save();//影片信息保存调用
			cout << endl << "【系统提示】是否继续修改此影片(Y/N): ";
			cin >> a;

			if (a != 'N' && a != 'n');
			{
				cout << endl;
				cout << "【系统提示】影片信息修改成功！" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
					<< setw(9) << setiosflags(ios::left) << "|  类型"
					<< setw(10) << setiosflags(ios::left) << "|   时长"
					<< setw(13) << setiosflags(ios::left) << "|  放映日期"
					<< setw(11) << setiosflags(ios::left) << "| 放映时间"
					<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
					<< setw(7) << setiosflags(ios::left) << "| 票价"
					<< setw(9) << setiosflags(ios::left) << "| 会员价"
					<< setw(7) << setiosflags(ios::left) << "| 余票" << "|" << endl;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
			}
		}
	}
	if (i == tick.len && j == 0)
	{
		cout << "【系统提示】未查询到相关信息,查询失败！" << endl;
	}
	system("pause");// 任意键继续
}

//删除影片
void ticket::del()
{
	tick.read();//影片信息读取
	string name;
	int i;
	int j = 0;// 标记删除的数量  
	cout << "【系统提示】请输入影片名称：";
	cin >> name;
	cout << endl;
	cout << "【系统提示】查询结果如下：" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
		<< setw(9) << setiosflags(ios::left) << "|  类型"
		<< setw(10) << setiosflags(ios::left) << "|   时长"
		<< setw(13) << setiosflags(ios::left) << "|  放映日期"
		<< setw(11) << setiosflags(ios::left) << "| 放映时间"
		<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
		<< setw(7) << setiosflags(ios::left) << "| 票价"
		<< setw(9) << setiosflags(ios::left) << "| 会员价"
		<< setw(7) << setiosflags(ios::left) << "| 余票"
		<< setw(9) << setiosflags(ios::left) << "|  状态" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;

	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == name)// 找到
		{
			j++;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
			cout << " ----------------------------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "【系统提示】是否删除影片 " << endl;
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃     1.确  认     2.取  消   ┃\t\n";
			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			int choose = 0;
			cout << "【系统提示】请输入你的选择：";
			cin >> choose;
			switch (choose)
			{
			case 1:
				for (int j = i + 1; j < tick.len; j++)
				{
					tick.tic[j - 1] = tick.tic[j];
				}
				cout << endl << "【系统提示】删除成功！" << endl;
				tick.len--;
				tick.save();
				break;
			case 2:tick.del(); break;
			}
		}
	}
	if (i == tick.len && j == 0)
	{
		cout << "【系统提示】未查询到相关信息，删除失败！" << endl;
	}
	system("pause");// 任意键继续  
}

//售票
void ticket::sell()
{
	tick.read();//影片信息读取
	tick.sort1();//排序调用
	//获取系统时间与已输入时间进行比较
	time_t timep;
	struct tm* p;
	int in_time[5];
	int now_time[5];
	int i;
	int k = 0;// 标记可供预定的影片数量 

	cout << "【系统提示】可预订的电影信息如下：" << endl;
	cout << " -------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
		<< setw(9) << setiosflags(ios::left) << "|  类型"
		<< setw(10) << setiosflags(ios::left) << "|   时长"
		<< setw(13) << setiosflags(ios::left) << "|  放映日期"
		<< setw(11) << setiosflags(ios::left) << "| 放映时间"
		<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
		<< setw(7) << setiosflags(ios::left) << "| 票价"
		<< setw(9) << setiosflags(ios::left) << "| 会员价"
		<< setw(7) << setiosflags(ios::left) << "| 余票" << "|" << endl;
	
	for (i = 0; i < tick.len; i++)
	{
		//将输入时间依次赋值给输入时间数组
		in_time[0] = tick.tic[i].year;//输入时间-年
		in_time[1] = tick.tic[i].month;//输入时间-月
		in_time[2] = tick.tic[i].day;//输入时间-日
		in_time[3] = tick.tic[i].hour;//输入时间-时
		in_time[4] = tick.tic[i].minute;//输入时间-分

		time(&timep);
		p = gmtime(&timep);

		//将系统时间依次赋值给系统时间数组
		now_time[0] = 1900 + p->tm_year;//系统时间-年
		now_time[1] = 1 + p->tm_mon;//系统时间-月
		now_time[2] = p->tm_mday;//系统时间-日
		now_time[3] = 8 + p->tm_hour;//系统时间-时
		now_time[4] = p->tm_min;//系统时间-分

		//依次比较五项数据
		for (int x = 0; x < 5; x++)
		{
			if (in_time[x] > now_time[x])
			{
				k++;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|" << endl;
				
				break;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
			}
			
			if (in_time[x] < now_time[x])
			{
				break;
			}
		}
		
	}
	cout << " -------------------------------------------------------------------------------------------------- " << endl;
	if (tick.len == 0 || k == 0)
	{
		cout << "【系统提示】暂无可供预定的影片！" << endl;
		return;
		system("pause");// 任意键继续
	}
	system("pause");// 任意键继续

	string na;
	cout << endl << "【系统提示】请输入要预订的影片名：";
	cin >> na;
	k = 0;// 再次做标记
	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == na)// 找到  
		{
			k++;// 找到的记录数  
			int j = 1;
			if (j == 1)
			{
				cout << "【系统提示】查找结果如下：" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
					<< setw(9) << setiosflags(ios::left) << "|  类型"
					<< setw(10) << setiosflags(ios::left) << "|   时长"
					<< setw(13) << setiosflags(ios::left) << "|  放映日期"
					<< setw(11) << setiosflags(ios::left) << "| 放映时间"
					<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
					<< setw(7) << setiosflags(ios::left) << "| 票价"
					<< setw(9) << setiosflags(ios::left) << "| 会员价"
					<< setw(7) << setiosflags(ios::left) << "| 余票" << "|" << endl;
			}
			j++;
			cout << "|--------------------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|" << endl;
			cout << " -------------------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "【系统提示】影片《" << na << "》当前预订情况(■表示已预定，□表示未预定）" << endl;
			cout << "【系统提示】" << tick.tic[i].num << "号厅座位示意图";
			cout << endl;
			for (int m = 0; m < 10; m++)
			{
				cout << endl;
				for (int n = 0; n < 10; n++)
				{
					if (tick.tic[i].seat[m][n] != 0)
					{

						cout << " ■";
					}
					else
					{
						cout << " □";
					}
				}
			}
			cout << endl;
			cout << endl;
			cout << "【系统提示】请输入预订的座位号（1-100）：";
			int seatnum;
			cin >> seatnum;
			if (seatnum > 100 || seatnum < 1)
			{
				cout << endl << "【系统提示】对不起，无此座位！";
				system("pause");// 任意键继续  
				return;
			}
			int m, n;
			m = (seatnum - 1) / 10;//座位号取个位-1
			n = (seatnum - 1) % 10;//座位号取十位-1
			if (tick.tic[i].seat[m][n] == 0 && tick.tic[i].rest != 0)
			{
				cout << "【系统提示】是否以会员权限购买(Y/N)：";
				char a;
				int price;
				cin >> a;
				if (a != 'N' && a != 'n')
				{
					//原价购买
					tick.tic[i].seat[m][n] = tick.tic[i].price;
				}
				else
				{
					//会员价购买
					tick.tic[i].seat[m][n] = tick.tic[i].discount;
				}
				tick.tic[i].rest--;//余位减一
				tick.tic[i].sum++;

				string ph;
				cout << "【系统提示】请输入预定手机号：";
				cin >> ph;
				//将订单信息保存至文件

				ud.read();//订单信息读取
				for (int x = scount1; x < scount1 + 1; x++)
				{
					userdata[x].phone = ph;
					userdata[x].name = na;
					userdata[x].type = tick.tic[i].type;
					userdata[x].min = tick.tic[i].min;
					userdata[x].year = tick.tic[i].year;
					userdata[x].month = tick.tic[i].month;
					userdata[x].day = tick.tic[i].day;
					userdata[x].hour = tick.tic[i].hour;
					userdata[x].minute = tick.tic[i].minute;
					userdata[x].num = tick.tic[i].num;
					userdata[x].seat = seatnum;
					userdata[x].price = tick.tic[i].seat[m][n];
					scount1++;
					ud.save();//订单信息保存
					break;
				}

				cout << endl;
				cout << "【系统提示】订单信息确认： " << endl;
				cout << " ---------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
					<< setw(9) << setiosflags(ios::left) << "|  类型"
					<< setw(10) << setiosflags(ios::left) << "|   时长"
					<< setw(13) << setiosflags(ios::left) << "|  放映日期"
					<< setw(11) << setiosflags(ios::left) << "| 放映时间"
					<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
					<< setw(10) << setiosflags(ios::left) << "|  座位号"
					<< setw(9) << setiosflags(ios::left) << "| 需支付" << "|" << endl;
				cout << "|----------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
					<< " " << setw(2) << setiosflags(ios::left) << seatnum / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seatnum % 10 << "号" << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].seat[m][n] << "|" << endl;
				cout << " ---------------------------------------------------------------------------------------------- " << endl;
				cout << endl;
				cout << "【系统提示】" << tick.tic[i].num << "号厅座位示意图";
				cout << endl;
				for (int m = 0; m < 10; m++)
				{
					cout << endl;
					for (int n = 0; n < 10; n++)
					{
						if (tick.tic[i].seat[m][n] != 0)
						{

							cout << " ■";
						}
						else
						{
							cout << " □";
						}
					}
				}
				cout << endl;
				cout << endl;
				cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
				cout << "┃     1.确  认     2.取  消   ┃\t\n";
				cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
				int choose = 0;
				cout << "【系统提示】请输入你的选择：";
				cin >> choose;
				switch (choose)
				{
				case 1:cout << endl << "【系统提示】预订成功！" << endl;;
					tick.save();
					cout << "【系统提示】用户" << ph << "订单信息： " << endl;
					cout << " ------------------------------------------------------------------------------------- " << endl;
					cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
						<< setw(9) << setiosflags(ios::left) << "|  类型"
						<< setw(10) << setiosflags(ios::left) << "|   时长"
						<< setw(13) << setiosflags(ios::left) << "|  放映日期"
						<< setw(11) << setiosflags(ios::left) << "| 放映时间"
						<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
						<< setw(10) << setiosflags(ios::left) << "|  座位号" << "|" << endl;
					cout << "|-------------------------------------------------------------------------------------|" << endl;
					cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
						<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
						<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
						<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
						<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
						<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
						<< " " << setw(2) << setiosflags(ios::left) << seatnum / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seatnum % 10 << "号" << "|" << endl;
					cout << " ------------------------------------------------------------------------------------- " << endl;
					system("pause");// 任意键继续 
					break;
				case 2:tick.sell(); break;
				}
				return;
			}
			else
			{
				if (tick.tic[i].rest == 0)
				{
					cout << endl << "【系统提示】余票不足，已售罄！";
					cout << endl;
					system("pause");// 任意键继续  
					return;
				}
				else if (tick.tic[i].seat[m][n] != 0)
				{
					cout << endl << "【系统提示】此座位已被预订！";
					cout << endl;
					system("pause");// 任意键继续  
					return;
				}
			}
		}
	}
	if (i == tick.len && k == 0)
	{
		cout << "【系统提示】没有找到您要预定的电影！" << endl;
		system("pause");// 任意键继续  
		return;
	}
}

//取票
void ticket::ticketout()
{
	p1.read();//订单信息读取
	string ph;
	int k = 0;//标记匹配次数
	cout << "【系统提示】请输入预定手机号：";
	cin >> ph;
	
	for (int i = 0; i < scount1+1; i++)
	{
		
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << endl;
			cout << "【系统提示】用户" << ph << "的订单信息： " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
				<< setw(9) << setiosflags(ios::left) << "|  类型"
				<< setw(10) << setiosflags(ios::left) << "|   时长"
				<< setw(13) << setiosflags(ios::left) << "|  放映日期"
				<< setw(11) << setiosflags(ios::left) << "| 放映时间"
				<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
				<< setw(10) << setiosflags(ios::left) << "|  座位号" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seat % 10 << "号" << "|" << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "【系统提示】是否打印订单信息 " << endl;
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃     1.确  认     2.取  消   ┃\t\n";
			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			int choose = 0;
			cout << "【系统提示】请输入你的选择：";
			cin >> choose;
			switch (choose)
			{
			case 1:cout << "【系统提示】打印成功！ " << endl;
				system("pause");// 任意键继续 
				break;
			case 2:tick.ticketout(); break;
			}
		}
	}
	if (k == 0)
	{
		cout << "【系统提示】未查询到订单信息" << endl;
		system("pause");// 任意键继续 
	}
}


//退票
void ticket::refund()
{
	p1.read();//订单信息读取
	string ph;
	int k = 0;//标记匹配次数
	int j = 0;
	int choice = 0;
	cout << "【系统提示】请输入预定手机号：";
	cin >> ph;
	cout << endl;
	for (int i = 0; i < scount1; i++)
	{
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << "【系统提示】用户" << ph << "订单信息： " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
				<< setw(9) << setiosflags(ios::left) << "|  类型"
				<< setw(10) << setiosflags(ios::left) << "|   时长"
				<< setw(13) << setiosflags(ios::left) << "|  放映日期"
				<< setw(11) << setiosflags(ios::left) << "| 放映时间"
				<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
				<< setw(10) << setiosflags(ios::left) << "|  座位号" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seat % 10 << "号" << "|" << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "【系统提示】是否退订当前影票 " << endl;
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃     1.确  认     2.取  消   ┃\t\n";
			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
			int choose = 0;
			cout << "【系统提示】请输入你的选择：";
			cin >> choose;
			switch (choose)
			{
			case 1://获取系统时间与已输入时间进行比较
				time_t timep;
				struct tm* p;
				int in_time[5];
				int now_time[5];

				//将输入时间依次赋值给输入时间数组
				in_time[0] = userdata[i].year;//输入时间-年
				in_time[1] = userdata[i].month;//输入时间-月
				in_time[2] = userdata[i].day;//输入时间-日
				in_time[3] = userdata[i].hour;//输入时间-时
				in_time[4] = userdata[i].minute;//输入时间-分

				time(&timep);
				p = gmtime(&timep);

				//将系统时间依次赋值给系统时间数组
				now_time[0] = 1900 + p->tm_year;//系统时间-年
				now_time[1] = 1 + p->tm_mon;//系统时间-月
				now_time[2] = p->tm_mday;//系统时间-日
				now_time[3] = 8 + p->tm_hour;//系统时间-时
				now_time[4] = p->tm_min;//系统时间-分

				//依次比较五项数据

				for (int x = 0; x < 5; x++)
				{
					if (in_time[x] > now_time[x])
					{
						j++;
						cout << endl;
						cout << "【系统提示】订单信息确认： " << endl;
						cout << " ---------------------------------------------------------------------------------------------- " << endl;
						cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
							<< setw(9) << setiosflags(ios::left) << "|  类型"
							<< setw(10) << setiosflags(ios::left) << "|   时长"
							<< setw(13) << setiosflags(ios::left) << "|  放映日期"
							<< setw(11) << setiosflags(ios::left) << "| 放映时间"
							<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
							<< setw(10) << setiosflags(ios::left) << "|  座位号"
							<< setw(9) << setiosflags(ios::left) << "| 返 还" << "|" << endl;
						cout << "|----------------------------------------------------------------------------------------------|" << endl;
						cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
							<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
							<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
							<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
							<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
							<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
							<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seat % 10 << "号" << "|"
							<< " " << setw(7) << setiosflags(ios::left) << userdata[i].price << "|" << endl;
						cout << " ---------------------------------------------------------------------------------------------- " << endl;
						cout << endl;
						break;
					}
					if (in_time[x] < now_time[x])
					{
						break;
					}
				}
				cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
				cout << "┃     1.确  认     2.取  消   ┃\t\n";
				cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
				cout << "【系统提示】请输入你的选择：";
				cin >> choice;
				switch (choice)
				{
				case 1:for (i = 0; i < scount1; i++)
				{
					if (userdata[i].phone == ph)// 找到
					{
						j++;
						for (int j = i + 1; j < scount1; j++)
						{
							userdata[j - 1] = userdata[j];
						}
						int m, n;
						m = (seat - 1) / 10;//座位号取个位-1
						n = (seat - 1) % 10;//座位号取十位-1
						/*int m = seat / 10;
						int n = seat % 10;*/
						
						tick.tic[i].seat[m][n] = 0;
						tick.tic[i].rest++;
						tick.tic[i].sum--;
						tick.save();
						cout << "【系统提示】退票成功！" << endl;
						system("pause");//清屏
						scount1--;
						ud.save();
					}
				}
			    break;
				case 2:tick.refund(); break;
				}
				if (j == 0)
				{
					cout << "【系统提示】影片已播放，无法退票！ " << endl;
				}
				break;
			case 2:tick.refund(); break;
			}
		}
	}
	if (k == 0)
	{
		cout << "【系统提示】未查询到相关信息 " << endl;
		system("pause");//清屏
	}
}
//查询购票历史记录
void ticket::history()
{
	p1.read();//订单信息读取
	string ph;
	int k = 0;//标记匹配次数
	int j = 0;
	int choice = 0;
	cout << "【系统提示】请再次输入预定手机号：";
	cin >> ph;
	cout << endl;
	for (int i = 0; i < scount1; i++)
	{
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << "【系统提示】用户" << ph << "订单信息： " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       影片名称"
				<< setw(9) << setiosflags(ios::left) << "|  类型"
				<< setw(10) << setiosflags(ios::left) << "|   时长"
				<< setw(13) << setiosflags(ios::left) << "|  放映日期"
				<< setw(11) << setiosflags(ios::left) << "| 放映时间"
				<< setw(11) << setiosflags(ios::left) << "| 放映影厅"
				<< setw(10) << setiosflags(ios::left) << "|  座位号" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "分钟" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "号厅" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "排" << setw(2) << setiosflags(ios::left) << seat % 10 << "号" << "|" << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
		}
	}
}
void ticket::rate()
{   
	node var;
	for (int i = 0; i < tick.len; i++)
	{
		for (int j = i + 1; j < tick.len; j++)
		{
			if (tick.tic[j].totalmoney > tick.tic[i].totalmoney)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
			}
		}
	}
	for (int i = 0; i < tick.len; i++)
	{
		cout << i << '.' << tick.tic[i].name       << tick.tic[i].totalmoney<<endl;
	}
}