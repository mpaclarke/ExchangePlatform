#include <iostream>
#include <string>
#include <vector>
#include <__algorithm/min_element.h>
#include <iomanip>
// Global Variable
bool keepRunning;
// Order book types
enum class OrderBookType
{
    bid,
    ask
};

class OrderBookEntry
{
    // Constructor uses an initialisation list
public:
    /** Enter price, ampunt, timestamp, product, order-type*/
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType)
        : price(_price),
          amount(_amount),
          timestamp(_timestamp),
          product(_product),
          orderType(_orderType)
    {
    }
    // Data members
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

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

double computeAveragePrice(std::vector<OrderBookEntry> &entries)
{
    double avg = 0.0;
    for (OrderBookEntry &e : entries)
    {
        avg += e.price;
    }
    return avg / entries.size();
}

double computeLowPrice(std::vector<OrderBookEntry> &entries)
{
    auto lowestPrice = std::min_element(entries.begin(), entries.end(),
                                        [](const OrderBookEntry &a, const OrderBookEntry &b)
                                        {
                                            return a.price < b.price;
                                        });

    return lowestPrice->price;
}

double computeHighPrice(std::vector<OrderBookEntry> &entries)
{
    auto highestPrice = std::max_element(entries.begin(), entries.end(),
                                         [](const OrderBookEntry &a, const OrderBookEntry &b)
                                         {
                                             return a.price < b.price;
                                         });

    return highestPrice->price;
}

double computePriceSpread(std::vector<OrderBookEntry> &entries)
{
    auto highestBid = std::max_element(entries.begin(), entries.end(),
                                       [](const OrderBookEntry &a, const OrderBookEntry &b)
                                       {
                                           return a.orderType == OrderBookType::bid && b.orderType == OrderBookType::bid && a.price > b.price;
                                       });

    auto lowestAsk = std::min_element(entries.begin(), entries.end(),
                                      [](const OrderBookEntry &a, const OrderBookEntry &b)
                                      {
                                          return a.orderType == OrderBookType::ask && b.orderType == OrderBookType::ask && a.price < b.price;
                                      });

    return lowestAsk->price - highestBid->price;
}

int main()
{

    // double price = 0.0;
    // double amount = 0.0;
    // std::string timestamp{"data"};
    // std::string product{"data"};
    // OrderBookType orderType = OrderBookType::ask;

    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timestamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderTypes;

    // Keeps the while loop running
    // keepRunning = true;
    // Loop to keep the program running
    // while (keepRunning)
    // {
    //     printMenuOptions();
    //     int userOption = getUserOutput();
    //     processUserOption(userOption);
    // }
    // std::cout << "The application has quit." << std::endl;
    // return 0;

    std::vector<OrderBookEntry> entries;
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

    // & passes by reference
    // iterator style
    unsigned short count = 0;
    for (OrderBookEntry &e : entries)
    {
        ++count;
        std::cout << "The price of entry number " << count << " is: " << e.price << std::endl;
    }

    std::cout << "The average price is " << computeAveragePrice(entries) << std::endl;

    std::cout << "The lowest price is " << computeLowPrice(entries) << std::endl;

    std::cout << "The highest price is " << computeHighPrice(entries) << std::endl;

    std::cout << "The spread price is " << std::fixed << std::setprecision(8) << computePriceSpread(entries) << std::endl;
}
