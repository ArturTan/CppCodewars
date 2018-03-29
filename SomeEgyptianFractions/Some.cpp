#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <math.h>
class Decomp
{
public:
  static std::string decompose(const std::string &nrStr, const std::string &drStr);
};

std::string Decomp::decompose(const std::string &nrStr, const std::string &drStr)
{
    long long int numerator = std::stoi(nrStr);
    long long int  denominator = std::stoi(drStr);
    std::vector<std::string> v;

    std::string word;
    while (true)
    {

        if (numerator > denominator)
        {
            long long int  fraction = numerator/denominator;
            word = std::to_string(fraction);
            v.push_back(word);
            numerator -= fraction * denominator;
            if (numerator == 0)
                break;
        }
        long long int fraq_mod_ = denominator / numerator + 1;
        //std::cout << "old_numerator" << numerator << std::endl;
        //std::cout << "old_denominator" << denominator << std::endl;
        //long long int temp_numerator = std::fmod((std::fmod((-1 * denominator), numerator) + numerator), numerator);
        long long int temp_numerator = std::fmod((std::fmod((-1 * denominator), numerator) + numerator), numerator);
        if (temp_numerator != 0){
            //std::cout << "CONDITION" << std::endl;
            denominator *= fraq_mod_;}
        else
        {
            fraq_mod_ = denominator / numerator;
            }
        numerator = temp_numerator;
        //std::cout << "new_numerator" << numerator << std::endl;
        //std::cout << "new_denominator" << denominator << std::endl;
        std::string temp = std::to_string(fraq_mod_);
        word = "1/" + temp;
        //std::cout << "word " << word << std::endl;
        //std::cout << "numerator " << numerator << std::endl;
        //std::cout << std::endl;
        v.push_back(word);
        if (numerator == 0)
            break;
    }
    std::string result = "[";
    std::vector<std::string> v1 (v.begin(), v.end()-1);
    for (auto & word : v1)
        result +=  word + ", ";
    result += v.back() + "]";

    std::cout << result << std::endl;
    return result;
}

int main()
{
    Decomp::decompose("3", "4");
    Decomp::decompose("4", "5");
    Decomp::decompose("12", "4");
    Decomp::decompose("21", "23");
    Decomp::decompose("66", "100");
}
