#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct PersonalInfo
{
	string FirstName;
	string LastName;
	string Sport;
	int TimeSpent;
	int NumberOfPeople;
	int MoneySpent;
};

int AddingInfo(int NumberOfClients, PersonalInfo PI[])
{
	for (int i = 0; i < NumberOfClients; i++)
	{
		cin >> PI[i].FirstName;
		cin >> PI[i].LastName;
		cin >> PI[i].Sport;
		cin >> PI[i].NumberOfPeople;
		cin >> PI[i].MoneySpent;
	}
	return 0;
}
void ShowingInfo(int &NumberOfClients, PersonalInfo PI[])
{
	for (int i = 0; i < NumberOfClients; i++)
	{
		cout << PI[i].FirstName<<" ";
		cout << PI[i].LastName<<endl;
		cout << PI[i].Sport<<endl;
		cout << PI[i].NumberOfPeople << endl;
		cout << PI[i].MoneySpent << endl;
	}
}

int Menu(int MenuNumber, int NumberOfClients, PersonalInfo PI[], bool Flag)
{
	do
	{
		switch (MenuNumber)
		{
		case 1:
		{
			AddingInfo(NumberOfClients, PI);
		}
		case 2:
		{
			ShowingInfo(NumberOfClients, PI);
		}
		case 4:
		{
			return Flag = 0;
		}
		}
	} while (Flag);
}

int main()
{
	bool Flag;
	Flag=1;
	int NumberOfClients;
	cin >> NumberOfClients;
	int MenuNumber;
	cin >> MenuNumber;
	PersonalInfo PI[10];
	AddingInfo(NumberOfClients, PI);
	ShowingInfo(NumberOfClients, PI);
}
