#ifndef EMPLOYEEHELPER_H
#define EMPLOYEEHELPER_H
#include "ClientHelper.h"
template <class T>
class EmployeeHelper
{
public:
    ControlHelper()
    {
    }
    // all method

    static void searchForClient()
    {
        system("cls");
        cout << "PLEASE ENTER ACCOUNT ID" << endl;
        int idForSearch;
        cin >> idForSearch;
        Client *searchResult;
        searchResult = FileManager::searchForClient(idForSearch);
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
    static void printAllClient(T *manger)
    {
        map<int, Client *> clients = FileManager::getAllClients();
        manger->printAllClients(clients);
    }
    static void changePassword(T *manger)
    {
        system("cls");
        cout << "Enter new password: ";
        string password;
        cin >> password;
        manger->changePassword(password);
        FileManager::updateEmployee(manger);
        system("cls");
        cout << "DONE ! ^_^" << endl;
    }
    static void deactivateClient(T *manger)
    {
        system("cls");
        cout << "PLEASE ENTER ACCOUNT ID" << endl;
        int idForSearch;
        cin >> idForSearch;
        Client *searchResult = FileManager::searchForClient(idForSearch);
        manger->deactivateClient(searchResult);
    }
    static void createClient(T *manger)
    {

        Client *client;
        string firstName = "";
        string lastName;
        string nationalId;
        string password;
        double balance;
        cout << "FIRST NAME: ";
        cin >> firstName;
        cout << "LAST NAME: ";
        cin >> lastName;
        cout << "NATIONAL ID ";
        cin >> nationalId;
        cout << "PASSWORD : ";
        cin >> password;
        cout << "BALANCE :";
        cin >> balance;
        client = manger->createClient(firstName, lastName, nationalId, password, balance);

        client->setId(FileManager::getLastClientId());
        FileManager::saveClient(client);
        FileManager::UpdateLastClientId();
        system("cls");
        cout << "DONE ! ^_^" << endl;
    }
    static void removeClient(T *manger)
    {
        cout << "PLEASE ENTER ID: ";
        Client *client;
        int id;
        cin >> id;
        client = FileManager::searchForClient(id);
        if (client != NULL)
        {
            bool isDeleted = FileManager::deleteClient(client);
            manger->deleteClient(client);
            system("cls");
            cout << "DONE ! ^_^" << endl;
        }
        else
        {
            cout << "CLIENT DOESN't EXIST" << endl;
        }
    }
};

#endif
