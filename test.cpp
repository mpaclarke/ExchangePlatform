#include <string>
#include <iostream>
#include <vector>

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
    std::vector<std::string> tokens;
    std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    tokens = tokenise(s, ',');

    for (const std::string& t : tokens) 
    {
        std::cout << t << std::endl;
    }

    return 0;
}