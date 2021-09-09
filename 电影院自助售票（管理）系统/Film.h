#pragma once
/*ӰƬ��Ϣ����*/
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

#define N 100//�ɴ��Ӱ����  
User p;
UserData p1;

//��Ӱ��Ϣ�ṹ��
struct node
{
	string name;//Ƭ��
	string type;//����
	int min;//ʱ��
	int year;//��
	int month;//��
	int day;//��
	int hour;//ʱ
	int minute;//��
	int datetime[5];
	int num;//Ӱ��
	float price;//�۸�
	float discount;//�ۿ�
	int rest;//��λ
	float seat[10][10];//��λ��Ϣ
	string action;//״̬
	float totalmoney=sum*discount;//��Ʊ��
	float sum;
};


//��Ӱ��
class ticket
{
private:
	node tic[N];
	int len;
public:
	ticket();
	~ticket();

	int sort(int i);
	void input();      //ӰƬ��Ϣ¼�루����Ա��
	void show();       //ӰƬ��Ϣ����ʾ������Ա��
	void search();     //ӰƬ��Ϣ��ѯ������Ա��
	void change();     //ӰƬ��Ϣ�޸ģ�����Ա��
	void del();        //ӰƬ��Ϣɾ��������Ա��
	void sell();       //��Ʊ���û���
	void refund();     //��Ʊ���û���
	void save();       //ӰƬ��Ϣ���棨����Ա��
	void read();       //ӰƬ��Ϣ��ȡ������Ա��
	void sort1();      //���ڱȽϣ�����
	void ctime();      //���ڱȽϣ��ж�ӰƬ����״̬��
	void ticketout();  //ȡƱ���û���
	void history();    //��ѯ��Ʊ��ʷ���û���
	void rate();        //Ʊ����������
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

//��ȡϵͳʱ��Ƚϣ��ж�ӰƬ����״̬��
void ticket::ctime()
{
	//��ȡϵͳʱ����������ʱ����бȽ�
	time_t timep;
	struct tm* p;
	int in_time[5];
	int now_time[5];
	int i;

	for (i = 0; i < tick.len; i++)
	{
		//������ʱ�����θ�ֵ������ʱ������
		in_time[0] = tick.tic[i].year;//����ʱ��-��
		in_time[1] = tick.tic[i].month;//����ʱ��-��
		in_time[2] = tick.tic[i].day;//����ʱ��-��
		in_time[3] = tick.tic[i].hour;//����ʱ��-ʱ
		in_time[4] = tick.tic[i].minute;//����ʱ��-��

		time(&timep);
		p = gmtime(&timep);

		//��ϵͳʱ�����θ�ֵ��ϵͳʱ������
		now_time[0] = 1900 + p->tm_year;//ϵͳʱ��-��
		now_time[1] = 1 + p->tm_mon;//ϵͳʱ��-��
		now_time[2] = p->tm_mday;//ϵͳʱ��-��
		now_time[3] = 8 + p->tm_hour;//ϵͳʱ��-ʱ
		now_time[4] = p->tm_min;//ϵͳʱ��-��

		//���αȽ���������
		for (int x = 0; x < 5; x++)
		{
			if (in_time[x] > now_time[x])
			{
				tick.tic[i].action = "δ����";
				break;
			}
			else if (in_time[x] < now_time[x])
			{
				tick.tic[i].action = "�Ѳ���";
				break;
			}
		}
	}
}

//����
void ticket::sort1()
{
	node var;
	//����ð���������򣩣����ȱȽ�ʱ���ٱȽ�����

	//������+ʱ��Ƚ�
	for (int i = 0; i < tick.len; i++)
	{
		for (int j = i + 1; j < tick.len; j++)
		{
			//�ȽϷ��ӣ�j�ķ���С��i��Сʱ������ð�����򽻻�i��j
			if (tick.tic[j].minute < tick.tic[i].minute)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]); 
			}
			//�Ƚ�Сʱ��j��СʱС��i��Сʱ������ð�����򽻻�i��j
			if (tick.tic[j].hour < tick.tic[i].hour)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//�Ƚ��գ�j����С��i���գ�����ð�����򽻻�i��j
			if (tick.tic[j].day < tick.tic[i].day)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//�Ƚ��·ݣ�j���·�С��i���·ݣ�����ð�����򽻻�i��j
			if (tick.tic[j].month < tick.tic[i].month)
			{
				var = tick.tic[i];
				tick.tic[i] = tick.tic[j];
				tick.tic[j] = var;
				//swap(tick.tic[j], tick.tic[i]);
			}
			//�Ƚ���ݣ�j�����С��i����ݣ�����ð�����򽻻�i��j	
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

//����
void ticket::save()
{
	ofstream ofile;
	ofile.open("ӰƬ����.txt", ios::out);

	for (int i = 0; i < tick.len; i++)
	{
		ofile << endl << tick.tic[i].name << endl; //����ӰƬ��
		ofile << tick.tic[i].type << endl;         //����ӰƬ����
		ofile << tick.tic[i].min << endl;          //����ӰƬʱ��
		ofile << tick.tic[i].year << endl;         //������
		ofile << tick.tic[i].month << endl;        //�����·�
		ofile << tick.tic[i].day << endl;          //������
		ofile << tick.tic[i].hour << endl;         //����ʱ
		ofile << tick.tic[i].minute << endl;       //�����
		ofile << tick.tic[i].num << endl;          //���泡��
		ofile << tick.tic[i].price << endl;        //����۸�
		ofile << tick.tic[i].discount << endl;     //�����Ա�ۿ�
		ofile << tick.tic[i].rest << endl;         //������λ

		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
			{
				ofile << tick.tic[i].seat[m][n] << endl;//������λ��Ϣ
			}
		}
	}
	ofile.close();
}

