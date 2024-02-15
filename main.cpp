#include "MerkleMain.h"
#include "CSVReader.h"
#include "Wallet.h"
#include <iostream>

/***
 * Main Class
 *
 */
int main()
{
    // MerkleMain app{};
    // app.init();
    // return 0;
    Wallet wallet;
    // TEST 1: if currency 'type' is not in the wallet yet, set the amount to amount
    std::cout << "TEST 1: set the amount to amount" << std::endl;
    std::cout << "SET 10 BTC and 10000 USDT to the Wallet:" << std::endl;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 10000);
    std::cout << wallet << std::endl;
    // TEST 2: if currency 'type' is already in the wallet and has > 0, add amount to the current amount
    std::cout << "TEST 2: add amount to the current amount" << std::endl;
    std::cout << "Adding 1 BTC and 1000 USDT to the Wallet:" << std::endl;
    wallet.insertCurrency("BTC", 1);
    wallet.insertCurrency("USDT", 1000);
    std::cout << wallet << std::endl;
    // TEST 3: throw an exception if 'amount' is less than 0
    std::cout << "TEST 3: throw an exception if 'amount' is less than 0" << std::endl;
    std::cout << "Trying to insert -1 BTC to the Wallet: " << std::endl;
    try
    {
        wallet.insertCurrency("BTC", -1);
    }
    catch (const std::exception &e)
    {
        std::cout << "*** EXCEPTION THROWN FROM insertCurrency() -> 'amount' is less than 0 *** " << std::endl;
    }
    std::cout << "" << std::endl;
    // Test 4: if the wallet does not contain this much currency, do not change the wallet and return false
    std::cout << "Test 4: if the wallet does not contain this much currency, do not change the wallet and return false " << std::endl;
    std::cout << "Trying to remove 1000 DOGE from the Wallet: " << std::endl;
    std::cout << "wallet.removeCurrency() returned: " << wallet.removeCurrency("DOGE", 1000) << std::endl;
    std::cout << "PRINT WALLET TO ENSURE THAT NOTHING HAS CHANGED: " << std::endl;
    std::cout << wallet << std::endl;
    // Test 5: if the wallet does contain at least this much currency of this type, remove the currency from the wallet and return true
    std::cout << "Test 5: if the wallet does contain at least this much currency of this type, remove the currency from the wallet and return true  " << std::endl;
    std::cout << "Removing 5 BTC from the Wallet: " << std::endl;
    std::cout << "wallet.removeCurrency returned: " << wallet.removeCurrency("BTC", 5) << std::endl;
    std::cout << "Removing 5000 USDT from the Wallet: " << std::endl;
    std::cout << "wallet.removeCurrency returned: " << wallet.removeCurrency("USDT", 5000) << std::endl;
    std::cout << wallet << std::endl;
    // TEST 6: throw an exception if amount < 0
    std::cout << "TEST 6: throw an exception if amount < 0" << std::endl;
    std::cout << "Trying to remove -1 BTC to the Wallet: " << std::endl;
    try
    {
        wallet.removeCurrency("BTC", -1);
    }
    catch (const std::exception &e)
    {
        std::cout << "*** EXCEPTION THROWN FROM removeCurrency() -> 'amount' is less than 0 *** " << std::endl;
    }
    std::cout << "" << std::endl;
    // TEST 7: if the wallet contains the sent amount of currency or more, return true
    std::cout << "TEST 7: if the wallet contains the sent amount of currency or more, return true" << std::endl;
    std::cout << "Asking does the Wallet contain 10 BTC: " << std::endl;
    std::cout << "wallet.containsCurrency returned: " << wallet.containsCurrency("BTC", 10) << std::endl;
    std::cout << " " << std::endl;
    // TEST 8: if the wallet does not contain the sent amount of currency or more, return false
    std::cout << "TEST 8: if the wallet does not contain the sent amount of currency or more, return false" << std::endl;
    std::cout << "Asking does the Wallet contain 10 DOGE: " << std::endl;
    std::cout << "wallet.containsCurrency returned: " << wallet.containsCurrency("DOGE", 10) << std::endl;
    std::cout << " " << std::endl;
}
