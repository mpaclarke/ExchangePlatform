#include <string>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    // String Vector Tokens
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

int main()
{
    // std::vector<std::string> tokens;
    // std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    // tokens = tokenise(s, ',');

    // for (const std::string& t : tokens)
    // {
    //     std::cout << t << std::endl;
    // }

    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;

    int lineCount = 1;
    if (csvFile.is_open())
    {
        std::cout << "File open " << std::endl;

        while (std::getline(csvFile, line))
        {
            std::cout << "Read line " << line << std::endl;
            tokens = tokenise(line, ',');
            if (tokens.size() != 5)
            {
                std::cout << "BAD LINE" << std::endl;
                continue;
            }

            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << " : " << amount << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "COULD NOT READ LINE NUMBER " << lineCount << std::endl;
                std::cout << "BAD FLOAT: " << tokens[3] << std::endl;
                std::cout << "BAD FLOAT: " << tokens[4] << std::endl;
                continue;
                //std::cerr << e.what() << '\n';
            }

            ++lineCount;
        }

        csvFile.close();
        if (!csvFile.is_open())
        {
            line.clear();
            std::cout << "The flie is closed." << line << std::endl;
        }
        std::cout << "Read " << lineCount << " lines from the file." << std::endl;
    }
    else
    {
        std::cout << "Could not open file. " << std::endl;
    }

    return 0;
}