//��ȡ
void ticket::read()
{
	ifstream ifile;
	ifile.open("ӰƬ����.txt", ios::in);

	tick.len = 0;

	if (!ifile.is_open())
	{
		//cout << "�ļ���ʧ�ܣ�" << endl;
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
	for (j = 0; j < i; j++)// ����Ԫ�ؿ�ʼ�Ƚ�����  
	{
		r = timecmp(tick.tic[i].datetime, tick.tic[j].datetime, 5);
		if (r == -1)// �ҵ���һ�������������  , ������ǰ��  
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
		for (j = i + 1; j < tick.len; j++)// ����Ԫ�ؿ�ʼ�Ƚ�����  
		{
			r = timecmp(tick.tic[i].datetime, tick.tic[j].datetime, 5);
			if (r == -1)// �ҵ���һ�������������  , ������ǰ��  
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

//¼����Ϣ������Ա��
void ticket::input()
{
	tick.read();
	char ch;// ���������е��ַ�"�� " 
	for (int i = tick.len; i < N; i++)
	{
		cout << "\n��ϵͳ��ʾ��ӰƬ���ƣ�";
		cin >> tick.tic[i].name;

		cout << "\n��ϵͳ��ʾ��ӰƬ���ͣ�����2D����";
		cin >> tick.tic[i].type;

		cout << "\n��ϵͳ��ʾ��ӰƬʱ����150����";
		cin >> tick.tic[i].min;

		cout << "\n��ϵͳ��ʾ����ӳ���� (2011-11-11) ��";
		cin >> tick.tic[i].year >> ch >> tick.tic[i].month >> ch >> tick.tic[i].day;

		cout << "\n��ϵͳ��ʾ����ӳʱ�� (12:30) ��";
		cin >> tick.tic[i].hour;
		cin >> ch;
		cin >> tick.tic[i].minute;

		tick.tic[i].datetime[0] = tick.tic[i].year;
		tick.tic[i].datetime[1] = tick.tic[i].month;
		tick.tic[i].datetime[2] = tick.tic[i].day;
		tick.tic[i].datetime[3] = tick.tic[i].hour;
		tick.tic[i].datetime[4] = tick.tic[i].minute;

		cout << "\n��ϵͳ��ʾ����ӳӰ����";
		cin >> tick.tic[i].num;

		cout << "\n��ϵͳ��ʾ����ӰƱ�ۣ�";
		cin >> tick.tic[i].price;
		cout << "\n��ϵͳ��ʾ����Ա�ۣ�";
		cin >> tick.tic[i].discount;

		tick.tic[i].rest = 100;

		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
				tick.tic[i].seat[m][n] = 0;
		}

		tick.len++;// ������1
		if (i != 0)// ��ʱ�� , ��������  
		{
			int j = sort(i);
		}

		tick.save();
		cout << endl;
		cout << "��ϵͳ��ʾ���Ƿ����¼��(Y/N)��";
		while (1)
		{
			cin >> ch;
			if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
				break;
			else
				cout << "��ϵͳ��ʾ�������ʽ�������������룺";
		}
		if (ch == 'n' || ch == 'N')
		{
			break;
		}
	}
}

//��ʾ��Ϣ������Ա��
void ticket::show()
{
	tick.read();
	tick.sort1();
	int i = 0;
	tick.ctime();//����ʱ��ȽϺ���

	cout << "��ϵͳ��ʾ�����е�Ӱ��Ϣ���£�" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
		<< setw(9) << setiosflags(ios::left) << "|  ����"
		<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
		<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
		<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
		<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
		<< setw(7) << setiosflags(ios::left) << "| ��Ʊ"
		<< setw(100) << setiosflags(ios::left) << "|��ӰƱ��"
		<< setw(9) << setiosflags(ios::left) << "|  ״̬" << "|" << endl;

	for (i = 0; i < tick.len; i++)
	{
		cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
			<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
			<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
			<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
			<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
			<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
			<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
			<< " " << setw(100) << setiosflags(ios::left) << tick.tic[i].totalmoney << "|"
			<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
		
	}
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	//setiosflags(ios::left) ������䣨���ͷ�ļ�#include <iomanip>ʹ�ã�
	//setw(10) ���������ݲ���10���Զ�����ո��Ʊ��ã����ͷ�ļ�#include <iomanip>ʹ�ã�
}

//ӰƬ��Ϣ��ѯ������Ա��
void ticket::search()
{
	tick.read();//ӰƬ��Ϣ��ȡ
	tick.ctime();//ʱ��Ƚϵ���
	int i;
	int k = 0;//����ҵ��Ĵ���  
	string na;

	cout << "��ϵͳ��ʾ��������ӰƬ����";
	cin >> na;
	cout << endl;

	if (tick.len == 0)
	{
		cout << "��ϵͳ��ʾ����ϢΪ�գ�";
	}
	else
	{
		cout << "��ϵͳ��ʾ����ѯ������£�" << endl;
		cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
		cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
			<< setw(9) << setiosflags(ios::left) << "|  ����"
			<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
			<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
			<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
			<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
			<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
			<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
			<< setw(7) << setiosflags(ios::left) << "| ��Ʊ"
			<< setw(100) << setiosflags(ios::left) << "|��ӰƱ��"
			<< setw(9) << setiosflags(ios::left) << "|  ״̬" << "|" << endl;
		cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
		for (i = 0; i < tick.len; i++)
		{
			if (tick.tic[i].name == na)// �ҵ�  
			{
				k++;// �ҵ��ļ�¼��  

				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
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
		cout << "��ϵͳ��ʾ��δ��ѯ�������Ϣ����ѯʧ�ܣ�" << endl;
	}

}
//ӰƬ��Ϣ�޸ģ�����Ա��
void ticket::change()
{
	tick.read();//ӰƬ��Ϣ��ȡ
	string name;
	int i;
	int j = 0;// ����޸�����  

	cout << "��ϵͳ��ʾ��������ӰƬ���ƣ�";
	cin >> name;
	cout << endl;
	cout << "��ϵͳ��ʾ����ѯ������£�" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
		<< setw(9) << setiosflags(ios::left) << "|  ����"
		<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
		<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
		<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
		<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
		<< setw(7) << setiosflags(ios::left) << "| ��Ʊ"
		<< setw(9) << setiosflags(ios::left) << "|  ״̬" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == name)// �ҵ�  
		{
			j++;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
			cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
			char a;
			int choice = -1;

			cout << endl;
			cout << "\t\t\t��������������������������������������������������������������������������������\n";
			cout << "\t\t\t��                                      ��\t\n";
			cout << "\t\t\t��   1.�޸�ӰƬ����   2.�޸�ӰƬ����    ��\t\n";
			cout << "\t\t\t��   3.�޸�ӰƬʱ��   4.�޸ķ�ӳ����    ��\t\n";
			cout << "\t\t\t��   5.�޸ķ�ӳʱ��   6.�޸ķ�ӳӰ��    ��\t\n";
			cout << "\t\t\t��   7.�޸�ӰƬƱ��   8.�޸Ļ�ԱƱ��    ��\t\n";
			cout << "\t\t\t��                                      ��\t\n";
			cout << "\t\t\t��������������������������������������������������������������������������������\n";
			cout << endl;
			cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��0-7����";
			cin >> choice;

			if (choice < 0 || choice>7)
			{
				cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺" << endl;
				cin >> choice;
			}
			char ch;
			switch (choice)
			{
			case 1:cout << "\n��ϵͳ��ʾ��ӰƬ���ƣ�";
				cin >> tick.tic[i].name;
				break;
			case 2:cout << "\n��ϵͳ��ʾ��ӰƬ���ͣ�����2D����";
				cin >> tick.tic[i].type;
				break;
			case 3:cout << "\n��ϵͳ��ʾ��ӰƬʱ����";
				cin >> tick.tic[i].min;
				break;
			case 4:cout << "\n��ϵͳ��ʾ����ӳ���ڣ�2020-11-11����";
				cin >> tick.tic[i].year >> ch >> tick.tic[i].month >> ch >> tick.tic[i].day;
				tick.tic[i].datetime[0] = tick.tic[i].year;
				tick.tic[i].datetime[1] = tick.tic[i].month;
				tick.tic[i].datetime[2] = tick.tic[i].day; i = sort(i);
				break;
			case 5:cout << "\n��ϵͳ��ʾ����ӳʱ�䣨12:15����";
				cin >> tick.tic[i].hour >> ch >> tick.tic[i].minute;
				tick.tic[i].datetime[3] = tick.tic[i].hour;
				tick.tic[i].datetime[4] = tick.tic[i].minute; i = sort(i);
				break;
			case 6:cout << "\n��ϵͳ��ʾ����ӳӰ����";
				cin >> tick.tic[i].num;
				break;
			case 7:cout << "\n��ϵͳ��ʾ��Ʊ�ۣ�";
				cin >> tick.tic[i].price;
				break;
			case 8:cout << "\n��ϵͳ��ʾ����Ա�ۣ�";
				cin >> tick.tic[i].discount;
				break;
			case 0:break;
			}
			tick.save();//ӰƬ��Ϣ�������
			cout << endl << "��ϵͳ��ʾ���Ƿ�����޸Ĵ�ӰƬ(Y/N): ";
			cin >> a;

			if (a != 'N' && a != 'n');
			{
				cout << endl;
				cout << "��ϵͳ��ʾ��ӰƬ��Ϣ�޸ĳɹ���" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
					<< setw(9) << setiosflags(ios::left) << "|  ����"
					<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
					<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
					<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
					<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
					<< setw(7) << setiosflags(ios::left) << "| ��Ʊ" << "|" << endl;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
					<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
			}
		}
	}
	if (i == tick.len && j == 0)
	{
		cout << "��ϵͳ��ʾ��δ��ѯ�������Ϣ,��ѯʧ�ܣ�" << endl;
	}
	system("pause");// ���������
}

//ɾ��ӰƬ
void ticket::del()
{
	tick.read();//ӰƬ��Ϣ��ȡ
	string name;
	int i;
	int j = 0;// ���ɾ��������  
	cout << "��ϵͳ��ʾ��������ӰƬ���ƣ�";
	cin >> name;
	cout << endl;
	cout << "��ϵͳ��ʾ����ѯ������£�" << endl;
	cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
		<< setw(9) << setiosflags(ios::left) << "|  ����"
		<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
		<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
		<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
		<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
		<< setw(7) << setiosflags(ios::left) << "| ��Ʊ"
		<< setw(9) << setiosflags(ios::left) << "|  ״̬" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;

	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == name)// �ҵ�
		{
			j++;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].action << "|" << endl;
			cout << " ----------------------------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "��ϵͳ��ʾ���Ƿ�ɾ��ӰƬ " << endl;
			cout << "��������������������������������������������������������������\n";
			cout << "��     1.ȷ  ��     2.ȡ  ��   ��\t\n";
			cout << "��������������������������������������������������������������\n";
			int choose = 0;
			cout << "��ϵͳ��ʾ�����������ѡ��";
			cin >> choose;
			switch (choose)
			{
			case 1:
				for (int j = i + 1; j < tick.len; j++)
				{
					tick.tic[j - 1] = tick.tic[j];
				}
				cout << endl << "��ϵͳ��ʾ��ɾ���ɹ���" << endl;
				tick.len--;
				tick.save();
				break;
			case 2:tick.del(); break;
			}
		}
	}
	if (i == tick.len && j == 0)
	{
		cout << "��ϵͳ��ʾ��δ��ѯ�������Ϣ��ɾ��ʧ�ܣ�" << endl;
	}
	system("pause");// ���������  
}

