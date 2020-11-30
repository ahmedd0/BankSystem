#ifndef BANKCONTROL_H
#define BANKCONTROL_H
#include "Menu.h"
#include <unistd.h>
#include <string>
#include "EmployeeSingleton.h"
#include "AdminSingleton.h"
#include "EmployeeHelper.h"
#include "AdminHelper.h"
using namespace std;
class BankControl
{
private:
public:
    BankControl(){

    };
    static void loginScreen()
    {
        int choice = Menu::loginScreen();

        switch (choice)
        {
        case 1:
            system("cls");
            BankControl::clientScreen();

            break;
        case 2:
            system("cls");
            BankControl::employeeScreen();
            system("cls");
            break;
        case 3:
            system("cls");
            adminScreen();
            system("cls");
            break;
        default:
            system("cls");
            cout << "Wrong Choice" << endl;
            sleep(2);
            system("cls");
            loginScreen();
            break;
        }
    }
    static void clientScreen()
    {
        Client *singletonClient = ClientSingleton::login();
        system("cls");
        int choice;
        if (singletonClient != NULL)
        {
            do
            {
                choice = Menu::clientOptions();

                switch (choice)
                {
                case 1:
                    system("cls");
                    singletonClient->checkBalance();
                    break;
                case 2:
                    system("cls");
                    ClientHelper::withdraw(singletonClient);

                    break;
                case 3:
                    system("cls");
                    ClientHelper::deposite(singletonClient);

                    break;
                case 4:
                    system("cls");
                    ClientHelper::transfer(singletonClient);

                    break;
                case 5:
                    system("cls");
                    singletonClient->printInfo();
                    break;
                case 6:
                    system("cls");
                    BankControl::loginScreen();
                    break;

                default:
                    system("cls");
                    cout << "Wrong Choice" << endl;
                    sleep(2);
                    system("cls");
                    Menu::clientOptions();
                    break;
                }
                sleep(2);
                system("cls");
            } while (choice);
        }
        else
        {
            system("cls");
            cout << "WRONG ID OR PASSWORD PLEASE TRY AGAIN" << endl;
            sleep(1);
            system("cls");
            BankControl::loginScreen();
        }
    }
    static void employeeScreen()
    {

        Employee *singletonEmployee = EmployeeSingleton::login();
        int choice;
        if (singletonEmployee != NULL)
        {
            do
            {
                system("cls");
                choice = Menu::employeeOptions();
                switch (choice)
                {
                case 1:
                    system("cls");
                    singletonEmployee->printInfo();
                    break;
                case 2:
                {
                    system("cls");
                    EmployeeHelper<Employee>::printAllClient(singletonEmployee);
                }

                break;
                case 3:
                    system("cls");
                    EmployeeHelper<Employee>::searchForClient();
                    break;
                case 4:
                    EmployeeHelper<Employee>::deactivateClient(singletonEmployee);

                    break;
                case 5:
                    EmployeeHelper<Employee>::changePassword(singletonEmployee);

                    break;
                case 6:
                    system("cls");
                    EmployeeHelper<Employee>::createClient(singletonEmployee);

                    break;
                case 7:
                    EmployeeHelper<Employee>::removeClient(singletonEmployee);

                    break;
                case 8:
                    system("cls");
                    BankControl::loginScreen();
                    //EmployeeSingleton::destroyEmployee();
                    break;

                // if Option not 1 ,2 or ... ==> Run the  ption Function Again!
                default:
                    system("cls");
                    cout << "Wrong Choice" << endl;
                    break;
                }
                sleep(2);
                system("cls");
            } while (choice != 8);
        }
        else
        {
            system("cls");
            cout << "WRONG ID OR PASSWORD PLEASE TRY AGAIN" << endl;
            sleep(1);
            system("cls");
            BankControl::loginScreen();
        }
    }
    static void adminScreen()
    {

        Admin *singletonAdmin = AdminSingleton::login();
        int choice;
        if (singletonAdmin != NULL)
        {
            do
            {
                system("cls");
                choice = Menu::adminOptions();
                switch (choice)
                {
                case 1:
                    system("cls");
                    singletonAdmin->printInfo();
                    break;
                case 2:
                {
                    system("cls");
                    AdminHelper<Admin>::printAllClient(singletonAdmin);
                }

                break;
                case 3:
                    system("cls");
                    AdminHelper<Admin>::searchForClient();
                    break;
                case 4:
                    AdminHelper<Admin>::deactivateClient(singletonAdmin);

                    break;
                case 5:
                    AdminHelper<Admin>::changePassword(singletonAdmin);

                    break;
                case 6:
                    system("cls");
                    AdminHelper<Admin>::createClient(singletonAdmin);

                    break;
                case 7:
                    AdminHelper<Admin>::removeClient(singletonAdmin);
                    break;
                case 8:
                    system("cls");
                    AdminHelper<Admin>::printAllEmployees(singletonAdmin);
                    break;
                case 9:
                    system("cls");
                    AdminHelper<Admin>::searchForEmployee();
                    break;
                case 10:
                    system("cls");
                    AdminHelper<Admin>::createEmployee(singletonAdmin);
                    break;
                case 11:
                    system("cls");
                    AdminHelper<Admin>::removeEmployee(singletonAdmin);
                    break;
                case 12:
                    system("cls");
                    BankControl::loginScreen();
                    //EmployeeSingleton::destroyEmployee();
                    break;
                default:
                    system("cls");
                    cout << "Wrong Choice" << endl;
                    break;
                }
                sleep(2);
                system("cls");
            } while (choice != 13);
        }
        else
        {
            system("cls");
            cout << "WRONG ID OR PASSWORD PLEASE TRY AGAIN" << endl;
            sleep(1);
            system("cls");
            BankControl::loginScreen();
        }
    }
};

#endif
