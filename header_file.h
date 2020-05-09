#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Account{
    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;
};


void menu(int*);

void makeAccount(vector<Account>& Accounts);
void printAccount(vector<Account>& Accounts);
void transfer(vector<Account>& Accounts);

void PrintAllAccounts(vector<Account>& Accounts);

void depositAccount(vector<Account>& Accounts);

void ActivateDeactivate(vector<Account>& Accounts);

void withdrawAccount(vector<Account>& Accounts);

void sortAccounts(vector<Account>& Accounts);

void deleteAccount(vector<Account>& Accounts);