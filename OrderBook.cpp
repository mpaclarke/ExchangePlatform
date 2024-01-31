#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    std::map<std::string, bool> productMap;

    for (OrderBookEntry &e : orders)
    {
        productMap[e.product] = true;
    }

    // flatten the map to a vector of strings
    for (auto const &e : productMap)
    {
        products.push_back(e.first);
    }
    return products;
}

/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 std::string product,
                                                 std::string timestamp)

{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry &e : orders)
    {
        if (e.orderType == type &&
            e.product == product &&
            e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}
