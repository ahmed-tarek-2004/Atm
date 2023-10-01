#include "machine.h"
#include<iostream>
#include<string>
using namespace std;
machine::machine()
{
	account_number = "";
	Phone = " ";
	name = " ";
	pin = 0;
	money = 0;
}
void machine::set_account(string account)
{
	this->account_number = account_number;
}
void machine::set_Phone(string Phone)
{
	this->Phone = Phone;
}
void machine::set_name(string name)
{
	this->name = name;
}
void machine::set_pin(int pin)
{
	this->pin = pin;
}
void machine::set_money(double money)
{
	this->money = money;
}
string machine::get_account()
{
	return account_number;
}
string machine::get_phone()
{
	return Phone;
}
string machine::get_name()
{
	return name;
}
int machine::get_pin()
{
	return pin;
}
double machine::get_money()
{
	return money;
}