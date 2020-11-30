#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"
#include <map>
class Employee : public Person
{

private:
	double sallary;

public:
	//---------- DEFAULT CONSTRUCTOR FUNCTION
	Employee()
	{

		sallary = 0;
	}
	//---------- PARAMETERIZED CONSTRUCTOR FUNCTION

	Employee(string firstName, string lastName, string nationalId, string password, double sallary)
		: Person(firstName, lastName, nationalId, password)
	{

		this->setSallary(sallary);
	}
	// set sallary
	void setSallary(double sallary)
	{
		this->sallary = sallary;
	}

	// ----------------- Get Sallary
	double getSallary()
	{

		return sallary;
	}
	//------------------------ PRINT EMPLOYEE INFORMATION
	void printInfo()
	{
		Person::printInfo();
		cout << "SALLARY: " << getSallary() << endl;
		cout << "====================================================================" << endl;
	}
	//--------------------------- CREATE ACCOUNT
	Client *createClient(string firstName, string lastName, string nationalId, string password, double balace)
	{
		Client *client = new Client(firstName, lastName, nationalId, password, balace);
		return client;
	}
	//---------------------------- DELETE CLIENT
	void deleteClient(Client *client)
	{
		delete client;
	}

	//------------------------ PRINT ALL CLIENTS INFORMATION
	void printAllClients(map<int, Client *> emp)
	{
		map<int, Client *>::iterator it;
		it = emp.begin();
		for (it; it != emp.end(); it++)
		{
			it->second->printInfo();
		}
	}

	//------------------------- ACTIVATE CLIENT
	void activateClient(Client *client)
	{
		client->setClientActive(true);
	}
	//------------------------- DEACTIVATE CLIENT
	void deactivateClient(Client *client)
	{
		client->setClientActive(false);
	}
	void changePassword(string password)
	{
		this->setPassword(password);
	}
};

#endif
