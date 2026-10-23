#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    double balance;

public:

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0)
        {
            balance = 0;
            cout << "Invalid balance. Balance set to 0.\n";
        }

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        double amount;

        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance = balance + amount;

            cout << "Money Deposited Successfully!\n";
            cout << "New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw()
    {
        double amount;

        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid Amount!\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance = balance - amount;

            cout << "Money Withdrawn Successfully!\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }

    void showAccount()
    {
        cout << "\n-----------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << name << endl;
        cout << "Balance        : " << balance << endl;
        cout << "-----------------------------\n";
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    void saveAccount()
    {
        ofstream file("accounts.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }
};


int main()
{
    BankAccount account;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "=================================\n";
        cout << "      BANK MANAGEMENT SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Show Account Details\n";
        cout << "5. Save Account\n";
        cout << "6. Exit\n";

        cout << "=================================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.showAccount();
            break;

        case 5:
            account.saveAccount();
            cout << "\nAccount Saved Successfully!\n";
            break;

        case 6:
            cout << "\nThank You For Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}