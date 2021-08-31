//John Link, jwl9vq@virginia.edu, 8/31/21, bankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class bankAccount{

public:
    bankAccount(double amount = 0.00);
    ~bankAccount();
    double withdraw(double amount);
    double deposit(double amount);
    double getBalance() const;

private:
    double balance;

};
#endif
