#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <fstream>
#include "Client.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;

class FileManager
{
public:
    FileManger()
    {
    }
    //----------------------- Save Client To File
    static void saveClient(Client *client)
    {
        // open the clients file and appent data to it
        ofstream clientsFile("client.txt", ios_base::app);
        // add line(id firstname lastname balance)
        clientsFile << client->getId() << " " << client->getFirstName() << " " << client->getLastName() << " " << client->getNationalId() << " " << client->getPassword() << " " << client->getBalance() << endl;
        // close the file
        clientsFile.close();
    }
    // ------------------------ Delete Client From File
    static bool deleteClient(Client *client)
    {
        int err = 0;
        fstream clientsFile;
        fstream temp;
        // open client file
        clientsFile.open("client.txt", ios::in);
        // open and create temp file to copy data from client file to it.
        // without the client that we want to delete
        temp.open("temp.txt", ios::out);
        // file data (id ,firstnam,lastname,balance)
        int clientID;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double balance;
        // loop on file and copy new data to temp.txt
        while (clientsFile >> clientID >> firstName >> lastName >> nationalId >> password >> balance)
        {

            if (client->getId() != clientID)
            {

                temp << clientID << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << balance << endl;
            }
            else
            {
                // Increase err by 1 if Cleint exist
                err++;
            }
        }

        clientsFile.close();
        // remove clients.txt
        remove("client.txt");
        temp.close();

        rename("temp.txt", "client.txt");
        // IF err == 0 == > the ACCOUNT DOESN"T EXIST IN DATA BASE
        if (err == 0)
        {
            return false;
        }
        // IF ERR > 0 ==> CLIENT DELETED
        else
        {
            return true;
        }
    }
    //----------------------------- UPDATE CLIENT DATA
    static bool updateClient(Client *client)
    {
        int err = 0;
        fstream clientsFile;
        fstream temp;
        // open client file
        clientsFile.open("client.txt", ios::in);
        // open and create temp file to copy data from client file to it.
        // without the client that we want to delete
        temp.open("temp.txt", ios::out);
        // file data (id ,firstnam,lastname,balance)
        int clientID;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double balance;
        // loop on file and copy new data to temp.txt
        while (clientsFile >> clientID >> firstName >> lastName >> nationalId >> password >> balance)
        {

            if (client->getId() == clientID)
            {
                firstName = client->getFirstName();
                lastName = client->getLastName();
                nationalId = client->getNationalId();
                password = client->getPassword();
                balance = client->getBalance();
                temp << clientID << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << balance << endl;
                err++;
            }
            else
            {
                // Increase err by 1 if Cleint exist
                temp << clientID << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << balance << endl;
            }
        }

        clientsFile.close();
        // remove clients.txt
        remove("client.txt");
        temp.close();
        rename("temp.txt", "client.txt");
        // IF err == 0 == > the ACCOUNT DOESN"T EXIST IN DATA BASE
        if (err == 0)
        {
            return false;
        }
        // IF ERR > 0 ==> CLIENT DELETED
        else
        {
            return true;
        }
    }
    //------------------------------ GET ALL ACCOUNT IN RETURN MAP
    static map<int, Client *> getAllClients()
    {
        // CREATE MAP
        map<int, Client *> allClients;
        // FILE VARIABLE
        int clientID;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double balance;
        fstream clientsFile;
        // open client file
        clientsFile.open("client.txt", ios::in);

        // LOOP THROUGH FILE
        while (clientsFile >> clientID >> firstName >> lastName >> nationalId >> password >> balance)
        {
            //COPY EVERY LINE INTO CLIENT OBJECT
            Client *client = new Client(firstName, lastName, nationalId, password, balance);
            client->setId(clientID);
            //ADD OBJECT INTO MAP
            allClients[clientID] = client;
        }
        //CLOSE FILE
        clientsFile.close();
        //RETURN THE MAP
        return allClients;
    }
    // ------------------------------------ GET CLIENT BY ID AND RETURN IT
    static Client *searchForClient(int id)
    {
        fstream clientsFile;
        // open client file
        clientsFile.open("client.txt", ios::in);
        // FILE VARIABLE
        int clientID;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double balance;
        int err = 0;
        Client *client;
        // CREATE OBJECT (CLIENT)

        //LOOP THROUGH FILE
        while (clientsFile >> clientID >> firstName >> lastName >> nationalId >> password >> balance)
        {

            if (clientID == id)
            {
                client = new Client(firstName, lastName, nationalId, password, balance);
                client->setId(clientID);
                err++;
            }
        }
        if (err == 0)
        {
            return NULL;
        }
        else
        {
            return client;
        }
    }
    // get last id++
    static int getLastClientId()
    {
        int lastId;
        fstream lastClientId;
        lastClientId.open("clientId.txt", ios::in);
        lastClientId >> lastId;
        lastClientId.close();
        lastId++;
        return lastId;
    }
    // update last id in file
    static void UpdateLastClientId()
    {
        int lastId;
        fstream lastClientId;
        lastClientId.open("clientId.txt", ios::in);
        lastClientId >> lastId;
        lastId++;
        lastClientId.close();
        lastClientId.open("clientId.txt", ios::out);
        lastClientId << lastId;
        lastClientId.close();
    }
    // =================================================================================
    // EMPLOYEE FILE MANGER FUNCTIONS
    //==================================================================================
    //----------------------- Save Employee To File
    static void saveEmployee(Employee *employee)
    {
        // open the employees file and appent data to it
        ofstream employeesFile("employee.txt", ios_base::app);
        // add line(id firstname lastname sallary)
        employeesFile << employee->getId() << " " << employee->getFirstName() << " " << employee->getLastName() << " " << employee->getNationalId() << " " << employee->getPassword() << " " << employee->getSallary() << endl;
        // close the file
        employeesFile.close();
    }
    // UPDATE EMPLOYEE DATA
    static bool updateEmployee(Employee *employee)
    {
        int err = 0;
        fstream employeesFile;
        fstream tempE;
        // open employees file
        employeesFile.open("employee.txt", ios::in);
        // open and create temp file to copy data from client file to it.
        // without the employees that we want to delete
        tempE.open("tempE.txt", ios::out);
        // file data (id ,firstnam,lastname,balance)
        int employeeId;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double sallary;
        // loop on file and copy new data to temp.txt
        while (employeesFile >> employeeId >> firstName >> lastName >> nationalId >> password >> sallary)
        {

            if (employee->getId() == employeeId)
            {
                firstName = employee->getFirstName();
                lastName = employee->getLastName();
                nationalId = employee->getNationalId();
                password = employee->getPassword();
                sallary = employee->getSallary();

                tempE << employeeId << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << sallary << endl;
                err++;
            }
            else
            {
                tempE << employeeId << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << sallary << endl;
            }
        }

        employeesFile.close();
        // remove EMPLOYEEs.txt
        remove("employee.txt");
        tempE.close();
        rename("tempE.txt", "employee.txt");
        // IF err == 0 == > the EMPLOYEE DOESN"T EXIST IN DATA BASE
        if (err == 0)
        {
            return false;
        }
        // IF ERR > 0 ==> CLIENT DELETED
        else
        {
            return true;
        }
    }
    // ------------------------ Delete Employee From File
    static bool deleteEmployee(Employee *employee)
    {
        int err = 0;
        fstream employeesFile;
        fstream tempE;
        // open employees file
        employeesFile.open("employee.txt", ios::in);
        // open and create temp file to copy data from client file to it.
        // without the employees that we want to delete
        tempE.open("tempE.txt", ios::out);
        // file data (id ,firstnam,lastname,balance)
        int employeeId;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double sallary;
        // loop on file and copy new data to temp.txt
        while (employeesFile >> employeeId >> firstName >> lastName >> nationalId >> password >> sallary)
        {

            if (employee->getId() != employeeId)
            {

                tempE << employeeId << " " << firstName << " " << lastName << " " << nationalId << " " << password << " " << sallary << endl;
            }
            else
            {
                // Increase err by 1 if employee exist
                err++;
            }
        }

        employeesFile.close();
        // remove EMPLOYEEs.txt
        remove("employee.txt");
        tempE.close();
        rename("tempE.txt", "employee.txt");
        // IF err == 0 == > the EMPLOYEE DOESN"T EXIST IN DATA BASE
        if (err == 0)
        {
            return false;
        }
        // IF ERR > 0 ==> CLIENT DELETED
        else
        {
            return true;
        }
    }

