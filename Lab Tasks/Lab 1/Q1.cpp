#include <iostream>
using namespace std;

class BankAccount {
    private:
    string accName;
    float balance;

    public:

    // Default Constructor
    BankAccount() {
        accName = "Unidentified User";
        balance = 0;
        cout << "Welcome to the platform" << endl;
    } 
    
    // Parameterized Constructor
    BankAccount(string n, float b) {
        accName = n;
        balance = b;
        cout << "Welcome to the platform, " << accName << endl;
    }

    // Copy Constructor
    BankAccount(const BankAccount &copy) {
        accName = copy.accName + " copy";
        balance = copy.balance;
        cout << "Account copied for " << accName << endl;
    }

    // Display

    void showBalance() {
        cout << "Account: " << accName << " - Balance is: $" << balance << endl;
    }

    // Setters

    void deposit(float dep) {
        balance += dep;
        cout << "Account: " << accName << " - Deposited $" << dep << endl;
        cout << "Account: " << accName << " - New balance: $" << balance << endl;
    }
    
    void withdraw(float wit) {
        if (wit > balance) {
            cout << "Account: " << accName << " - Balance is low, withdraw not possible." << endl;
        }   else    {
            balance -= wit;
            cout << "Account: " << accName << " - Withdrawn $" << wit << endl;
            cout << "Account: " << accName << " - New balance: $" << balance << endl;
        }
    }

};

int main() {

    BankAccount account1;
    account1.showBalance();

    cout << endl;
    
    BankAccount account2("Talha", 1000);
    account2.showBalance();
    
    cout << endl;
    
    BankAccount account3(account2);
    account3.withdraw(200);
    account3.showBalance();
    
    cout << endl;

    account2.showBalance();
}