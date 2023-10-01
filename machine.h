#ifndef MACHINE_H
#define MACHINE_H
#include<string>
using namespace std;
class machine
{
private:
	string account_number;
	string Phone;
	string name;
	double money;
	int pin;
public:
	machine();
	machine(long long account_number, string name, string Phone, int pin);
	void set_account(string account);
	void set_Phone(string Phone);
	void set_money(double money);
	void set_name(string name);
	void set_pin(int pin);
	string get_account();
	string get_phone();
	string get_name();
	double get_money();
	int get_pin();
};
#endif