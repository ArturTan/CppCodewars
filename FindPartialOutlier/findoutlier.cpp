/*
You are given an array (which will have a length of at least 3,
but could be very large) containing integers.
The array is either entirely comprised of odd integers or
entirely comprised of even integers except for a single integer N.
Write a method that takes the array as an argument and returns
this "outlier" N.

[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)

*/
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
int FindOutlier(std::vector<int> arr)
{

    auto Even = std::find_if(arr.begin(), arr.end(), [](const auto & i){return (!(i%2));});
    auto Even2 = std::find_if((Even+1), arr.end(), [](const auto & i){return (!(i%2));});

    if (Even2 == arr.end())
        return (*Even);

    auto Odd = std::find_if(arr.begin(), arr.end(), [](const auto & i){return (i%2);});
    return (*Odd);
}


int main()
{
    std::vector<int> as {2, 3, 4};
    assert(FindOutlier(as) == 3);
};
