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
	float startTime, startTimeMinutes, startTimeHour;
	float endTime, endTimeMinutes, endTimeHour;
	float MoneySpent;
	int InvitedPeople = 0;
	string DiscountTier = "Tier 0";
};

float addCustomer(int& NumberOfCustomers, PersonalInfo PI[], int& popularityFootball, int& popularityBasketball, int& popularityTennis)
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
	if (PI[i].Sport == 1)
	{
		popularityFootball++;
	}
	if (PI[i].Sport == 2)
	{
		popularityBasketball++;
	}
	if (PI[i].Sport == 3)
	{
		popularityTennis++;
	}
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
	cout << "Start time: (example : 14 15)" << endl;
	cin >> PI[i].startTimeHour >> PI[i].startTimeMinutes;
	if (PI[i].startTimeHour > 39 or PI[i].startTimeMinutes > 59 or PI[i].startTimeHour < 0 or PI[i].startTimeMinutes < 0)
	{
		do
		{
			cout << "Incorrect input!" << endl;
			cout << "Please fill in again." << endl; cout << endl;
			cout << "Start time: (example : 14 15)" << endl;
			cin >> PI[i].startTimeHour >> PI[i].startTimeMinutes;
		} while (PI[i].startTimeHour > 39 or PI[i].startTimeMinutes > 59 or PI[i].startTimeHour < 0 or PI[i].startTimeMinutes < 0);
	}

	PI[i].startTime = PI[i].startTimeHour * 60 + PI[i].startTimeMinutes;
	PI[i].TimeSpent = 0;
	PI[i].endTimeHour = 0;
	PI[i].endTimeMinutes = 0;

	return 0;
}
float endCustomer(int& NumberOfCustomers, PersonalInfo PI[], int& countRemain)
{
	int index = 0;
	if (countRemain == NumberOfCustomers - 1)
	{
		cout << "There are no remaining customers to be updated." << endl;
		return 0;
	}
	cout << "Pick a customer:" << endl;
	for (int i = 1; i < NumberOfCustomers; i++)
	{
		if (PI[i].endTimeHour == 0 and PI[i].endTimeMinutes == 0)
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
			cout << "Start time:" << endl;
			cout << PI[i].startTimeHour << " " << PI[i].startTimeMinutes << endl;
			cout << endl;
		}
	}
	cout << "Update status on customer :" << endl;
	cin >> index;
	if (index < 1 or index > NumberOfCustomers) {
		do {
			cout << "Incorrect input!" << endl;
			cout << "Please fill in again." << endl; cout << endl;
			cout << endl;
			cout << "Update status on customer number:" << endl;
			cin >> index;
		} while (index < 1 or index > NumberOfCustomers);
	}
	cout << "Finish time (example 14 15):" << endl;
	cin >> PI[index].endTimeHour >> PI[index].endTimeMinutes;
	PI[index].endTime = PI[index].endTimeHour * 60 + PI[index].endTimeMinutes;
	PI[index].TimeSpent = (PI[index].endTime - PI[index].startTime) / 60;
	countRemain++;
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
		if (PI[i].TimeSpent == 0)
		{
			cout << "Began training at: " << PI[i].startTimeHour << ":" << PI[i].startTimeMinutes << endl;
			cout << "Still working out." << endl;
		}
		else
		{
			cout << "Began training at: " << PI[i].startTimeHour << ":" << PI[i].startTimeMinutes << endl;
			cout << "Finished training at: " << PI[i].endTimeHour << ":" << PI[i].endTimeMinutes << endl;
		}
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
	cout << "Total : " << TotalMoney << "lv" << endl;
	return 0;
}
void referaFriend(int& NumberOfCustomers, PersonalInfo PI[])
{
	string FirstName;
	string LastName;
	cin >> FirstName;
	cin >> LastName;
	for (int i = 1; i <= NumberOfCustomers; i++)
	{
		if (FirstName.compare(PI[i].FirstName) == 1 && LastName.compare(PI[i].LastName) == 1)
		{
			PI[i].InvitedPeople++;
			if (PI[i].InvitedPeople == 3)
			{
				PI[i].DiscountTier = "Tier 1";
			}
			else if (PI[i].InvitedPeople == 5)
			{
				PI[i].DiscountTier = "Tier 2";
			}
			else if (PI[i].InvitedPeople == 10)
			{
				PI[i].DiscountTier = "Tier 3";
			}
			cout << FirstName << " " << LastName << "-" << PI[i].DiscountTier << " " << "Discount" << endl;
		}
	}
	cout << endl;
}
float sportPopularity(int& NumberofCustomers, PersonalInfo PI[], int& popularityFootball, int& popularityBasketball, int& popularityTennis) {

	if (popularityFootball == popularityTennis && popularityFootball == popularityBasketball)
	{
		cout << "There isn't a most popular sport." << endl;
		cout << "All sports are played by " << popularityFootball << " people each" << endl;
		return 0;
	}
	if (popularityFootball > popularityBasketball&& popularityFootball > popularityTennis)
	{
		cout << "Most popular sport is Football." << endl;
		cout << "Its played by " << popularityFootball << " people." << endl;
		return 0;
	}
	if (popularityBasketball > popularityFootball&& popularityBasketball > popularityTennis)
	{
		cout << "Most popular sport is Basketball." << endl;
		cout << "Its played by " << popularityBasketball << " people." << endl;
		return 0;
	}	if (popularityTennis > popularityFootball&& popularityBasketball < popularityTennis)
	{
		cout << "Most popular sport is Tennis." << endl;
		cout << "Its played by " << popularityTennis << " people." << endl;
		return 0;
	}
	if (popularityFootball == popularityBasketball)
	{
		cout << "Most popular sports are Football and Basketball." << endl;
		cout << "They are played by " << popularityFootball << " people each." << endl;
		return 0;
	}
	if (popularityFootball == popularityTennis)
	{
		cout << "Most popular sports are Football and Tennis." << endl;
		cout << "They are played by " << popularityFootball << " people each." << endl;
		return 0;
	}
	if (popularityTennis == popularityBasketball)
	{
		cout << "Most popular sports are Tennis and Basketball." << endl;
		cout << "They are played by " << popularityTennis << " people each." << endl;
		return 0;
	}
	cout << endl;
}
int Menu(PersonalInfo PI[], bool Flag)
{
	int NumberOfCustomers = 1, countRemain = 0;
	int popularityFootball = 0, popularityBasketball = 0, popularityTennis = 0;
	int MenuNumber = 0;
	do
	{
		cout << "..:: MENU ::.." << endl;
		cout << "1. Add a new customer" << endl;
		cout << "2. Finish a customer" << endl;
		cout << "3. Show all customers" << endl;
		cout << "4. Calculate Money" << endl;
		cout << "5. Refer a friend" << endl;
		cout << "6. Show most popular sport" << endl;
		cout << "7. Exit" << endl;
		cin >> MenuNumber;
		switch (MenuNumber)
		{
		case 1:
		{
			addCustomer(NumberOfCustomers, PI, popularityFootball, popularityBasketball, popularityTennis);
			NumberOfCustomers++;
			break;
		}
		case 2:
		{
			endCustomer(NumberOfCustomers, PI, countRemain);
			break;
		}
		case 3:
		{
			showInfo(NumberOfCustomers, PI);
			break;
		}
		case 4:
		{
			calculateMoney(NumberOfCustomers, PI);
			break;
		}
		case 5:
		{
			referaFriend(NumberOfCustomers, PI);
			break;
		}
		case 6:
		{
			sportPopularity(NumberOfCustomers, PI, popularityFootball, popularityBasketball, popularityTennis);
			break;
		}
		case 7:
		{
			cout << "Thank you!" << endl;
			cout << "Goodbye!" << endl;
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