//��Ʊ
void ticket::sell()
{
	tick.read();//ӰƬ��Ϣ��ȡ
	tick.sort1();//�������
	//��ȡϵͳʱ����������ʱ����бȽ�
	time_t timep;
	struct tm* p;
	int in_time[5];
	int now_time[5];
	int i;
	int k = 0;// ��ǿɹ�Ԥ����ӰƬ���� 

	cout << "��ϵͳ��ʾ����Ԥ���ĵ�Ӱ��Ϣ���£�" << endl;
	cout << " -------------------------------------------------------------------------------------------------- " << endl;
	cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
		<< setw(9) << setiosflags(ios::left) << "|  ����"
		<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
		<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
		<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
		<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
		<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
		<< setw(7) << setiosflags(ios::left) << "| ��Ʊ" << "|" << endl;
	
	for (i = 0; i < tick.len; i++)
	{
		//������ʱ�����θ�ֵ������ʱ������
		in_time[0] = tick.tic[i].year;//����ʱ��-��
		in_time[1] = tick.tic[i].month;//����ʱ��-��
		in_time[2] = tick.tic[i].day;//����ʱ��-��
		in_time[3] = tick.tic[i].hour;//����ʱ��-ʱ
		in_time[4] = tick.tic[i].minute;//����ʱ��-��

		time(&timep);
		p = gmtime(&timep);

		//��ϵͳʱ�����θ�ֵ��ϵͳʱ������
		now_time[0] = 1900 + p->tm_year;//ϵͳʱ��-��
		now_time[1] = 1 + p->tm_mon;//ϵͳʱ��-��
		now_time[2] = p->tm_mday;//ϵͳʱ��-��
		now_time[3] = 8 + p->tm_hour;//ϵͳʱ��-ʱ
		now_time[4] = p->tm_min;//ϵͳʱ��-��

		//���αȽ���������
		for (int x = 0; x < 5; x++)
		{
			if (in_time[x] > now_time[x])
			{
				k++;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
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
		cout << "��ϵͳ��ʾ�����޿ɹ�Ԥ����ӰƬ��" << endl;
		return;
		system("pause");// ���������
	}
	system("pause");// ���������

	string na;
	cout << endl << "��ϵͳ��ʾ��������ҪԤ����ӰƬ����";
	cin >> na;
	k = 0;// �ٴ������
	for (i = 0; i < tick.len; i++)
	{
		if (tick.tic[i].name == na)// �ҵ�  
		{
			k++;// �ҵ��ļ�¼��  
			int j = 1;
			if (j == 1)
			{
				cout << "��ϵͳ��ʾ�����ҽ�����£�" << endl;
				cout << " -------------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
					<< setw(9) << setiosflags(ios::left) << "|  ����"
					<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
					<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
					<< setw(7) << setiosflags(ios::left) << "| Ʊ��"
					<< setw(9) << setiosflags(ios::left) << "| ��Ա��"
					<< setw(7) << setiosflags(ios::left) << "| ��Ʊ" << "|" << endl;
			}
			j++;
			cout << "|--------------------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].price << "|"
				<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].discount << "|"
				<< " " << setw(5) << setiosflags(ios::left) << tick.tic[i].rest << "|" << endl;
			cout << " -------------------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "��ϵͳ��ʾ��ӰƬ��" << na << "����ǰԤ�����(����ʾ��Ԥ��������ʾδԤ����" << endl;
			cout << "��ϵͳ��ʾ��" << tick.tic[i].num << "������λʾ��ͼ";
			cout << endl;
			for (int m = 0; m < 10; m++)
			{
				cout << endl;
				for (int n = 0; n < 10; n++)
				{
					if (tick.tic[i].seat[m][n] != 0)
					{

						cout << " ��";
					}
					else
					{
						cout << " ��";
					}
				}
			}
			cout << endl;
			cout << endl;
			cout << "��ϵͳ��ʾ��������Ԥ������λ�ţ�1-100����";
			int seatnum;
			cin >> seatnum;
			if (seatnum > 100 || seatnum < 1)
			{
				cout << endl << "��ϵͳ��ʾ���Բ����޴���λ��";
				system("pause");// ���������  
				return;
			}
			int m, n;
			m = (seatnum - 1) / 10;//��λ��ȡ��λ-1
			n = (seatnum - 1) % 10;//��λ��ȡʮλ-1
			if (tick.tic[i].seat[m][n] == 0 && tick.tic[i].rest != 0)
			{
				cout << "��ϵͳ��ʾ���Ƿ��Ի�ԱȨ�޹���(Y/N)��";
				char a;
				int price;
				cin >> a;
				if (a != 'N' && a != 'n')
				{
					//ԭ�۹���
					tick.tic[i].seat[m][n] = tick.tic[i].price;
				}
				else
				{
					//��Ա�۹���
					tick.tic[i].seat[m][n] = tick.tic[i].discount;
				}
				tick.tic[i].rest--;//��λ��һ
				tick.tic[i].sum++;

				string ph;
				cout << "��ϵͳ��ʾ��������Ԥ���ֻ��ţ�";
				cin >> ph;
				//��������Ϣ�������ļ�

				ud.read();//������Ϣ��ȡ
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
					ud.save();//������Ϣ����
					break;
				}

				cout << endl;
				cout << "��ϵͳ��ʾ��������Ϣȷ�ϣ� " << endl;
				cout << " ---------------------------------------------------------------------------------------------- " << endl;
				cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
					<< setw(9) << setiosflags(ios::left) << "|  ����"
					<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
					<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
					<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
					<< setw(10) << setiosflags(ios::left) << "|  ��λ��"
					<< setw(9) << setiosflags(ios::left) << "| ��֧��" << "|" << endl;
				cout << "|----------------------------------------------------------------------------------------------|" << endl;
				cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
					<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
					<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
					<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
					<< " " << setw(2) << setiosflags(ios::left) << seatnum / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seatnum % 10 << "��" << "|"
					<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].seat[m][n] << "|" << endl;
				cout << " ---------------------------------------------------------------------------------------------- " << endl;
				cout << endl;
				cout << "��ϵͳ��ʾ��" << tick.tic[i].num << "������λʾ��ͼ";
				cout << endl;
				for (int m = 0; m < 10; m++)
				{
					cout << endl;
					for (int n = 0; n < 10; n++)
					{
						if (tick.tic[i].seat[m][n] != 0)
						{

							cout << " ��";
						}
						else
						{
							cout << " ��";
						}
					}
				}
				cout << endl;
				cout << endl;
				cout << "��������������������������������������������������������������\n";
				cout << "��     1.ȷ  ��     2.ȡ  ��   ��\t\n";
				cout << "��������������������������������������������������������������\n";
				int choose = 0;
				cout << "��ϵͳ��ʾ�����������ѡ��";
				cin >> choose;
				switch (choose)
				{
				case 1:cout << endl << "��ϵͳ��ʾ��Ԥ���ɹ���" << endl;;
					tick.save();
					cout << "��ϵͳ��ʾ���û�" << ph << "������Ϣ�� " << endl;
					cout << " ------------------------------------------------------------------------------------- " << endl;
					cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
						<< setw(9) << setiosflags(ios::left) << "|  ����"
						<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
						<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
						<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
						<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
						<< setw(10) << setiosflags(ios::left) << "|  ��λ��" << "|" << endl;
					cout << "|-------------------------------------------------------------------------------------|" << endl;
					cout << "|" << setw(21) << setiosflags(ios::left) << tick.tic[i].name << "|"
						<< " " << setw(7) << setiosflags(ios::left) << tick.tic[i].type << "|"
						<< " " << setw(3) << setiosflags(ios::left) << tick.tic[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
						<< " " << setw(4) << setiosflags(ios::left) << tick.tic[i].year << "-" << setw(2) << setiosflags(ios::left) << tick.tic[i].month << "-" << setw(3) << setiosflags(ios::left) << tick.tic[i].day << "|"
						<< "   " << setw(2) << setiosflags(ios::left) << tick.tic[i].hour << ":" << setw(4) << setiosflags(ios::left) << tick.tic[i].minute << "|"
						<< "   " << setw(1) << setiosflags(ios::left) << tick.tic[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
						<< " " << setw(2) << setiosflags(ios::left) << seatnum / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seatnum % 10 << "��" << "|" << endl;
					cout << " ------------------------------------------------------------------------------------- " << endl;
					system("pause");// ��������� 
					break;
				case 2:tick.sell(); break;
				}
				return;
			}
			else
			{
				if (tick.tic[i].rest == 0)
				{
					cout << endl << "��ϵͳ��ʾ����Ʊ���㣬��������";
					cout << endl;
					system("pause");// ���������  
					return;
				}
				else if (tick.tic[i].seat[m][n] != 0)
				{
					cout << endl << "��ϵͳ��ʾ������λ�ѱ�Ԥ����";
					cout << endl;
					system("pause");// ���������  
					return;
				}
			}
		}
	}
	if (i == tick.len && k == 0)
	{
		cout << "��ϵͳ��ʾ��û���ҵ���ҪԤ���ĵ�Ӱ��" << endl;
		system("pause");// ���������  
		return;
	}
}

//ȡƱ
void ticket::ticketout()
{
	p1.read();//������Ϣ��ȡ
	string ph;
	int k = 0;//���ƥ�����
	cout << "��ϵͳ��ʾ��������Ԥ���ֻ��ţ�";
	cin >> ph;
	
	for (int i = 0; i < scount1+1; i++)
	{
		
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << endl;
			cout << "��ϵͳ��ʾ���û�" << ph << "�Ķ�����Ϣ�� " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
				<< setw(9) << setiosflags(ios::left) << "|  ����"
				<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
				<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
				<< setw(10) << setiosflags(ios::left) << "|  ��λ��" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seat % 10 << "��" << "|" << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "��ϵͳ��ʾ���Ƿ��ӡ������Ϣ " << endl;
			cout << "��������������������������������������������������������������\n";
			cout << "��     1.ȷ  ��     2.ȡ  ��   ��\t\n";
			cout << "��������������������������������������������������������������\n";
			int choose = 0;
			cout << "��ϵͳ��ʾ�����������ѡ��";
			cin >> choose;
			switch (choose)
			{
			case 1:cout << "��ϵͳ��ʾ����ӡ�ɹ��� " << endl;
				system("pause");// ��������� 
				break;
			case 2:tick.ticketout(); break;
			}
		}
	}
	if (k == 0)
	{
		cout << "��ϵͳ��ʾ��δ��ѯ��������Ϣ" << endl;
		system("pause");// ��������� 
	}
}


//��Ʊ
void ticket::refund()
{
	p1.read();//������Ϣ��ȡ
	string ph;
	int k = 0;//���ƥ�����
	int j = 0;
	int choice = 0;
	cout << "��ϵͳ��ʾ��������Ԥ���ֻ��ţ�";
	cin >> ph;
	cout << endl;
	for (int i = 0; i < scount1; i++)
	{
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << "��ϵͳ��ʾ���û�" << ph << "������Ϣ�� " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
				<< setw(9) << setiosflags(ios::left) << "|  ����"
				<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
				<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
				<< setw(10) << setiosflags(ios::left) << "|  ��λ��" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seat % 10 << "��" << "|" << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;

			cout << endl;
			cout << "��ϵͳ��ʾ���Ƿ��˶���ǰӰƱ " << endl;
			cout << "��������������������������������������������������������������\n";
			cout << "��     1.ȷ  ��     2.ȡ  ��   ��\t\n";
			cout << "��������������������������������������������������������������\n";
			int choose = 0;
			cout << "��ϵͳ��ʾ�����������ѡ��";
			cin >> choose;
			switch (choose)
			{
			case 1://��ȡϵͳʱ����������ʱ����бȽ�
				time_t timep;
				struct tm* p;
				int in_time[5];
				int now_time[5];

				//������ʱ�����θ�ֵ������ʱ������
				in_time[0] = userdata[i].year;//����ʱ��-��
				in_time[1] = userdata[i].month;//����ʱ��-��
				in_time[2] = userdata[i].day;//����ʱ��-��
				in_time[3] = userdata[i].hour;//����ʱ��-ʱ
				in_time[4] = userdata[i].minute;//����ʱ��-��

				time(&timep);
				p = gmtime(&timep);

				//��ϵͳʱ�����θ�ֵ��ϵͳʱ������
				now_time[0] = 1900 + p->tm_year;//ϵͳʱ��-��
				now_time[1] = 1 + p->tm_mon;//ϵͳʱ��-��
				now_time[2] = p->tm_mday;//ϵͳʱ��-��
				now_time[3] = 8 + p->tm_hour;//ϵͳʱ��-ʱ
				now_time[4] = p->tm_min;//ϵͳʱ��-��

				//���αȽ���������

				for (int x = 0; x < 5; x++)
				{
					if (in_time[x] > now_time[x])
					{
						j++;
						cout << endl;
						cout << "��ϵͳ��ʾ��������Ϣȷ�ϣ� " << endl;
						cout << " ---------------------------------------------------------------------------------------------- " << endl;
						cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
							<< setw(9) << setiosflags(ios::left) << "|  ����"
							<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
							<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
							<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
							<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
							<< setw(10) << setiosflags(ios::left) << "|  ��λ��"
							<< setw(9) << setiosflags(ios::left) << "| �� ��" << "|" << endl;
						cout << "|----------------------------------------------------------------------------------------------|" << endl;
						cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
							<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
							<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
							<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
							<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
							<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
							<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seat % 10 << "��" << "|"
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
				cout << "��������������������������������������������������������������\n";
				cout << "��     1.ȷ  ��     2.ȡ  ��   ��\t\n";
				cout << "��������������������������������������������������������������\n";
				cout << "��ϵͳ��ʾ�����������ѡ��";
				cin >> choice;
				switch (choice)
				{
				case 1:for (i = 0; i < scount1; i++)
				{
					if (userdata[i].phone == ph)// �ҵ�
					{
						j++;
						for (int j = i + 1; j < scount1; j++)
						{
							userdata[j - 1] = userdata[j];
						}
						int m, n;
						m = (seat - 1) / 10;//��λ��ȡ��λ-1
						n = (seat - 1) % 10;//��λ��ȡʮλ-1
						/*int m = seat / 10;
						int n = seat % 10;*/
						
						tick.tic[i].seat[m][n] = 0;
						tick.tic[i].rest++;
						tick.tic[i].sum--;
						tick.save();
						cout << "��ϵͳ��ʾ����Ʊ�ɹ���" << endl;
						system("pause");//����
						scount1--;
						ud.save();
					}
				}
			    break;
				case 2:tick.refund(); break;
				}
				if (j == 0)
				{
					cout << "��ϵͳ��ʾ��ӰƬ�Ѳ��ţ��޷���Ʊ�� " << endl;
				}
				break;
			case 2:tick.refund(); break;
			}
		}
	}
	if (k == 0)
	{
		cout << "��ϵͳ��ʾ��δ��ѯ�������Ϣ " << endl;
		system("pause");//����
	}
}
//��ѯ��Ʊ��ʷ��¼
void ticket::history()
{
	p1.read();//������Ϣ��ȡ
	string ph;
	int k = 0;//���ƥ�����
	int j = 0;
	int choice = 0;
	cout << "��ϵͳ��ʾ�����ٴ�����Ԥ���ֻ��ţ�";
	cin >> ph;
	cout << endl;
	for (int i = 0; i < scount1; i++)
	{
		if (ph == userdata[i].phone)
		{
			k++;
			int seat = userdata[i].seat;
			cout << "��ϵͳ��ʾ���û�" << ph << "������Ϣ�� " << endl;
			cout << " ------------------------------------------------------------------------------------- " << endl;
			cout << setw(22) << setiosflags(ios::left) << "|       ӰƬ����"
				<< setw(9) << setiosflags(ios::left) << "|  ����"
				<< setw(10) << setiosflags(ios::left) << "|   ʱ��"
				<< setw(13) << setiosflags(ios::left) << "|  ��ӳ����"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳʱ��"
				<< setw(11) << setiosflags(ios::left) << "| ��ӳӰ��"
				<< setw(10) << setiosflags(ios::left) << "|  ��λ��" << "|" << endl;
			cout << "|-------------------------------------------------------------------------------------|" << endl;
			cout << "|" << setw(21) << setiosflags(ios::left) << userdata[i].name << "|"
				<< " " << setw(7) << setiosflags(ios::left) << userdata[i].type << "|"
				<< " " << setw(3) << setiosflags(ios::left) << userdata[i].min << setw(5) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(4) << setiosflags(ios::left) << userdata[i].year << "-" << setw(2) << setiosflags(ios::left) << userdata[i].month << "-" << setw(3) << setiosflags(ios::left) << userdata[i].day << "|"
				<< "   " << setw(2) << setiosflags(ios::left) << userdata[i].hour << ":" << setw(4) << setiosflags(ios::left) << userdata[i].minute << "|"
				<< "   " << setw(1) << setiosflags(ios::left) << userdata[i].num << setw(6) << setiosflags(ios::left) << "����" << "|"
				<< " " << setw(2) << setiosflags(ios::left) << seat / 10 + 1 << "��" << setw(2) << setiosflags(ios::left) << seat % 10 << "��" << "|" << endl;
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