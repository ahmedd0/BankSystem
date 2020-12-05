#ifndef CLIENTHELPER_H
#define CLIENTHELPER_H
class ClientHelper
{
    // Private section
public:
    ClientHelper()
    {
    }
    static void withdraw(Client *singletonClient)
    {
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
    }
    static void deposite(Client *singletonClient)
    {
        cout << "PLEASE ENTER DEPOSITE AMOUNT" << endl;
        double depositAmount;
        cin >> depositAmount;
        singletonClient->deposit(depositAmount);
        FileManager::updateClient(singletonClient);
        system("cls");
        cout << "DONE ! ^_^" << endl;
    }
    static void transfer(Client *singletonClient)
    {
        cout << "PLEASE ENTER AMOUNT" << endl;
        double transferValue;
        cin >> transferValue;
        cout << "PLEASE ENTER ACCOUNT ID" << endl;
        int receiverId;
        cin >> receiverId;
        Client *receiverClient;
        receiverClient = FileManager::searchForClient(receiverId);
        if (receiverClient != NULL)
        {
        	if(transferValue<=singletonClient->getBalance()){
        		singletonClient->transferMoney(transferValue, receiverClient);
            FileManager::updateClient(singletonClient);
            FileManager::updateClient(receiverClient);
            system("cls");
            cout << "DONE ! ^_^" << endl;
			}else{
				system("cls");
				cout<<"SORRY YOUT BALANCE IS LESS THAN THE RQUIRE AMOUNT"<<endl;
			}
            
        }
        else
        {
            system("cls");
            cout << "SORRY THERE IS NO CLIENT WITH THIS ID" << endl;
        }
    }
};

#endif
