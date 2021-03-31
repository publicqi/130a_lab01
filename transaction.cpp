#include "transaction.h"
#include <iostream>

using namespace std;

Transaction::Transaction(Transaction* previous){
    if(previous == NULL){
        this->hash = "";
    }
    else{
        this->hash = previous->genHash();
    }
    this->prev = previous;
}

void Transaction::addTxn(int amount, string sender, string receiver){
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;
}

void Transaction::printChain(){
    if(prev){
        prev->printChain();
    }
    cout << "Amount: " << amount << "\n";
    cout << "Sender: " << sender << "\n";
    cout << "Receiver: " << receiver << "\n";
    cout << "Nonce: " << nonce << "\n";
    if(!hash.empty()){
        cout << "Hash: " << hash << "\n";
    }
    else{
        puts("Hash: NULL\n");
    }
}

int Transaction::getBalance(string person){
    int balance = 50;
    return getBalanceHelper(person, &balance);
}

int Transaction::getBalanceHelper(string person, int* balance){
    if(sender == person){
        *balance -= amount;
    }
    if(receiver == person){
        *balance += amount;
    }

    if(prev){
        prev->getBalanceHelper(person, balance);
    }
    return *balance;
}


string Transaction::genHash(){
    return "ABCD";
}