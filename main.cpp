#include "transaction.h"
#include <stdio.h>
#include <iostream>

int menu(){
    int choice;
    puts("Welcome to the transaction-chain application....");
    puts("1) Add a transaction to the chain.");
    puts("2) Find Balance of a person.");
    puts("3) Print the chain.");
    puts("4) Exit.");
    puts("Which operation do you want to make? (1,2,3,4):");
    scanf("%d", &choice);
    return choice;
}


int main(){
    int choice;
    Transaction* tail = nullptr;
    int amount;
    std::string sender;
    std::string receiver;
    std::string person;

    while(1){
        system("cat tests/*");
        choice = menu();
        if(choice == 4){
            // exit
            return 0;
        }
        else if(choice == 1){
            // add
            tail = new Transaction(tail);
            puts("Integer amount of money:");
            scanf("%d", &amount);
            puts("Sender name");
            std::cin >> sender;
            puts("Receiver name");
            std::cin >> receiver;
            tail->addTxn(amount, sender, receiver);
        }
        else if(choice == 2){
            // balance
            puts("Person Name");
            std::cin >> person;
            printf("%d\n", tail->getBalance(person));
        }
        else if(choice == 3){
            // print chain
            tail->printChain();
        }
        else{
            puts("wrong operation!");
        }
    }
    return 0;
}