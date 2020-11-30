#ifndef ADMINHELPER
#define ADMINHELPER
#include "EmployeeHelper.h"
template <class T>
class AdminHelper : public EmployeeHelper<T>
{
	// Private section
public:
	AdminHelper()
	{
	}
	static void printAllEmployees(T *admin)
	{
		map<int, Employee *> Employees = FileManager::getAllEmployee();
		admin->printAllEmployees(Employees);
	}
	static void searchForEmployee()
	{
		system("cls");
		cout << "PLEASE ENTER EMPLOYEE ID" << endl;
		int idForSearch;
		cin >> idForSearch;
		Employee *searchResult;
		searchResult = FileManager::searchForEmployee(idForSearch);
		if (searchResult != NULL)
		{
			searchResult->printInfo();
		}
		else
		{
			system("cls");
			cout << "wrong id" << endl;
		}
	};
	static void createEmployee(T *manger)
    {

        Employee *employee;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double sallary;
        cout << "FIRST NAME: ";
        cin >> firstName;
        cout << "LAST NAME: ";
        cin >> lastName;
        cout << "NATIONAL ID ";
        cin >> nationalId;
        cout << "PASSWORD : ";
        cin >> password;
        cout << "SALLARY :";
        cin >> sallary;
        employee = manger->createEmployee(firstName, lastName, nationalId, password, sallary);

        employee->setId(FileManager::getLastEmployeeId());
        FileManager::saveEmployee(employee);
        FileManager::UpdateLastEmployeeId();
        system("cls");
        cout << "DONE ! ^_^" << endl;
    }
    static void removeEmployee(T *manger)
    {
        cout << "PLEASE ENTER ID: ";
        Employee *employee;
        int id;
        cin >> id;
        employee = FileManager::searchForEmployee(id);
        if (employee != NULL)
        {
            bool isDeleted = FileManager::deleteEmployee(employee);
            manger->deleteEmployee(employee);
            system("cls");
            cout << "DONE ! ^_^" << endl;
        }
        else
        {
            cout << "EMPLOYEE DOESN't EXIST" << endl;
        }
    }
};

#endif
