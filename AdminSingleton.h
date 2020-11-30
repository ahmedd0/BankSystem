#ifndef ADMINSINGLETON_H
#define ADMINSINGLETON_H
#include "Admin.h"
class AdminSingleton
{
    // Private section

private:
    static Admin *instance;

public:
    AdmintSingleton() {}

    static Admin *login()
    {
        int id;
        string password;
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;
        Admin *logged = FileManager::searchForAdmin(id);
        ;
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
};

#endif
