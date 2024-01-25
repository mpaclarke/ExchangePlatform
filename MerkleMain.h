// pre-processor directive
#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkleMain
{
public:
    
    // Consructor   
    MerkleMain();
    /** Call this function to start the simulation.*/
    void init();
private:
    // Variable to keep menu open
    bool keepRunning;
    // Loads the order book data 
    void loadOrderBook(); 
    // Prints the menu options
    void printMenuOptions();
    // Gets the users input
    int getUserOption();
    // Prints the help
    void printHelp();
    // This function iterates over the vector calculating some basic stats
    void printMarketStats();
    // Takes ASK
    void enterAsk();
    // Takes BID
    void enterBid();
    // Prints the content of the wallet
    void printWallet();
    // Calls the next time frame
    void goToNextTimeFrame();
    // Processes the user input option
    void processUserOption(int userOption);
    // Collection of Order Book data.
    std::vector<OrderBookEntry> entries;
};