    //------------------------------ GET ALL ACCOUNT IN RETURN MAP
    static map<int, Employee *> getAllEmployee()
    {
        // CREATE MAP
        map<int, Employee *> allEmployees;
        // FILE VARIABLE
        int employeeId;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double sallary;
        fstream employeesFile;
        // open client file
        employeesFile.open("employee.txt", ios::in);

        // LOOP THROUGH FILE
        while (employeesFile >> employeeId >> firstName >> lastName >> nationalId >> password >> sallary)
        {
            //COPY EVERY LINE INTO CLIENT OBJECT
            Employee *client = new Employee(firstName, lastName, nationalId, password, sallary);
            client->setId(employeeId);
            //ADD OBJECT INTO MAP
            allEmployees[employeeId] = client;
        }
        //CLOSE FILE
        employeesFile.close();
        //RETURN THE MAP
        return allEmployees;
    }
    // ------------------------------------ GET CLIENT BY ID AND RETURN IT
    static Employee *searchForEmployee(int id)
    {
        fstream employees;
        // open client file
        employees.open("employee.txt", ios::in);
        // FILE VARIABLE
        int employeeId;
        string firstName;
        string lastName;
        string nationalId;
        string password;
        double sallary;
        int err = 0;
        Employee *employee;
        //LOOP THROUGH FILE
        while (employees >> employeeId >> firstName >> lastName >> nationalId >> password >> sallary)
        {

            if (employeeId == id)
            {
                // CREATE OBJECT (CLIENT)
                employee = new Employee(firstName, lastName, nationalId, password, sallary);
                employee->setId(employeeId);
                err++;
            }
        }
        if (err == 0)
        {
            return NULL;
        }
        else
        {
            return employee;
        }
    }

    // get last id++
    static int getLastEmployeeId()
    {
        int lastId;
        fstream lastEmployeeId;
        lastEmployeeId.open("employeeId.txt", ios::in);
        lastEmployeeId >> lastId;
        lastEmployeeId.close();
        lastId++;
        return lastId;
    }
    // update last id in file
    static void UpdateLastEmployeeId()
    {
        int lastId;
        fstream lastEmployeeId;
        lastEmployeeId.open("employeeId.txt", ios::in);
        lastEmployeeId >> lastId;
        lastId++;
        lastEmployeeId.close();
        lastEmployeeId.open("employeeId.txt", ios::out);
        lastEmployeeId << lastId;
        lastEmployeeId.close();
    }
};

#endif
