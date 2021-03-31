#include <string>

class Transaction
{
    public:
        Transaction(Transaction* previous);
        void addTxn(int amount, std::string sender, std::string receiver);
        int getBalance(std::string person);
        void printChain();
        std::string genHash();

    private:
        int getBalanceHelper(std::string person, int* balance);
        Transaction* prev;
        int amount;
        std::string sender;
        std::string receiver;
        std::string nonce;
        std::string hash;
};