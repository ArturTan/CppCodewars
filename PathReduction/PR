#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
    static void tettest_();
};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr)
{
    std::cout << "START" << std::endl;
    std::copy (arr.begin(), arr.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::unordered_map<std::string, std::string> directions = {
        {"NORTH","SOUTH"},
        {"SOUTH","NORTH"},
        {"EAST","WEST"},
        {"WEST","EAST"},
    };

    auto it = arr.begin();
    int iteration = 0;

    auto find_opposite = [&](auto & i)
    {
        return (i == directions[*it]) ;
    };


    while(true)
    {

        auto if_there_is_an_opposite = std::find_if(it, arr.end(), find_opposite);
        if (if_there_is_an_opposite != arr.end() && if_there_is_an_opposite == (it+1))
        {
            arr.erase(if_there_is_an_opposite, if_there_is_an_opposite+1);
            arr.erase(it, it +1);
            it = arr.begin();
            continue;
        }
        it++;
        if ((it == arr.end()) || arr.empty())
           break;
    }
    std::cout << std::endl;
    std::copy (arr.begin(), arr.end(), std::ostream_iterator<std::string>(std::cout, " "));

    return arr;
};

int main()
{
    std::vector<std::string> d1 = {
        //"EAST", "WEST", "NORTH", "SOUTH" };
        //"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH","WEST" };
        //"EAST", "EAST", "WEST", "NORTH", "WEST", "EAST", "EAST", "SOUTH", "NORTH", "WEST"};
        "SOUTH", "EAST", "NORTH", "WEST" };

    DirReduction::dirReduc(d1);
}

