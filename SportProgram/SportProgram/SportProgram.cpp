// ConsoleApplication20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct PersonalInfo
{
	string FirstName;
	string LastName;
	int Sport;
	float TimeSpent;
	float MoneySpent;
};

float addInfo(int& NumberOfCustomers, PersonalInfo PI[])
{
	int i = NumberOfCustomers;
	cout << "CUSTOMER NUMBER " << i << endl;
	cout << "First name:" << endl;
	cin >> PI[i].FirstName;
	cout << "Last name:" << endl;
	cin >> PI[i].LastName;
	cout << "Pick a sport:" << endl;
	cout << "1. Football : 30lv/h " << endl;
	cout << "2. Basketball : 25lv/h " << endl;
	cout << "3. Tennis : 40lv/h" << endl;
	cin >> PI[i].Sport;
	if (PI[i].Sport < 1 or PI[i].Sport>3)
	{
		do
		{
			cout << "Incorrect input!" << endl;
			cout << "Please fill in again." << endl;
			cout << endl;
			cout << "Pick a sport:" << endl;
			cout << "1. Football : 30lv/h " << endl;
			cout << "2. Basketball : 25lv/h " << endl;
			cout << "3. Tennis : 40lv/h" << endl;
			cin >> PI[i].Sport;
		} while (PI[i].Sport < 1 or PI[i].Sport>3);
	}
	cout << "Spent time:" << endl;
	cin >> PI[i].TimeSpent;
	return 0;
}
void showInfo(int& NumberOfCustomers, PersonalInfo PI[])
{
	for (int i = 1; i < NumberOfCustomers; i++)
	{
		cout << "CUSTOMER NUMBER " << i << endl;
		cout << "Name:";
		cout << PI[i].FirstName << " ";
		cout << PI[i].LastName << endl;
		cout << "Sport:";
		if (PI[i].Sport == 1)
		{
			cout << " Football" << endl;
		}
		if (PI[i].Sport == 2)
		{
			cout << " Basketball" << endl;
		}
		if (PI[i].Sport == 3)
		{
			cout << " Tennis" << endl;
		}
		cout << "Time spent:";
		cout << PI[i].TimeSpent << endl;
		cout << endl;
	}
}
int calculateMoney(int& NumberOfCustomers, PersonalInfo PI[])
{
	float SpentMoney[100];
	float TotalMoney = 0;
	for (int i = 1; i < NumberOfCustomers; i++)
	{
		if (PI[i].Sport == 1)
		{
			PI[i].MoneySpent = 30;
		}
		if (PI[i].Sport == 2)
		{
			PI[i].MoneySpent = 25;
		}
		if (PI[i].Sport == 3)
		{
			PI[i].MoneySpent = 40;
		}
		SpentMoney[i] = PI[i].MoneySpent * PI[i].TimeSpent;
	}
	for (int i = 1; i < NumberOfCustomers; i++)
	{
		cout << PI[i].FirstName << " " << PI[i].LastName << endl;
		cout << "Spent money:" << SpentMoney[i] << "lv" << endl;
		cout << endl;
		TotalMoney += SpentMoney[i];
	}
	cout << "Total money: " << TotalMoney << "lv" << endl;
	return 0;
}
int Menu(PersonalInfo PI[], bool Flag)
{
	int NumberOfCustomers = 1;
	int MenuNumber = 0;
	do
	{
		cout << "..:: MENU ::.." << endl;
		cout << "1. Add Information" << endl;
		cout << "2. Display Information" << endl;
		cout << "3. Calculate Money" << endl;
		cout << "4. Exit" << endl;
		cin >> MenuNumber;
		switch (MenuNumber)
		{
		case 1:
		{
			addInfo(NumberOfCustomers, PI);
			NumberOfCustomers++;
			break;
		}
		case 2:
		{
			showInfo(NumberOfCustomers, PI);
			break;
		}
		case 3:
		{
			calculateMoney(NumberOfCustomers, PI);
			break;
		}
		case 4:
		{
			cout << "Thank you!" << endl;
			return Flag = 0;
		}
		default:
		{
			cout << "Incorrect input!" << endl;
			cout << "Please fill in again." << endl;
		}
		}
	} while (Flag == 1);
	return 0;
}
int main()
{
	bool Flag;
	Flag = 1;
	cout << "Welcome!" << endl;
	PersonalInfo PI[100];
	Menu(PI, Flag);
}