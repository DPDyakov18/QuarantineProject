#include <iostream>
#include <string>
using namespace std;
//structure about personal information for each customer
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
	string DiscountTier = "Discount 0";
};
//function that is adding information the customer
float addCustomer(int& NumberOfCustomers, PersonalInfo PI[], int& popularityFootball, int& popularityBasketball, int& popularityTennis)
{
	//i(index) is assigned by the number of customers
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
	//inputing information about played sport
	cin >> PI[i].Sport;
	//checking the number of times each sport is played
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
	//cheking if statement for right inputing of data
	if (PI[i].Sport < 1 or PI[i].Sport>3)
	{
		//do while loop for repeating an action while the statement is correct
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
			//while statement repeats the if statement
		} while (PI[i].Sport < 1 or PI[i].Sport>3);
	}
	cout << "Start time: (example : 14 15)" << endl;
	cin >> PI[i].startTimeHour >> PI[i].startTimeMinutes;
	//cheking if statement for right inputing of data
	if (PI[i].startTimeHour > 23 or PI[i].startTimeMinutes > 59 or PI[i].startTimeHour < 0 or PI[i].startTimeMinutes < 0)
	{
		do
		{
			cout << "Incorrect input!" << endl;
			cout << "Please fill in again." << endl; cout << endl;
			cout << "Start time: (example : 14 15)" << endl;
			cin >> PI[i].startTimeHour >> PI[i].startTimeMinutes;
		} while (PI[i].startTimeHour > 23 or PI[i].startTimeMinutes > 59 or PI[i].startTimeHour < 0 or PI[i].startTimeMinutes < 0);
	}
	//calculating the start time of each customer
	PI[i].startTime = PI[i].startTimeHour * 60 + PI[i].startTimeMinutes;
	PI[i].TimeSpent = 0;
	PI[i].endTimeHour = 0;
	PI[i].endTimeMinutes = 0;
	PI[i].InvitedPeople = 0;
	cout << endl;
	return 0;
}
//funtion that inputs the end time for each customer
float customersTimeEnd(int& NumberOfCustomers, PersonalInfo PI[], int& countRemain)
{
	if (NumberOfCustomers > 0)
	{
		int index = 0;
		//checking if there are any remaining customers to be updated
		if (countRemain == NumberOfCustomers)
		{
			cout << "There are no remaining customers to be updated." << endl;
			return 0;
		}
		cout << "Pick a customer:" << endl;
		//loop for outputing all the customers
		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			if (PI[i].endTimeHour == 0 and PI[i].endTimeMinutes == 0)
			{
				cout << "CUSTOMER NUMBER " << i << endl;
				cout << "Name: ";
				cout << PI[i].FirstName << " ";
				cout << PI[i].LastName << endl;
				cout << "Sport:";
				//checking the type of sport
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
		cout << "Update status on customer number:" << endl;
		cin >> index;
		//cheching if inputed customer isn't real
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
		//cheking if statement for right inputing of data
		if (PI[index].endTimeHour > 23 or PI[index].endTimeMinutes > 59 or PI[index].endTimeHour < 0 or PI[index].endTimeMinutes < 0)
		{
			do
			{
				cout << "Incorrect input!" << endl;
				cout << "Please fill in again." << endl; cout << endl;
				cout << "Finish time (example 14 15):" << endl;
				cin >> PI[index].endTimeHour >> PI[index].endTimeMinutes;
			} while (PI[index].endTimeHour > 23 or PI[index].endTimeMinutes > 59 or PI[index].endTimeHour < 0 or PI[index].endTimeMinutes < 0);
		}
		PI[index].endTime = PI[index].endTimeHour * 60 + PI[index].endTimeMinutes;
		//checking if theiputed finish time is after the starting time
		if (PI[index].endTime <= PI[index].startTime)
		{
			do
			{
				cout << "Incorrect input!" << endl;
				cout << "Please fill in again." << endl; cout << endl;
				cout << "Finish time (example 14 15):" << endl;
				cin >> PI[index].endTimeHour >> PI[index].endTimeMinutes;
				PI[index].endTime = PI[index].endTimeHour * 60 + PI[index].endTimeMinutes;

			} while (PI[index].endTime <= PI[index].startTime);
		}
		PI[index].TimeSpent = (PI[index].endTime - PI[index].startTime) / 60;
		countRemain++;
	}
	else
	{
		cout << "There aren't any customers!" << endl;
	}
	cout << endl;
	return 0;
}
//function for displaying info
void showInfo(int& NumberOfCustomers, PersonalInfo PI[])
{
	if (NumberOfCustomers > 0)
	{
		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			cout << "CUSTOMER NUMBER " << i << endl;
			cout << "Name:";
			cout << PI[i].FirstName << " ";
			cout << PI[i].LastName << endl;
			cout << "Sport:";
			//checking the type of sport
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
			//checking if there is inputed finish time
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
			cout << PI[i].DiscountTier << endl;
		}
	}
	else
	{
		cout << "There aren't any customers!" << endl;
	}
	cout << endl;
}
//function for calculating the money
int calculateMoney(int& NumberOfCustomers, PersonalInfo PI[])
{
	if (NumberOfCustomers > 0)
	{
		float SpentMoney[100];
		float TotalMoney = 0;
		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			//checking the type of sport and the price of it
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
			if (PI[i].DiscountTier == "Discount 0") {
				cout << PI[i].FirstName << " " << PI[i].LastName << endl;
				cout << "Spent money: " << SpentMoney[i] << "lv" << endl;
				cout << endl;
				TotalMoney += SpentMoney[i];
			}
			else if (PI[i].DiscountTier == "Discount 5%")
			{
				SpentMoney[i] = SpentMoney[i] - SpentMoney[i] * 0.05;
				cout << PI[i].FirstName << " " << PI[i].LastName << endl;
				cout << "Spent money: " << SpentMoney[i] << "lv" << endl;
				cout << endl;
				TotalMoney += SpentMoney[i];
			}
			else if (PI[i].DiscountTier.compare("Discount 10%"))
			{
				SpentMoney[i] = SpentMoney[i] - SpentMoney[i] * 0.10;
				cout << PI[i].FirstName << " " << PI[i].LastName << endl;
				cout << "Spent money: " << SpentMoney[i] << "lv" << endl;
				cout << endl;
				TotalMoney += SpentMoney[i];
			}
			else if (PI[i].DiscountTier.compare("Discount 20%"))
			{
				SpentMoney[i] = SpentMoney[i] - SpentMoney[i] * 0.20;
				cout << PI[i].FirstName << " " << PI[i].LastName << endl;
				cout << "Spent money: " << SpentMoney[i] << "lv" << endl;
				cout << endl;
				TotalMoney += SpentMoney[i];
			}
		}
		cout << "Total : " << TotalMoney << "lv" << endl;
	}
	else
	{
		cout << "There aren't any customers!" << endl;
	}
	cout << endl;
	return 0;
}
void referaFriend(int& NumberOfCustomers, PersonalInfo PI[])
{
	if (NumberOfCustomers > 0)
	{
		string FirstName;
		string LastName;
		cout << "Enter First Name:";
		cin >> FirstName;
		cout << "Enter Last Name:";
		cin >> LastName;
		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			if (FirstName == PI[i].FirstName && LastName == PI[i].LastName)
			{
				PI[i].InvitedPeople++;
				if (PI[i].InvitedPeople == 3)
				{
					PI[i].DiscountTier = "Discount 5%";
				}
				else if (PI[i].InvitedPeople == 5)
				{
					PI[i].DiscountTier = "Discount 10%";
				}
				else if (PI[i].InvitedPeople == 10)
				{
					PI[i].DiscountTier = "Discount 20%";
				}
				cout << PI[i].FirstName << " " << PI[i].LastName << "-" << PI[i].DiscountTier << endl;
			}
		}
	}
	else
	{
		cout << "There aren't any customers!";
	}
	cout << endl;
}
//function for checking the popularity of each sport
float sportPopularity(int& NumberofCustomers, PersonalInfo PI[], int& popularityFootball, int& popularityBasketball, int& popularityTennis)
{
	if (NumberofCustomers > 0)
	{
		//cheching if all sports are played by the same amount of people
		if (popularityFootball == popularityTennis && popularityFootball == popularityBasketball)
		{
			cout << "There isn't a most popular sport." << endl;
			cout << "All sports are played by " << popularityFootball << " people each" << endl;
			return 0;
		}
		//checking for the most popular sport
		if (popularityFootball > popularityBasketball&& popularityFootball > popularityTennis)
		{
			cout << "Most popular sport is Football." << endl;
			cout << "It's played by " << popularityFootball << " people." << endl;
			return 0;
		}
		if (popularityBasketball > popularityFootball&& popularityBasketball > popularityTennis)
		{
			cout << "Most popular sport is Basketball." << endl;
			cout << "It's played by " << popularityBasketball << " people." << endl;
			return 0;
		}	if (popularityTennis > popularityFootball&& popularityBasketball < popularityTennis)
		{
			cout << "Most popular sport is Tennis." << endl;
			cout << "It's played by " << popularityTennis << " people." << endl;
			return 0;
		}
		//checking if there are two most played sports
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
	}
	else
	{
		cout << "There aren't any customers!" << endl;
	}
	cout << endl;
}
void deleteCustomersInfo(int& NumberOfCustomers, PersonalInfo PI[])
{
	string FirstName;
	string LastName;
	if (NumberOfCustomers > 0)
	{
		cout << "All customers:" << endl;
		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			cout << PI[i].FirstName << " " << PI[i].LastName << endl;
		}
		cout << endl;
		cout << "Enter First Name:";
		cin >> FirstName;
		cout << "Enter Last Name:";
		cin >> LastName;
		bool flag = false;

		for (int i = 1; i <= NumberOfCustomers; i++)
		{
			if (FirstName == PI[i].FirstName && LastName == PI[i].LastName)
			{
				PI[i] = PI[i + 1];
				flag = true;
			}
			if (flag == true)
			{
				NumberOfCustomers--;
				cout << "You have deleted customer's info!";
			}
		}
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand names!" << endl;
			cout << "Please enter new names!";
			cout << endl;
			cout << "Enter First Name:";
			cin >> FirstName;
			cout << "Enter Last Name:";
			cin >> LastName;
		}
	}
	else
	{
		cout << "There aren't any customers!";
	}
	cout << endl;
}
//main menu
int Menu(PersonalInfo PI[], bool Flag)
{
	int NumberOfCustomers = 0, countRemain = 0;
	int popularityFootball = 0, popularityBasketball = 0, popularityTennis = 0;
	int MenuNumber = 0;
	do
	{
		cout << "..:: MENU ::.." << endl;
		cout << "1. Add a new customer" << endl;
		cout << "2. Finish with a customer" << endl;
		cout << "3. Show all customers" << endl;
		cout << "4. Calculate Money" << endl;
		cout << "5. Refer a friend" << endl;
		cout << "6. Show most popular sport" << endl;
		cout << "7. Delete a customer of the list" << endl;
		cout << "8. Exit" << endl;
		cin >> MenuNumber;
		switch (MenuNumber)
		{
		case 1:
		{
			NumberOfCustomers++;
			addCustomer(NumberOfCustomers, PI, popularityFootball, popularityBasketball, popularityTennis);
			break;
		}
		case 2:
		{
			customersTimeEnd(NumberOfCustomers, PI, countRemain);
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
			deleteCustomersInfo(NumberOfCustomers, PI);
			break;
		}
		case 8:
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