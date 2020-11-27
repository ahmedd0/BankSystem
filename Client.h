#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Person.h"

class Client : public Person
{
private:
	double balance;
	bool isClientActive;

public:
	// ------------------- CONSTRUCTOR FUNCTION
	Client()
	{
		setBalance(0);
		isClientActive = true;
	}
	//-------------------- PARAMETERIZED CONSTRUCTOR FUNCTION
	Client(string firstName, string lastName, string nationalId,string password, double balance)

		:Person(firstName, lastName, nationalId ,password)
	{

		setBalance(balance);

		isClientActive = true;
	}

	//-------------------- SET BALANCE FUNCTION

	void setBalance(double balance)
	{

		this->balance = balance;
	}

	//-------------------- GET BALANCE FUNCTION

	double getBalance()
	{

		return balance;
	}

	//-------------------- CHECK BALANCE AND PRINT IT

	void checkBalance()
	{

		cout << "HELLO " << firstName + " " + lastName << " YOUR BALANCE IS " << getBalance() << endl;
	}

	// ------------------- WITHDRAW FUNCTION

	void withdraw(double amount)
	{
		balance -= amount;
	}

	//-------------------- DEPOSITE FUNCTION

	void deposit(double amount)
	{

		balance += amount;
	}
	//------------------- TRANSFER MONEY TO ANOTHER ACCOUNT

	void transferMoney(double amount, Client *receiver)
	{
		this->withdraw(amount);
		receiver->deposit(amount);
	}
	//----------------- CHANGE PASSWORD FUNCTION

	void changePassword(string password)
	{

		this->setPassword(password);
	}
	//PRINT INFO
	void printInfo(){
		Person::printInfo();
		cout << "BALANCE: " << getBalance() << endl;
		cout << "====================================================================" << endl;
	}

	// -------------------- Activate Account

	void setClientActive(bool isClientActive)
	{
		this->isClientActive = isClientActive;
	}
	// Return Client Status
	bool isActive()
	{
		return isClientActive;
	}
	// ------------------- LOGOUT FUNCTION
	void logout()
	{
	}
};

#endif
