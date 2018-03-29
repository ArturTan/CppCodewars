/*In mathematics, a Diophantine equation is a polynomial equation,
usually with two or more unknowns, such that only the integer
solutions are sought or studied.

In this kata we want to find all integers x, y (x >= 0, y >= 0)
solutions of a diophantine equation of the form:

x2 - 4 * y2 = n
where the unknowns are x and y, and n is a given positive number.

in decreasing order of the positive xi. If there is no solution
return [] or "[]".

Examples
sol_equa(90005) --> [[45003, 22501], [9003, 4499], [981, 467], [309, 37]]
sol_equa(90002) --> []
Hint
x2 - 4 * y2 = (x - 2*y) * (x + 2*y)
*/



#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <cassert>

class Dioph
{
private:
    long long n;
    std::set<int> dividers{};
    std::vector<std::pair<long, long>> results{};
public:
  static std::vector<std::pair <long, long>> solEquaStr(long long n);
  void find_divider();
  void equation(const int & a, const int & b);
  void series_of_equations();
  void show_dividers();
  Dioph(int n_) : n(n_){ }
};

void Dioph::show_dividers()
{
    std::copy(dividers.begin(), dividers.end(), std::ostream_iterator<int>(std::cout, " "));
}

std::vector<std::pair <long, long>> Dioph::solEquaStr(long long n)
{
    Dioph dioph(n);
    dioph.find_divider();
    dioph.series_of_equations();
    //for (auto & it : dioph.results)
      //  std::cout << "X " << it.first << "y " << it.second << std::endl;

    return dioph.results;
}


void Dioph::find_divider()
{
    for (auto i = 1; i <= sqrt(n); i++)
    {
        if (!(n%i))
        {
            dividers.insert(i);
            dividers.insert(n/i);
        }
    }
}

void Dioph::equation(const int & a, const int & b)
{
    int y = (b - a)/4;
    int x = a + 2 * y;
    if (((x - 2 * y)*(x + 2 * y) == n) && (x >= 0) && (y >= 0))
    {
        std::pair <long, long> result (x, y);
        results.push_back(result);
    }
}

void Dioph::series_of_equations()
{
    for (auto & i : dividers)
        for (auto & j : dividers)
            equation(i, j);
}

int main()
{
    std::vector<std::pair <long, long>> sol2 = { {4501, 2250} };
    assert(Dioph::solEquaStr(9001) == sol2);
}
