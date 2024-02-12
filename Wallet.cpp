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

/** insert currency into the wallet */
bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;
    if (amount < 0) 
    {
        return false;
    }
    if (currencies.count(type) == 0) 
    {
        return false;
    }
    else 
    {
        if (containsCurrency(type, amount)) 
        {
            currencies[type] -= amount;
            return true;
        }
        else
        {
            return false;
        }
    }
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
    std::string s;
    for (std::pair<const std::string,double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n"; 
    }

    return s;
}