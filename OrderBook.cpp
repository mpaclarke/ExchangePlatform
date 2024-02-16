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

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = orders[0].price;
    for (OrderBookEntry &e : orders)
    {
        if (e.price > max)
            max = e.price;
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders[0].price;
    for (OrderBookEntry &e : orders)
    {
        if (e.price < min)
            min = e.price;
    }
    return min;
}

double OrderBook::getSpread(double highestPrice, double lowestPrice)
{
    return highestPrice - lowestPrice;
}

/** Takes in a vector of filtered orders.
 * Returns the volume.
 */
double OrderBook::getVolume(std::vector<OrderBookEntry> &orders)
{
    // local variable that is returned.
    double volume = 0.0;
    // Iterates over the input vector
    for (OrderBookEntry &e : orders)
    {
        // Sums the volume of the price and the amount
        volume += e.price * e.amount;
    }
    // returns the volume.
    return volume;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (const OrderBookEntry &e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = orders[0].timestamp;
    }
    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry &order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask,
                                                 product,
                                                 timestamp);

    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid,
                                                 product,
                                                 timestamp);
    // Store the sales
    std::vector<OrderBookEntry> sales;
    // Sort the asks
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    // Sort the bids
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDes);
    // iterate over the asks
    for (OrderBookEntry &ask : asks)
    {
        // iterate over the bids
        for (OrderBookEntry &bid : bids)
        {
            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{ask.price,
                                    0,
                                    timestamp,
                                    product,
                                    OrderBookType::asksale};

                if (bid.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;
                }
                if (ask.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::asksale;
                }

                                if (bid.amount == ask.amount)
                {
                    // do something...
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                if (bid.amount > ask.amount)
                {
                    // do something...
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                }
                if (bid.amount < ask.amount &&
                    bid.amount > 0)
                {
                    // do something...
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    return sales;
}