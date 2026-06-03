#include <iostream>
#include <string>
#include <iomanip> //iomanipulator for formatting output
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // constructor to initialize the bank account with account holder's name, account number, and initial balance
    BankAccount(string acchold, int accnum, double bal)
    {
        accountHolder = acchold;
        accountNumber = accnum;
        balance = bal;
    }
    // deposit method to add money to the account
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. New balance: " << setprecision(2) << balance << endl; // setprecision(2) to display balance with 2 decimal places
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }
    // withdraw method to subtract money from the account if sufficient funds are available
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << setprecision(2) << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
    // displatInfo method to show the account details including account holder's name, account number, and current balance
    void displayInfo()
    {
        cout << "------Account Details------" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << setprecision(2) << balance << endl;
    }
    // getters
    string getaccountHolder()
    {
        return accountHolder;
    }
    int getaccountNumber()
    {
        return accountNumber;
    }
    double getbalance()
    {
        return balance;
    }
    // setters
    void setaccountHolder(string newHolder)
    {
        accountHolder = newHolder;
    }
};

int main()
{
    // Two object account1 and account2 are created using the BankAccount class constructor
    BankAccount account1("John Doe", 123456, 1000.0);
    BankAccount account2("Rahul", 156430, 16489.125);

    cout << "----Operations on account1---- " << endl;
    account1.deposit(500.50);  // Deposit money into account1
    account1.withdraw(200.25); // Withdraw money from account1
    cout << endl;

    cout << "----Operations on account2---- " << endl;
    account2.deposit(1000.00); // Deposit money into account2
    account2.withdraw(500.00); // Withdraw money from account2
    cout << endl;

    cout << "----Attempt Invalid Withdrawal---- " << endl;
    account1.withdraw(2000.00); // Attempt to withdraw more than the balance from account1
    cout << endl;

    account1.displayInfo(); // Display account1 information
    cout << endl;
    account2.displayInfo(); // Display account2 information

    return 0;
}