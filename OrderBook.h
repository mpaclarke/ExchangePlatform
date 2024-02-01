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
    /** Return the highest price */
    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    /** Return the lowest price */
    static double getLowPrice(std::vector<OrderBookEntry>& orders);
     /** Return the spread */
    static double getSpread(double highestPrice, double lowestPrice); 
    
    private:
        std::vector<OrderBookEntry> orders;
};
