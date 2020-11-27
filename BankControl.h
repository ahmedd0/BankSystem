#ifndef BANKCONTROL_H
#define BANKCONTROL_H
#include "Menu.h"
#include <unistd.h>
#include <string>
#include "EmployeeSingleton.h"
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
            //                    loginAsAdmin();
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
        Client *singletonClient = ClientSingleton::loginAsClient();
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
                    double withdrawAmount;
                    cout << "PLEASE ENTER WITHDRAW AMOUNT" << endl;
                    cin >> withdrawAmount;
                    if (withdrawAmount > singletonClient->getBalance())
                    {
                        system("cls");
                        cout << "SORRY YOUT BALANCE IS LESS THAN THE RQUIRE AMOUNT" << endl;
                    }
                    else
                    {
                        singletonClient->withdraw(withdrawAmount);
                        FileManager::updateClient(singletonClient);
                        system("cls");
                        cout << "DONE ! ^_^" << endl;
                    }

                    break;
                case 3:
                    system("cls");
                    cout << "PLEASE ENTER DEPOSITE AMOUNT" << endl;
                    double depositAmount;
                    cin >> depositAmount;
                    singletonClient->deposit(depositAmount);
                    FileManager::updateClient(singletonClient);
                    system("cls");
                    cout << "DONE ! ^_^" << endl;
                    break;
                case 4:
                    system("cls");
                    cout << "PLEASE ENTER AMOUNT" << endl;
                    double transferValue;
                    cin >> transferValue;
                    cout << "PLEASE ENTER ACCOUNT ID" << endl;
                    int receiverId;
                    cin >> receiverId;
                    Client *receiverClient;
                    receiverClient = FileManager::searchForClient(receiverId);
                    singletonClient->transferMoney(transferValue, receiverClient);
                    FileManager::updateClient(singletonClient);
                    //FileManager::updateClient(receiverClient);

                    system("cls");
                    cout << "DONE ! ^_^" << endl;
                    break;
                case 5:
                    system("cls");
                    singletonClient->printInfo();
                    break;
                case 6:
                    system("cls");
                    //singletonClient->logout();
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

        Employee *singletonEmployee = EmployeeSingleton::loginAsEmployee();
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
                    map<int, Client *> clients = FileManager::getAllClients();
                    singletonEmployee->printAllClients(clients);
                }

                break;
                case 3:
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

                    break;
                case 4:
                    system("cls");
                    cout << "PLEASE ENTER ACCOUNT ID" << endl;
                    cin >> idForSearch;
                    searchResult = FileManager::searchForClient(idForSearch);
                    singletonEmployee->deactivateClient(searchResult);
                    break;
                case 5:
                {
                    system("cls");
                    cout << "Enter new password: ";
                    string password;
                    cin >> password;
                    singletonEmployee->changePassword(password);
                    FileManager::updateEmployee(singletonEmployee);
                    system("cls");
                    cout << "DONE ! ^_^" << endl;
                }

                break;
                case 6:
                {
                    system("cls");
                    Client *client;
                    string firstName = "";
                    string lastName;
                    string nationalId;
                    string password;
                    double balance;
                    cout << "FIRST NAME: ";
                    cin >> firstName;
                    cout << endl;
                    cout << "LAST NAME: ";
                    cin >> lastName;
                    cout << endl;
                    cout << "NATIONAL ID ";
                    cin >> nationalId;
                    cout << endl;
                    cout << "PASSWORD : ";
                    cin >> password;
                    cout << endl;
                    cout << "BALANCE :" << endl;
                    cin >> balance;
                    client = singletonEmployee->createClient(firstName, lastName, nationalId, password, balance);

                    client->setId(FileManager::getLastClientId());
                    FileManager::saveClient(client);
                    FileManager::UpdateLastClientId();
                    system("cls");
                    cout << "DONE ! ^_^" << endl;
                }

                break;
                case 7:
                {
                    cout << "PLEASE ENTER ID: ";
                    Client *client;
                    int id;
                    cin >> id;
                    client = FileManager::searchForClient(id);
                    if (client != NULL)
                    {
                        bool isDeleted = FileManager::deleteClient(client);
                        singletonEmployee->deleteClient(client);
                        system("cls");
                        cout << "DONE ! ^_^" << endl;
                    }
                    else
                    {
                        cout << "CLIENT DOESN't EXIST" << endl;
                    }
                }

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
};

#endif
