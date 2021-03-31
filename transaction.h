#include <string>

class Transaction
{
    public:
        Transaction(Transaction* previous);
        void addTxn(int amount, std::string sender, std::string receiver);
        int getBalance(std::string person);
        void printChain();
        std::string getHash();

    private:
        void genNonce();
        int getBalanceHelper(std::string person, int* balance);
        std::string sha256(const std::string str);
        Transaction* prev;
        int amount;
        std::string sender;
        std::string receiver;
        std::string nonce;
        std::string hash;
};