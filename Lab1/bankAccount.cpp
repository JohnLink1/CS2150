//John Link, jwl9vq@virginia.edu, 8/31/21, bankAccount.cpp
#include "bankAccount.h"
#include <iostream>

using namespace std;

bankAccount::bankAccount(double amount) : balance(amount){

}
bankAccount::~bankAccount(){

}

double bankAccount::withdraw(double amount){
    if(balance < amount){
        return balance;
    }
    balance = balance - amount;
    return balance;
}

double bankAccount::deposit(double amount){
    balance = balance + amount;
    return balance;
}

double bankAccount::getBalance() const{
    return balance;
}




