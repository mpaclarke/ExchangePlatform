#pragma once
#include <string>
#include <map>

class Wallet 
{
    public:
        Wallet();
        /** insert currency into the wallet */
        void insertCurrency(std::string type, double amount);
        /** check if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);
        /** genertate a string representation of the wallet */
        std::string toString();
    private:
        std::map<std::string, double> currencies(); 

};