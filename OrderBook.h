#pragma once
#include "OrderBook.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
public:
    /** construct, reading a csv data file */
    OrderBook(std::string filename);
    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();
    /** return vector of orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);
    /** Return the earliest timestamp from the data */
    std::string getEarliestTime();
    /** Return the next timestamp from the data
     * If there is no next timestamp
     * wrap around to the start.
     */
    std::string getNextTime(std::string timestamp);
    /** Return the highest price */
    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    /** Return the lowest price */
    static double getLowPrice(std::vector<OrderBookEntry> &orders);
    /** Return the spread */
    static double getSpread(double highestPrice, double lowestPrice);
    /** Return the Volume of Product.*/
    static double getVolume(std::vector<OrderBookEntry> &orders);
    /** Insert and order*/
    void insertOrder(OrderBookEntry &order);
    /** Matching */
    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);


private:
    std::vector<OrderBookEntry> orders;
};
