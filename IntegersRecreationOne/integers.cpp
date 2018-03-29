/*

Divisors of 42 are : 1, 2, 3, 6, 7, 14, 21, 42. These divisors squared are:
 1, 4, 9, 36, 49, 196, 441, 1764. The sum of the squared divisors is 2500
which is 50 * 50, a square!

Given two integers m, n (1 <= m <= n) we want to find all integers between
m and n whose sum of squared divisors is itself a square. 42 is such a number.

The result will be an array of arrays or of tuples (in C an array of Pair)
 or a string, each subarray having two elements, first the number whose
 squared divisors is a square and then the sum of the squared divisors.

#Examples:

list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]

The form of the examples may change according to the language,
see Example Tests: for more details.
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <numeric>
#include <iterator>
#include <set>

class SumSquaredDivisors
{
private:
    std::map<int, int> squared_dict;
    std::map<int, std::set<int>> dict_of_dividers;
    std::map<long long, long long> results;

public:
    static std::string listSquared(long long m, long long n);
    void add_dividers_if_divider_has_squares(int && basic, int && candidate);
    void dict_creator(int & divider);
    void cycle(long long m, long long n);
    void divider_parser(int number);
    long long check_if_sum_is_square(int number);
    void print_squared_dict();
    void show_dict_of_dividers();
    std::string show_results();
};


void SumSquaredDivisors::print_squared_dict()
{
    for (auto & para : squared_dict)
        std::cout << "Number in squared dict " << para.first << " Second " << para.second << std::endl;
}

void SumSquaredDivisors::show_dict_of_dividers()
{
    for (auto & para : dict_of_dividers)
    {
        std::cout << "First " << para.first << " Second ";
        std::copy(para.second.begin(), para.second.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
}

void SumSquaredDivisors::dict_creator(int & divider)
{
    squared_dict[divider] = divider * divider;
}

void SumSquaredDivisors::add_dividers_if_divider_has_squares(int && basic, int && candidate)
{
    if (dict_of_dividers.find(candidate) != dict_of_dividers.end())
        dict_of_dividers[basic].insert(dict_of_dividers[candidate].begin(), dict_of_dividers[candidate].end());
    if (squared_dict.find(candidate) == squared_dict.end())
        squared_dict[candidate] = candidate * candidate;
    dict_of_dividers[basic].insert(squared_dict[candidate]);
}

void SumSquaredDivisors::cycle(long long m, long long n)
{
    for (; m <= n; ++m)
    {
        divider_parser(m);
        long long sum = check_if_sum_is_square(m);
        if (sum)
           results[m] = sum;
    }
}

void SumSquaredDivisors::divider_parser(int number)
{
    int divider = 1;

    while (divider <= sqrt(number))
    {
        if(!(number % divider))
        {
            add_dividers_if_divider_has_squares(std::move(number), std::move(divider));
            add_dividers_if_divider_has_squares(std::move(number), std::move(number / divider));
        }
        divider++;
    };
}

long long SumSquaredDivisors::check_if_sum_is_square(int number)
{
    int sum = std::accumulate(dict_of_dividers[number].begin(),
                    dict_of_dividers[number].end(),
                    0,
                    std::plus<int>());
    int sqrt_of_sum = sqrt(sum);
    if (sqrt_of_sum * sqrt_of_sum == sum)
        return sum;
    else
        return 0;
}

std::string SumSquaredDivisors::show_results()
{
    std::string answer("{");
    if (results.size() > 0)
    {
        for (auto & para : results)
            answer += '{' + std::to_string(para.first) + ", " + std::to_string(para.second) + '}' + ", ";
        answer.erase(answer.end()-2, answer.end());
    }
    answer += '}';
    return answer;

}


std::string SumSquaredDivisors::listSquared(long long m, long long n)
{
    SumSquaredDivisors Machine;
    Machine.cycle(m, n);
    return Machine.show_results();
}

void test()
{
SumSquaredDivisors Machine;
for (auto i = 0; i < 20; i++)
    Machine.dict_creator(i);

Machine.print_squared_dict();

for (auto i = 2; i <= 42; i++)
    Machine.divider_parser(i);

Machine.show_dict_of_dividers();

std::cout << Machine.check_if_sum_is_square(36);
};

int main()
{

   std::cout <<  SumSquaredDivisors::listSquared(42, 250) << std::endl; //42, 250, "{{42, 2500}, {246, 84100}}"

}
