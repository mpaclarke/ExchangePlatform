#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFilename);
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOrderBookEntry(std::string price,
                                                  std::string amount,
                                                  std::string timestamp,
                                                  std::string product,
                                                  OrderBookType OrderBookType);

private:
    static unsigned int lineCount;
    static OrderBookEntry stringsToOrderBookEntry(std::vector<std::string> tokens);
};