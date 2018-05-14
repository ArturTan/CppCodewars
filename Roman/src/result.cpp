#include "../include/Roman.hpp"

std::string solution(int number)
{
    Converter converter;
    return converter.arabic_to_roman_convert(number);
}

std::string Converter::arabic_to_roman_convert(int number)
{
    std::string roman_form;
    while (number != 0)
    {
        for (auto & record : arabic_to_roman)
        {
            int temp = number - record.first ;
            if (temp < 0)
                continue;
            number -= record.first;
            roman_form += record.second;
        }
    }
    return roman_form;
}
