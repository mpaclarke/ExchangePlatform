// pre-processor directive
#pragma once
#include <string>
// Order book types
enum class OrderBookType
{
    bid,
    ask
};
// OrderBookEntry class with appropriate data types to represent a the fields in a row in the data file.
class OrderBookEntry
{
    // OrderBookEntry class has a constructor taking an appropriate set of arguments.
public:
    /** Enter price, ampunt, timestamp, product, order-type*/
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);
    // Data members
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};