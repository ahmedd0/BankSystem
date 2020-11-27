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
	Admin(string firstName, string lastName, string nationalId,string password ,double salary)
		: Employee(firstName, lastName, nationalId,password, salary)
	{
	}
	//--------------------- Create Employee
	void createEmployee(string firstName, string lastName, string nationalId,string password ,double sallary)
	{
		Employee *e = new Employee(firstName, lastName, nationalId, password,sallary);
	}
	//----------------------- REMOVE AN EMPLPYEE
	void removeEmployee(Employee *e)
	{
		delete e;
	}
	//---------------------- PRINT EMPLOYEE INFORMATION
	void printEmployeeInfo(Employee *emp)
	{
		// emp->printInfo();
	}
	//-----------------------PRINT INFORMATION FOR ALL EMPLOYEES
	void printAllEmployee(vector<Employee> employees)
	{
		// for (int i = 0; i < employees.size(); i++)
		// {
		// 	printEmployeeInfo(&employees[i]);
		// }
	}
	//-----------------------SEARCH
	void searchForEmployee()
	{
		
	}
};

#endif
