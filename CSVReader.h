#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFilename);

private:
    static unsigned int lineCount; 
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOrderBookEntry(std::vector<std::string> tokens);
};