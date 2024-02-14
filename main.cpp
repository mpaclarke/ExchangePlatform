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
    MerkleMain app{};
    app.init();
    return 0;
    // Wallet wallet;
    // wallet.insertCurrency("BTC", 10);
    // wallet.insertCurrency("USDT", 10000);
    // std::cout << wallet.toString() << std::endl;
    // wallet.removeCurrency("USDT", 1000);
    // std::cout << wallet.toString() << std::endl;

}
