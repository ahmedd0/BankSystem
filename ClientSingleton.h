#ifndef BANK_SYSTEM_CLION_CLIENTSINGLETON_H
#define BANK_SYSTEM_CLION_CLIENTSINGLETON_H

#include "FileManager.h"
#include "Menu.h"

class ClientSingleton
{

private:
    static Client *instance;

public:
    ClientSingleton() {}

    static Client *login()
    {
        int id;
        string password;
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;
        Client *logged = FileManager::searchForClient(id);
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
    static void destroyInstance()
    {
        instance = NULL;
    }
};

#endif //BANK_SYSTEM_CLION_CLIENTSINGLETON_H
