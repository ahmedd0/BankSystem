#ifndef ADMIN_H
#define ADMIN_H
#include <vector>

#include "Employee.h"
class Admin : public Employee
{

private:
public:
	Admin()
	{
	}
	Admin(string firstName, string lastName, string nationalId, string password, double salary)
		: Employee(firstName, lastName, nationalId, password, salary)
	{
	}
	//--------------------- Create Employee
	Employee *createEmployee(string firstName, string lastName, string nationalId, string password, double sallary)
	{
		Employee *e = new Employee(firstName, lastName, nationalId, password, sallary);
		return e;
	}
	//----------------------- REMOVE AN EMPLPYEE
	void deleteEmployee(Employee *e)
	{
		delete e;
	}

	//-----------------------PRINT INFORMATION FOR ALL EMPLOYEES
	void printAllEmployees(map<int, Employee *> emp)
	{
		map<int, Employee *>::iterator it;
		it = emp.begin();
		for (it; it != emp.end(); it++)
		{
			it->second->printInfo();
		}
	}
};

#endif
