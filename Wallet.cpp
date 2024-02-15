#include "Wallet.h"
#include "CSVReader.h"
#include <iostream>

Wallet::Wallet()
{
}

std::ostream &operator<<(std::ostream &os, Wallet &wallet)
{
    os << wallet.toString();
    return os;
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
        throw std::exception{};
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
    for (std::pair<const std::string, double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}

bool Wallet::canFulfillOrder(const OrderBookEntry &order)
{
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    // ask
    if (order.orderType == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currs[0];
        std::cout << "Wallet::canFulfillOrder -> " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    // bid
    if (order.orderType == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        std::cout << "Wallet::canFulfillOrder -> " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    return false;
}