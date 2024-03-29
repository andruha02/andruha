#include "stdafx.h"
#include <iostream>
#include <fstream>
#define N 3
using namespace std;

struct Data
{
	char surname[32], surname1[32], name[32], day[32], month[32];
	int hour, minute, second;
};

void CreateData(struct Data *student, int i)
{
	for (int j = 0; j < i; j++)
	{
		Data *st = &student[j];
		cout << endl << "Student" << j + 1 << endl;
		cout << "Surname : " << endl;
		cin >> st->surname;
		cout << "Name : " << endl;
		cin >> st->name;
		cout << "Day birthday : " << endl;
		cin >> st->day;
		cout << "Month birthday : " << endl;
		cin >> st->month;
	}
}
void CreateData1(struct Data *skier, int i)
{
	
	for (int j = 0; j < i; j++)
	{
		Data *sk = &skier[j];
		cout << endl << "Member" << j + 1 << endl;
		cout << "Surname1 : " << endl;
		cin >> sk->surname1;
		cout << "Hour : " << endl;
		cin >> sk->hour;
		cout << "Minute : " << endl;
		cin >> sk->minute;
		cout << "Second : " << endl;
		cin >> sk->second;
	}
}



void RW(struct Data *student, int i) //Функція запису RW() у типізований файл INFO.DAT у вигляді структури
{
	ofstream info("INFO.DAT");

	for (int j = 0; j < i; j++)
	{
		Data *st = &student[j];
		info << st->surname << endl << st->name << endl << st->day << endl << st->month << endl;
	}
}


void RD(struct Data *student1, int i, int m) //Функція читання RD() з файлу INFO.DAT для виведення вмысту файлу на екран
{
	char month1[32];
	cout << endl << " Enter a month : " << endl;
	cin >> month1;
	ifstream file;
	file.open("INFO.DAT");

	for (int j = 0; j < i; j++)
	{
		Data *st = &student1[j];
		file.getline(st->surname, 32);

		file.getline(st->name, 32);

		file.getline(st->day, 32);

		file.getline(st->month, 32);


	}
	for (int n = 0; n < i; n++)
	{
		if (strstr(student1[n].month, month1) != NULL)
		{
			Data *st = &student1[n];
			cout << endl << st->surname << endl;

			cout << st->name << endl;

			cout << st->day << endl;

			cout << st->month << endl;

			m++;
		}
	}
	cout << "Results searching: " << m << endl;
	cout << "_________________________________________________________________________________________" << endl;
}

void RW(struct Data *skier, int i, int j) //Функція запису RW() у типізований файл INFO.TXT у вигляді структури
{
	ofstream info("INFO.TXT");

	for (j = 0; j < i; j++)
	{
		Data *sk = &skier[j];
		info << sk->surname1 << endl << sk->hour << ":" << sk->minute << ":" << sk->second << endl;
	}
}

void RD(struct Data *skier, int i)//Функція читання RD() з файлу INFO.TXT для виведення вмісту файлу на екран
{
	ifstream file;
	file.open("INFO.TXT");
	int a, b, c, d, maxseconds = 0, thirdmember;

	for (int j = 0; j < i; j++)
	{
		Data *sk = &skier[j];
		a = sk->hour;
		b = sk->minute;
		c = sk->second;
		d = (a * 60 + b) * 60 + c;
		cout << "Seconds summ : " << d << endl;
		if (d > maxseconds)
		{
			maxseconds = d;
			thirdmember = j + 1;
		}
	}
	cout << "Max= " << maxseconds << endl;
	cout << "Maxi= " << thirdmember << endl;
	cout << "_________________________________________________________________________________________" << endl;
	cout << "Third Plays: " << endl << skier[thirdmember - 1].surname1 << endl;
	cout << skier[thirdmember - 1].hour << ":" << skier[thirdmember - 1].minute << ":" << skier[thirdmember - 1].second << endl;

}

int main()
{
	struct Data student[N];
	struct Data skier[N];
	CreateData(student, N);
	CreateData1(skier, N);
	RW(student, N);
	RW(skier, N, 0);
	RD(student, N, 0);
	RD(skier, N);
	cin.get();
}
