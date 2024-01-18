#include <iostream>
#include <string>
#include <vector>
// Global Variable
bool keepRunning;

void printMenuOptions()
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

int getUserOutput()
{
    int userOption;
    std::cout << "Please Select an Option" << std::endl;
    std::cout << "Type in 1 - 7" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose " << userOption << std::endl;
    return userOption;
}

void printHelp()
{
    std::cout << "******* Help *******" << std::endl;
    std::cout << "Your aim is to make money! " << std::endl;
    std::cout << "Analyse the market and make bids and offers." << std::endl;
}

void printMarketStats()
{
    std::cout << "Print the Stats Here" << std::endl;
}

void enterAsk()
{
    std::cout << "Make an offer..." << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid: enter the amount you would like to bid." << std::endl;
}

void printWallet()
{
    std::cout << "WALLET: EMPTY" << std::endl;
}

void goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}

void processUserOption(int userOption)
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

int main()
{
    enum class OrderBookType
    {
        bid,
        ask
    };
    // double price = 0.0;
    // double amount = 0.0;
    // std::string timestamp{"data"};
    // std::string product{"data"};
    // OrderBookType orderType = OrderBookType::ask;

    std::vector<double> prices;
    std::vector<double> amounts;
    std::vector<std::string> timestamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> orderTypes;


    // Keeps the while loop running
    keepRunning = true;
    // Loop to keep the program running
    while (keepRunning)
    {
        printMenuOptions();
        int userOption = getUserOutput();
        processUserOption(userOption);
    }
    std::cout << "The application has quit." << std::endl;
    return 0;
}
