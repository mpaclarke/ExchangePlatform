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
    wallet.insertCurrency("BTC", 10);
    std::cout << "Wallet has BTC " << wallet.containsCurrency("BTC", 10) << std::endl;;
    std::cout << wallet.toString() << std::endl;

}
