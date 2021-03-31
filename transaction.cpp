#include "transaction.h"
#include <iostream>
#include <openssl/sha.h>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

Transaction::Transaction(Transaction* previous){
    if(previous == NULL){
        this->hash = "NULL";
    }
    else{
        this->hash = previous->getHash();
    }
    this->prev = previous;
}

void Transaction::addTxn(int amount, string sender, string receiver){
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;

    genNonce();
}

void Transaction::printChain(){
    if(prev){
        prev->printChain();
    }
    cout << "Amount: " << amount << "\n";
    cout << "Sender: " << sender << "\n";
    cout << "Receiver: " << receiver << "\n";
    cout << "Nonce: " << nonce << "\n";
    cout << "Hash: " << hash << "\n";
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

void Transaction::genNonce(){
    int nonce = 0;

    while(1){
        if(sha256(to_string(amount) + sender + receiver + to_string(nonce)).back() == '0'){
            this->nonce = to_string(nonce);
            return;
        }
        nonce ++;
    }
}

string Transaction::getHash(){
    return sha256(to_string(amount) + sender + receiver + this->hash + nonce);
}

// https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c/10632725
string Transaction::sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}
