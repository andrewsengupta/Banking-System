#include "header_file.h"


void menu(int *num)
{
    int select = 0;
    cout << "Welcome! Select options below:" << endl;
    cout << "\t1. Make new account."
         << "\n\t2. Deposit to an account."
         << "\n\t3. Withdraw from an account."
         << "\n\t4. Transfer money."
         << "\n\t5. Print account."
         << "\n\t6. Activate/Deactivate an account."
         << "\n\t7. Delete an account."
         << "\n\t8. Display all accounts."
         << "\n\t9. Quit." << endl;
    cout << "Selection:\t";
        cin >> select;
        *num = select;
    while (!(select>=1 && select<=9))
    {
        cout<<"Select number between 1 and 9";
        cin>>select;
    }
*num=select;
}


void makeAccount(vector<Account>& Accounts)
{
    int randomAccountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active = true;
    Account newaccount;
    while (active) {
        active = false;
        randomAccountNumber = rand() % 9000 + 1000;
        for (int i = 0; i < Accounts.size(); i++) {
            if (Accounts[i].accountNumber = randomAccountNumber)
            {
                active = true;

            }
            if (!active)
            {
                break;
            }

        }
    }
    cout << "Creating bank account number: " << randomAccountNumber << endl;
    cout<<"Enter first name: ";
    cin>>firstName;
    cout<<"Enter last name: ";
    cin>>lastName;
    cout<<"Enter starting balance: ";
    cin>>accountBalance;
    newaccount.accountNumber=randomAccountNumber;
    newaccount.accountBalance=accountBalance;
    newaccount.lastName=lastName;
    newaccount.firstName=firstName;
    newaccount.active=true;
    Accounts.push_back(newaccount);
}

void depositAccount(vector<Account>& Accounts)
{
    double depositamount;
    int accountNumber;
    cout<<"Enter account number for deposit: ";
    cin>>accountNumber;
    cout<<"Amount to be deposited: ";
    cin>>depositamount;


    bool taken= false;
    for (int i=0;i<Accounts.size();i++)
    {
        if (Accounts[i].accountNumber==accountNumber)
        {
            Accounts[i].accountBalance+=depositamount;
            bool taken= true;
            break;
        }
        if (!taken)
        {
            cout<<"The account does not exist."<<endl;
        }
    }
}

void withdrawAccount(vector<Account>& Accounts)
{
    double withdrawalamount;
    int accountNumber;
    cout<<"Enter account number for withdrawal: ";
    cin>>accountNumber;
    cout<<"Enter amount to be withdrawn: ";
    cin>>withdrawalamount;


    bool taken= false;
    for (int i=0;i<Accounts.size();i++)
    {
        if (Accounts[i].accountNumber==accountNumber)
        {
            Accounts[i].accountBalance-=withdrawalamount;
            bool taken= true;
            break;
        }
        if (!taken)
        {
            cout<<"The account does not exist."<<endl;
        }
    }
}

void deleteAccount(vector<Account>& Accounts)
{
    int accountNumber;
    bool taken = false;
    cout<<"Enter account number to be deleted: ";
    cin>>accountNumber;
    for (int i=0; i<Accounts.size();i++)
    {
        if (Accounts[i].accountNumber==accountNumber)
        {
            Accounts.erase(Accounts.begin()+i);
            bool taken= true;
            cout<<"The account has been deleted."<<endl;
            break;
        }
        if (!taken)
        {
            cout<<"The account does not exist."<<endl;
        }
    }
}

void PrintAllAccounts(vector<Account>& Accounts)
{
    for (int i=0; i<Accounts.size(); i++)
    {
        cout<<"Account number: "<<Accounts[i].accountNumber<<"\t Balance: "<<Accounts[i].accountBalance<<endl;
        cout<<"Last name: "<<Accounts[i].lastName<<"\t First name: "<<Accounts[i].firstName<<endl;
    }
}

void printAccount(vector<Account>& Accounts){
    int accountNumber;
    bool taken= false;
    cout<<"Enter account number to print ";
    cin>>accountNumber;

    for (int i=0; i<Accounts.size(); i++)
    {
        if (Accounts[i].accountNumber==accountNumber)
        {
            cout<<"Account number: "<<Accounts[i].accountNumber<<"\t Balance: "<<Accounts[i].accountBalance<<endl;
            cout<<"Last name: "<<Accounts[i].lastName<<"\t First name: "<<Accounts[i].firstName<<endl;
            bool taken= true;
            break;
        }
        if (!taken)
        {
            cout<<"The account does not exist."<<endl;
        }
    }
}


void transfer(vector<Account>& Accounts)
{
    int senderaccountNumber;
    int receiveraccountNumber;
    double transferamount;
    bool taken = false;
    cout << "Enter account number for the sender: ";
    cin >> senderaccountNumber;
    for (int i = 0; i < Accounts.size(); i++) {
        if (Accounts[i].accountNumber == senderaccountNumber)
        {
            cout<<"Enter account number for the receiver: ";
            cin>>receiveraccountNumber;
            for (int i=0; i<Accounts.size(); i++)
            {
                if (Accounts[i].accountNumber==receiveraccountNumber)
                {
                    cout<<"Enter amount to be transferred: ";
                    cin>>transferamount;
                    for (int i=0; i<Accounts.size(); i++)
                    {
                        if (Accounts[i].accountNumber==senderaccountNumber)
                        {
                            if (transferamount<=Accounts[i].accountBalance)
                            {
                                Accounts[i].accountBalance+=transferamount;
                                bool taken=true;
                                break;
                            }
                        }
                    }
                }
                if (!taken)
                {
                    cout << "The account does not exist." << endl;
                }

            }
        }
        if (!taken) {
            cout << "The account does not exist." << endl;
        }
    }
}


void sortAccounts(vector<Account>& Accounts)
{
    int i,j;
    int temp=0;
    for (i=0; i<Accounts.size(); i++)
    {
        for (j=0; j<Accounts.size()-1; j++)
        {
            if (Accounts[j].accountNumber>Accounts[j+1].accountNumber)
            {
                temp= Accounts[j].accountNumber= Accounts[j+1].accountNumber;
                Accounts[j+1].accountNumber=temp;
            }
        }
    }
}

void ActivateDeactivate(vector<Account> & Accounts)
{

    bool taken=false;
    int index=0;
    int accountNumber;
    cout<<"Enter account number for activation/deactivation: ";
    cin>>accountNumber;

    for (int i=0; i<Accounts.size(); i++)
    {
        if (Accounts[i].accountNumber==accountNumber)
        {
            int option;
            taken=true;
            int index=i;
            cout<<"Press 1 to activate, 0 to deactivate: ";
            cin>>option;
            if (option==1)
            {
                Accounts[index].active=true;
                cout<<"The account has been activated."<<endl;

            }
            else if (option==0)
            {
                Accounts[index].active=false;
                cout<<"The account has been deactivated."<<endl;

            }
            else
            {
                cout<<"Invalid input"<<endl;
            }

        }

    }
    if (!taken)
    {
        cout<<"The account does not exist."<<endl;
    }

}