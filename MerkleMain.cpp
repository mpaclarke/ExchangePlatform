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
    keepRunning = true;
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

    while (keepRunning)
    {
        printMenuOptions();
        input = getUserOption();
        processUserOption(input);
    }
    std::cout << "The application has shutdown." << std::endl;
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
    // Prints the current time
    std::cout << "**** **** **** **** **** ****" << std::endl;
    std::cout << "The current time is: " << currentTime << std::endl;
    std::cout << "**** **** **** **** **** ****" << std::endl;
}

// Gets the users input
int MerkleMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Please Select an Option" << std::endl;
    std::cout << "Type in 1 - 7" << std::endl;
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
    {
        // Uses default in switch to warn user.
    }

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
    std::cout << "List of Products: " << std::endl;
    for (std::string const &product : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << product << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                  product,
                                                                  currentTime);
        std::cout << "\t Number of ASKS: " << entries.size() << std::endl;
        std::cout << "\t Max ASKS: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "\t Min ASKS: " << OrderBook::getLowPrice(entries) << std::endl;
        std::cout << "\t Spread: " << OrderBook::getSpread(OrderBook::getHighPrice(entries), OrderBook::getLowPrice(entries))
                  << std::endl;
        std::cout << "\t Volume: " << OrderBook::getVolume(entries) << std::endl;
    }
    std::cout << "- - - - - - - - - - - - - - - - - " << std::endl;
}

// Takes ASK
void MerkleMain::enterAsk()
{
    std::cout << "MAKE AN ASK" << std::endl;
    std::cout << "Please enter the amount: product,price,amount; eg: ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "BAD INPUT: " << input << std::endl;
    }
    else
    {
        try
        {
            std::cout << "You entered: " << input << std::endl;
            OrderBookEntry obe = CSVReader::stringsToOrderBookEntry(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask);
            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Your Wallet has sufficient funds." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Your Wallet has insufficient funds." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "MerkleMain::enterAsk() -> BAD INPUT: " << input << std::endl;
        }
    }
}

// Takes BID
void MerkleMain::enterBid()
{
    std::cout << "MAKE A BID!" << std::endl;
    std::cout << "Please enter the amount: product,price,amount; eg: ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "BAD INPUT: " << input << std::endl;
    }
    else
    {
        try
        {
            std::cout << "You entered: " << input << std::endl;
            OrderBookEntry obe = CSVReader::stringsToOrderBookEntry(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid);
            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Your Wallet has sufficient funds." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Your Wallet has insufficient funds." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "MerkleMain::enterBid() -> BAD INPUT: " << input << std::endl;
        }
    }
}

// Prints the content of the wallet
void MerkleMain::printWallet()
{
    std::cout << "WALLET: " << wallet << std::endl;
}

// Calls the next time frame
void MerkleMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry &sale : sales)
    {
        std::cout << "Sale price: " << sale.price << " | Sale amount: " << sale.amount << std::endl;
    }
    currentTime = orderBook.getNextTime(currentTime);
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