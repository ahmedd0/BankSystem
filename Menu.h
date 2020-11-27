#ifndef BANK_SYSTEM_COPY_MENU_H
#define BANK_SYSTEM_COPY_MENU_H

#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "ClientSingleton.h"
#include "EmployeeSingleton.h"
#include "FileManager.h"

using namespace std;

class Menu
{

private:
    Menu()
    {
    }

public:
    static void welcomeScreen()
    {
        cout << "============================================" << endl;
        cout << "===        Welcome to Bank System        ===" << endl;
        cout << "============================================" << endl;
        sleep(3);
    }

    static int loginScreen()
    {
        int choice;

        cout << "1 - Login as Client" << endl;
        cout << "2 - Login as Employee" << endl;
        cout << "3 - Login as Admin" << endl;
        cout << "=======================================" << endl;
        cin >> choice;
        return choice;
    }

    static int clientOptions()
    {
        int choice;

        cout << "1 - CHECK BALANCE" << endl;
        cout << "2 - WITHDRAW" << endl;
        cout << "3 - DEPOSIT" << endl;
        cout << "4 - TRANSFER MONEY" << endl;
        cout << "5 - PRINT ALL INFORMATION" << endl;
        cout << "6 - LOG OUT" << endl;
        cout << "==================================" << endl;
        cout << "please Insert Option from 1 to 6" << endl;
        cin >> choice;
        return choice;
    }

    static int employeeOptions()
    {

        int choice;

        cout << "(1) PRINT INFO" << endl;
        cout << "(2) PRINT ALL ACCOUNTS" << endl;
        cout << "(3) SEARCH FOR AN ACCOUNT" << endl;
        cout << "(4) DEACTIVATE" << endl;
        cout << "(5) CHANGE PASSWORD" << endl;
        cout << "(6) CREATE ACCOUNT" << endl;
        cout << "(7) REMOVE ACCOUNT" << endl;
        cout << "(8) LOG OUT" << endl;

        cout << "==================================" << endl;
        cout << "please Insert Option from 1 to 7" << endl;
        cin >> choice;
        return choice;
    }
    static int adminOptions()
    {

        int choice;

        cout << "(1) PRINT INFO" << endl;
        cout << "(2) PRINT ALL CLIENTS" << endl;
        cout << "(3) SEARCH FOR AN CLIENT" << endl;
        cout << "(4) DEACTIVATE CLIENT" << endl;
        cout << "(5) CHANGE PASSWORD" << endl;
        cout << "(6) CREATE ACCOUNT" << endl;
        cout << "(7) PRINT ALL EMPLOYEES" << endl;
        cout << "(8) SEARCH FOR AN EMPLOYEE" << endl;
        cout << "(9) DEACTIVATE EMPLOYEE" << endl;
        cout << "(10) CREATE EMPLOYEE" << endl;
        cout << "(11) LOG OUT" << endl;

        cout << "==================================" << endl;
        cout << "please Insert Option from 1 to 11" << endl;
        cin >> choice;
        return choice;
    }
};

#endif //BANK_SYSTEM_COPY_MENU_H
