#include "CSVReader.h"
#include <iostream>
#include <fstream>

unsigned int CSVReader::lineCount = 0;

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::cout << "CSVReader::readCSV -> ***** START DATA PROCESSING ***** " << std::endl;
    std::vector<OrderBookEntry> orders;
    std::ifstream csvFile{csvFilename};
    std::string line;
    unsigned int invalidLineCount = 0;

    if (csvFile.is_open())
    {
        std::cout << "CSVReader::readCSV -> *** FILE OPEN *** " << std::endl;
        std::cout << "CSVReader::readCSV -> reading data from " << csvFilename << std::endl;
        while (std::getline(csvFile, line))
        {
            try
            {
                OrderBookEntry obe = stringsToOrderBookEntry(tokenise(line, ','));
                orders.push_back(obe);
            }
            catch (const std::exception &e)
            {
                std::cout << "CSVReader::readCSV -> caught the throw..." << std::endl;
            }
            ++lineCount;
        } // end of while loop
        csvFile.close();
        if (!csvFile.is_open())
        {
            line.clear();
            std::cout << "CSVReader::readCSV -> *** FILE CLOSED *** " << std::endl;
        }

        std::cout << "CSVReader::readCSV -> Read " << lineCount << " valid line(s) from " << csvFilename << std::endl;
        if (invalidLineCount > 0)
        {
            std::cout << "CSVReader::readCSV -> Read " << invalidLineCount << " invalid line(s) from " << csvFilename << std::endl;
        }
    }
    else
    {
        std::cout << "CSVReader::readCSV ->Could not open file. " << std::endl;
    }

    std::cout << "CSVReader::readCSV -> ***** END DATA PROCESSING ***** " << std::endl;
    std::cout << " " << std::endl;
    return orders;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end)
            break;

        if (end >= 0)
            token = csvLine.substr(start, end - start);

        else
            token = csvLine.substr(start, end - start);

        tokens.push_back(token);

        start = end + 1;

    } while (end != std::string::npos);
    return tokens;
}
OrderBookEntry CSVReader::stringsToOrderBookEntry(std::vector<std::string> tokens)
{
    double price, amount;
    if (tokens.size() != 5)
    {
        std::cout << "stringsToOrderBookEntry() -> BAD LINE: Incorrect number of Tokens at line number " << lineCount + 1 << std::endl;
        throw std::exception{};
    }
    // If we have 5 tokens in the vector:
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "stringsToOrderBookEntry() -> BAD DATA: line number " << lineCount + 1 << std::endl;
        std::cout << "BAD FLOAT: " << tokens[3] << std::endl;
        std::cout << "BAD FLOAT: " << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{
        price,
        amount,
        tokens[0],
        tokens[1],
        OrderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
}