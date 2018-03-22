#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>
#include <numeric>

class GapInPrimes
{
public:
    static std::pair <long long, long long> gap(int g, long long m, long long n);
};

std::pair <long long, long long > GapInPrimes::gap(int g, long long m, long long n)
{
    std::vector<int> numbers;
    std::generate_n(std::back_inserter(numbers), n-m+1, [&, t = 0]() mutable ->int { return (m + t++); });

    int start = 2;
    std::vector<int> primers_among_numbers, distances;
    std::pair<long long, long long> pair_of_primes(0,0);

    while (start < sqrt(n))
    {
        auto place_to_be_removed = std::remove_if(numbers.begin(),
                                             numbers.end(),
                                             [&](auto & i) { return (i%start == 0) ; });
        numbers.erase(place_to_be_removed, numbers.end());
        start++;
    }

    numbers.insert(numbers.begin(), start);

    for (auto it = numbers.begin(); it < numbers.end() - 1; it++)
    {
        int distance_candidate = *(it + 1) - *it;
        if (distance_candidate == g)
        {
            pair_of_primes.first = *it;
            pair_of_primes.second = *(it + 1);
            return pair_of_primes;
        }
    }
    return pair_of_primes;
}

int main()
{

    int gap, range_1, range_2;
    std::cout << "GAP: ";
    std::cin >> gap;
    std::cout << "Range between: ";
    std::cin >> range_1;
    std::cout << "and: ";
    std::cin >> range_2;
    std::pair<long long, long long> pair_of_primes = GapInPrimes::gap(gap,range_1, range_2);
    std::cout << pair_of_primes.first << " " << pair_of_primes.second;
}

