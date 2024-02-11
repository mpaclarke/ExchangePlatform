#include "Wallet.h"

Wallet::Wallet()
{
}

/** insert currency into the wallet */
void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if (amount < 0) 
    {
        throw std::exception{};
    }
    if (currencies.count(type) == 0) 
    {
        balance = 0; 
    }
    else 
    {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}
/** check if the wallet contains this much currency or more */
bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencies.count(type) == 0) 
    {
        return false;
    }
    else 
    {
        return currencies[type];
    }
}

std::string Wallet::toString()
{
    return "TEST WALLET";
}