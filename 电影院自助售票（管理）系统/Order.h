#pragma once
/*������Ϣ*/
#include<iostream>
#include<fstream>

using namespace std;
#define MAX 100
int scount1 = 0;


class UserData
{
public:
	string phone;//�绰
	string name;//Ƭ��
	string type;//����
	int min;//ʱ��
	int year;//��
	int month;//��
	int day;//��
	int hour;//ʱ
	int minute;//��
	int num;//Ӱ��
	float seat;//��λ��
	int price;//Ʊ��

	UserData() {};
	void save();
	void read();
}ud;

UserData userdata[MAX];

void UserData::save()
{
	ofstream ofile;
	ofile.open("data.txt", ios::out);
	for (int x = 0; x < scount1; x++)
	{
		ofile << userdata[x].phone << endl;
		ofile << userdata[x].name << endl;
		ofile << userdata[x].type << endl;
		ofile << userdata[x].min << endl;
		ofile << userdata[x].year << endl;
		ofile << userdata[x].month << endl;
		ofile << userdata[x].day << endl;
		ofile << userdata[x].hour << endl;
		ofile << userdata[x].minute << endl;
		ofile << userdata[x].num << endl;
		ofile << userdata[x].seat << endl;
		ofile << userdata[x].price << endl;
	}
	ofile.close();
}

void UserData::read()
{
	ifstream ifile;
	scount1 = 0;

	ifile.open("data.txt", ios::in);

	if (!ifile.is_open())
	{
		//cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	for (int x = 0; !ifile.eof(); x++)
	{
		ifile >> userdata[x].phone;
		ifile >> userdata[x].name;
		ifile >> userdata[x].type;
		ifile >> userdata[x].min;
		ifile >> userdata[x].year;
		ifile >> userdata[x].month;
		ifile >> userdata[x].day;
		ifile >> userdata[x].hour;
		ifile >> userdata[x].minute;
		ifile >> userdata[x].num;
		ifile >> userdata[x].seat;
		ifile >> userdata[x].price;
		scount1++;
	}
	scount1--;
	ifile.close();
}
