#include "header_file.h"
using std::vector;
using namespace std;
int main() {
    vector<Account> bankAccounts;
    srand(time(NULL));
    int input = 0;
    while(input!=9)
    {
        menu(&input);
        switch (input)
        {
            case 1:
                makeAccount(bankAccounts);
                sortAccounts(bankAccounts);
                break;
            case 2:
                depositAccount(bankAccounts);
                break;
            case 3:
                withdrawAccount(bankAccounts);
                break;
            case 4:
                transfer(bankAccounts);
                break;
            case 5:
                printAccount(bankAccounts);
                break;
            case 6:
                ActivateDeactivate(bankAccounts);
                break;
            case 7:
                deleteAccount(bankAccounts);
                break;
            case 8:
                PrintAllAccounts(bankAccounts);
                break;
            case 9:
                cout << "Bank is closed!";
                break;
            default:
                cout<<"Invalid input";
                break;
        }
    }
}