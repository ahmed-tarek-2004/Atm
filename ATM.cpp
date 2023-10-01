#include<algorithm>
#include<iostream>
#include<conio.h>
#include<string>
#include "machine.h"
using namespace std;
string acc;
int pin;
string name;
string phone;
double money;
int i = 0;
int f;
int j;
void intro();
void information(int id, machine* atm)
{
	cout << "\tWelcome Mr / \" " << atm[id].get_name() << " \".\n\n";
	cout << "[1]-Check Your Balance in Bank Account \n"
		<< "[2]-Get Money or Cash Withdraw \n"
		<< "[3]-Enter Money\n"
		<< "[4]-User Details\n"
		<< "[5]-Update Mobile Number\n"
		<< "[6]-Exist\n";
}
void enter( machine* atm)
{
	intro();
	cout << "Enter Account Number : ";
	cin >> acc;
	atm[i].set_account(acc);
	cout << "Enter Pin : ";
	cin >> pin;
	atm[i].set_pin(pin);
	cout << "Enter Name Of Client : ";
	cin.get();
	getline(cin, name);
	atm[i].set_name(name);
	cout << "Enter Phone Of Mr / " << atm[i].get_name()<< " : ";
	cin >> phone;
	atm[i].set_Phone(phone);
	cout << "Enter Money Please :  ";
	cin >> money;
	atm[i].set_money(money);
	i++;
}
void edit(int id, machine* atm)
{
	intro();
	cout << "Enter Account Number : ";
	cin >> acc;
	atm[id].set_account(acc);
	cout << "Enter Pin : ";
	cin >> pin;
	atm[id].set_pin(pin);
	cout << "Enter Name Of Client : ";
	cin.get();
	getline(cin, name);
	atm[id].set_name(name);
	cout << "Enter Phone Of Mr / " << atm[id].get_name() << " : ";
	cin >> phone;
	atm[id].set_Phone(phone);
	cout << "Enter Money Please :  ";
	cin >> money;
	atm[id].set_money(money);
}
void deleteacc(int id,machine*atm)
{
	swap(atm[i - 1], atm[i]);
	i--;
}
void intro()
{
	cout << endl << "\t\t****Welcome to ATM*****" << endl
		<< "\t\t-----------------------\n\n";
}
int main()
{
	int t = -1;
	int size = 100;
	machine* atm = new machine[size];
	do
	{
		system("cls");
		intro();
		int choice;
		do
		{
			cout << "[1]-Add A New Account .\n"
				<< "[2]-Have An Account .\n"
				<< "[3]-Print All Users .\n"
				<< "[4]-Edit Account .\n"
				<< "[5]-Delete Account .\n"
				<< "Enter Your Choice : ";
			cin >> choice;
			if (choice > 2 || choice < 1)
				cout << "\n\tInvaid Choice !!!\n";
		} while (choice > 3 || choice < 1);
		system("cls");
		switch (choice)
		{
		case 1:
			enter(atm+i);
			break;
		case 2:
			if (i == 0)
			{
				system("cls");
				intro();
				cout << "\n\t>>> No Accounts Exsit !!! <<<\n"
					<< "[1]-If You Want To Regesiter . \n"
					<< "[0]-For Exist .\n";
				int choice1;
				cin >> choice1;
				if (choice1)
				{
					enter(atm);
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "Enter Accont Number : ";
				cin >> acc;
				cout << "Enter Pin : ";
				cin >> pin;
				f = 0;
				cout << "\n I = " << i << endl;
				for (j = 0; j < i; j++)
				{
					if ((acc == atm[j].get_account()) && (pin == atm[j].get_pin()))
					{
						f = 1;
						cout << "Found \n\n";
						break;
					}
				}
				if (f)
				{
					cout << "\nUser Details Are Invalid. !!!\n"
						<< "[1]-If You Want To Regesiter . \n"
						<< "[0]-For Exist .\n";
					cin >> choice;
					if (choice)
					{
						enter(atm);
					}
					else
					{
						continue;
					}
				}
				else
				{
					j--;
					system("cls");
					information(j, atm);
					cout << "Enter Your Choice : ";
					int choice3;
					cin >> choice3;
					switch (choice3)
					{
					case 1:
						cout << "Your Balance IS : " << atm[j].get_money() << " .EGP\n";
						break;
					case 2:
						cout << "Enter The Amount You Want To Take : ";
						int amount;
						cin >> amount;
						if (amount > atm[j].get_money())
						{
							cout << "Invalid Amount : ";
						}
						else
						{
							atm[j].set_money(atm[i].get_money() - amount);
						}
						cout << "Sucessful Process . (*^_^*) \n";
						break;
					case 3:
						cout << "Enter The Money Amount : ";
						cin >> money;
						money += atm[j].get_money();
						atm[j].set_money(money);
						cout << "Sucessful Process . (*^_^*) \n";
						break;
					case 4:
						cout << "\n\n--------------------------------------------------------\n"
							<< "\tThe Client Name Is : " << atm[j].get_name() << endl
							<< "\tThe Client Phone Number Is : " << atm[j].get_phone() << endl
							<< "\tThe Client Account Number Is : " << atm[j].get_account() << endl
							<< "\tThe Client Pin Is : " << atm[j].get_pin() << endl
							<< "\tThe Client Saved Money Is : " << atm[j].get_money() << endl;
						cout << "Press Enter to Exit This Menu : ";
						_getch();
						break;
					case 5:
						cout << "Enter Old Phone Number : ";
						cin >> phone;
						int k;
						f = 0;
						if (phone == atm[j].get_phone())
						{
							f++;
							cout << "Enter The New Phone Number : ";
							cin >> phone;
							atm[j].set_Phone(phone);
							cout << "\n\tMoblile Phone Edited (*^_^*)\n";
						}
						else
						{
							cout << "Invalid Phone Number. !!!\n";
						}
						break;
					}
				}
			}
			break;
		case 3:
			for (int k = 0; k < i; k++)
			{
				cout << "---------------------------------------------------------------\n";
				cout<< "\tThe Client Name Is : " << atm[k].get_name() << endl
					<< "\tThe Client Phone Number Is : " << atm[k].get_phone() << endl
					<< "\tThe Client Account Number Is : " << atm[k].get_account() << endl
					<< "\tThe Client Pin Is : " << atm[k].get_pin() << endl
					<< "\tThe Client Saved Money Is : " << atm[k].get_money() << endl;
				cout << "---------------------------------------------------------------\n";
			}
			break;
		case 4:
		    f = 0;
			cout << "Enter Accont Number : ";
			cin >> acc;
			cout << "Enter Pin : ";
			cin >> pin;
			cout << "\n I = " << i << endl;
			for (j = 0; j < i; j++)
			{
				//cout << "Searching ....\b\n";
				if ((acc == atm[j].get_account()) && (pin == atm[j].get_pin()))
				{
					f = 1;
					cout << "Found \n\n";
					//j--;
					break;
				}
			}
			if (f)
			{
				cout << "\n\tInvalid Enter \n";
			}
			else
			{
				edit(j - 1, atm);
				cout << "\n\t>>>Edited<<<\n";
			}
			break;
		case 5:
			cout << "Enter Accont Number : ";
			cin >> acc;
			cout << "Enter Pin : ";
			cin >> pin;
			f = 0;
			cout << "\n I = " << i << endl;
			for (j = 0; j < i; j++)
			{
				//cout << "Searching ....\b\n";
				if ((acc == atm[j].get_account()) && (pin == atm[j].get_pin()))
				{
					f = 1;
					cout << "Found \n\n";
					//j--;
					break;
				}
			}
			if (f)
			{
				cout << "\n\tInvalid Enter \n";
			}
			else
			{
				deleteacc(j - 1, atm);
				cout << "\n\t>>Deleted<<\n";
			}
			break;
		}
		cout << "\n\t[1]-Main Menu \n"
			<< "\t[0]-Exit\n Enter Your Choice : ";
		cin >> t;
	} while (t);
	delete[]atm;
	return 0;
}