#include <iostream>
#include <string>
#include <vector>


struct BankAccount {
    std::string NumberofAccount;
    std::string NameofOwner;
    double balance = 0.0;
};


short findIndex(const std::vector<BankAccount>& account, const std::string& Number){
    for (short i = 0; i < account.size(); i++){
        if (account[i].NumberofAccount == Number) return i;
    }
    return -1;
}


bool findAccount(const std::vector<BankAccount>& account, const std::string& Number){
    return findIndex(account, Number) != -1;
}


void CreareAccount(std::vector<BankAccount>& accounts){
    BankAccount newacc;

    std::cout << "Enter account number: ";
    std::cin >> newacc.NumberofAccount;

    if (findAccount(accounts, newacc.NumberofAccount)){
        std::cout << "Account number already exists\n";
        return;
    }

    std::cout << "Enter name of owner: ";
    std::cin.ignore();
    std::getline(std::cin, newacc.NameofOwner);

    accounts.push_back(newacc);
}


void AddMoney(std::vector<BankAccount>& account){
    std::string number;
    double summa = 0.0;

    std::cout << "Enter number of account: ";
    std::cin >> number;

    if (!findAccount(account, number)){
        std::cout << "Didn't find\n";
        return;
    }

    std::cout << "Enter sum to refill: ";
    std::cin >> summa;

    if (summa < 0){
        std::cout << "Summa must be pos\n";
        return;
    }

    account[findIndex(account, number)].balance += summa;

    std::cout << "Update balance: " << account[findIndex(account, number)].balance << "\n";
}


void Withdraw(std::vector<BankAccount>& account){
    double summa = 0.0;
    std::string numb;

    std::cout << "Enter number of account: ";
    std::cin >> numb;

    auto index = findIndex(account, numb);

    if (index == -1) return;

    std::cout << "Enter sum to withdraw: ";
    std::cin >> summa;

    if (summa < 0) return;

    if (summa > account[index].balance){
        std::cout << "Current balance: " << account[index].balance << "\n";
        return;
    }

    account[index].balance -= summa;
    std::cout << "New balance: " << account[index].balance << "\n";
}

void ShowAccount(const std::vector<BankAccount>& account){
    std::string number;

    std::cout << "Enter number of account:";
    std::cin >> number;

    auto ind = findIndex(account, number);

    if (ind == -1) return;

    std::cout << "Number of account: " << account[ind].NumberofAccount << ", Owner name" << account[ind].NameofOwner << ", Balance:" << account[ind].balance << "\n";
}


void Opr(){
    std::cout << "Create new bank account: 1\n";
    std::cout << "Add money to account: 2\n";
    std::cout << "Withdraw money: 3\n";
    std::cout << "Show account inf: 4\n";
    std::cout << "The end!: 5\n";
    std::cout << "Enter choice: ";
}


int main(){
    std::vector<BankAccount> account;
    short n = 0;

    do {
        Opr();
        std::cin >> n;

        switch (n){
            case 1:
                CreareAccount(account);
                break;
            case 2:
                AddMoney(account);
                break;
            case 3:
                Withdraw(account);
                break;
            case 4:
                ShowAccount(account);
                break;
            case 5:
                std::cout << "The end!\n";
                break;
            default:
                std::cout << "Unacceptable";
                std::cin.ignore();
        }
    } while (n != 5);

    return 0;
}