#include "MerkleMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

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
    std::cout << "MerkleMain::loadOrderBook() -> Loading order book... " << std::endl;
    orders = CSVReader::readCSV("20200317.csv");
    std::cout << "MerkleMain::loadOrderBook() -> Stored " << orders.size() << " orders." << std::endl;
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
    std::cout << "- - - - - Exchange Stats - - - - -" << std::endl;
    std::cout << "The Order Book contains: " << orders.size() << " orders." << std::endl;

    unsigned int asks = 0;
    unsigned int bids = 0;
    for (OrderBookEntry &e : orders)
    {
        if (e.orderType == OrderBookType::ask)
            asks++;
        if (e.orderType == OrderBookType::bid)
            bids++;
    }
    std::cout << "OrderBook ASKS: " << asks << " | OrderBook BIDS: " << bids << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - " << std::endl;
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