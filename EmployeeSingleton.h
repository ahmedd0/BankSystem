
#ifndef BANK_SYSTEM_CLION_EMPLOYEESINGLETON_H
#define BANK_SYSTEM_CLION_EMPLOYEESINGLETON_H
#include "Employee.h"
#include "FileManager.h"
class EmployeeSingleton
{

private:
    static Employee *instance;

public:
    EmployeeSingleton() {}
    static Employee *loginAsEmployee()
    {
        int id;
        string password;
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;
        Employee *logged = FileManager::searchForEmployee(id);
        if (logged != NULL)
        {
            if (logged->getPassword() == password)
            {
                return logged;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            return NULL;
        }
    }
    static void destroyEmployee()
    {
        instance = NULL;
    }
};
#endif //BANK_SYSTEM_CLION_EMPLOYEESINGLETON_H
