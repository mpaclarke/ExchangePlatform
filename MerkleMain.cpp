#include "MerkleMain.h"
#include <iostream>
#include <vector> 
#include "OrderBookEntry.h"

MerkleMain::MerkleMain()
{
}

void MerkleMain::init()
{
    loadOrderBook();
    keepRunning = true;
    int input;
    while (keepRunning)
    {
        printMenuOptions();
        input = getUserOption();
        processUserOption(input);
    }
    std::cout << "The application has shutdown." << std::endl;
}

 void MerkleMain::loadOrderBook() 
 {
    // Pushes data to vector
    // bid
    entries.push_back(OrderBookEntry{0.02187308,
                                     7.44564869,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    // bid
    entries.push_back(OrderBookEntry{0.02187307,
                                     3.467434,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    // bid
    entries.push_back(OrderBookEntry{0.02187305,
                                     6.85567013,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    // bid
    entries.push_back(OrderBookEntry{0.021873,
                                     1,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::bid});
    // ask
    entries.push_back(OrderBookEntry{0.02189093,
                                     9.80492203,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::ask});
    // ask
    entries.push_back(OrderBookEntry{0.02189094,
                                     10.91645003,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::ask});
    // ask
    entries.push_back(OrderBookEntry{0.02189096,
                                     6.85752424,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::ask});
    // ask
    entries.push_back(OrderBookEntry{0.02189398,
                                     9.14003499,
                                     "2020/03/17 17:01:24.884492",
                                     "ETH/BTC",
                                     OrderBookType::ask});
 }

// Prints the menu options
void MerkleMain::printMenuOptions()
{
    // Menu Options
    std::cout << "********** MAIN MENU **********" << std::endl;
    // 1 print help
    std::cout << "1: Print Help " << std::endl;
    // 2 print exchange sats
    std::cout << "2: Print Exchange Stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Place an Ask" << std::endl;
    // 4 make a bid
    std::cout << "4: Place a Bid" << std::endl;
    // 5 show the wallet
    std::cout << "5: Print Wallet" << std::endl;
    // 6 continue (next time step)
    std::cout << "6: Continue" << std::endl;
    // 7 quit the application
    std::cout << "7: Quit" << std::endl;
    // Prints prompt to the user
    std::cout << "**** **** **** **** **** ****" << std::endl;
}

// Gets the users input
int MerkleMain::getUserOption()
{
    int userOption;
    std::cout << "Please Select an Option" << std::endl;
    std::cout << "Type in 1 - 7" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose " << userOption << std::endl;
    return userOption;
}

// Prints the help
void MerkleMain::printHelp()
{
    std::cout << "******* Help *******" << std::endl;
    std::cout << "Your aim is to make money! " << std::endl;
    std::cout << "Analyse the market and make bids and offers." << std::endl;
}

// 4)
// This function iterates over the vector calculating some basic stats
void MerkleMain::printMarketStats()
{
    std::cout << "- - - - - MARKET STATS - - - - -" << std::endl;
    std::cout << "The Order Book contains: " << entries.size() << " entries." << std::endl;
}

// Takes ASK
void MerkleMain::enterAsk()
{
    std::cout << "Make an offer..." << std::endl;
}

// Takes BID
void MerkleMain::enterBid()
{
    std::cout << "Make a bid: enter the amount you would like to bid." << std::endl;
}

// Prints the content of the wallet
void MerkleMain::printWallet()
{
    std::cout << "WALLET: EMPTY" << std::endl;
}

// Calls the next time frame
void MerkleMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}

// Processes the user input option
void MerkleMain::processUserOption(int userOption)
{
    switch (userOption)
    {
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterAsk();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        goToNextTimeFrame();
        break;
    case 7:
        std::cout << "Exiting the application..." << std::endl;
        keepRunning = false;
        break;
    default:
        std::cout << "Invaild choice. Please choose options 1-7:" << std::endl;
        break;
    }
}