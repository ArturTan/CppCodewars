#include "../include/Poker.hpp"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
std::vector<std::string> splitter (const char* pokerhand)
{
    std::vector<std::string> splitted_cards;
    std::string splitted_pokerhand(pokerhand);

    auto it = splitted_pokerhand.begin();
    int step = 0;
    while (true)
    {
        auto finded_split = std::find(it, splitted_pokerhand.end(), ' ');
        std::string card{it, finded_split};
        splitted_cards.push_back(card);
        if (finded_split == splitted_pokerhand.end())
           break;
        it = finded_split+1;
        step++;
    }
    return splitted_cards;
}

void PokerHand::isStraight()
{
    std::find_if(splitted_cards_with_values_and_suits.begin(),
            splitted_cards_with_values_and_suits.end(),
            [](auto i) { auto & [x, y] = i; return true; });
}

PokerHand::PokerHand (const char* pokerhand)
{
    std::vector<std::string> splitted_cards = splitter("2H 3H 4H 5H 6H");
    std::generate_n(std::back_inserter(splitted_cards_with_values_and_suits),
                    splitted_cards.size(),
                    [&splitted_cards, i = 0]() mutable { auto card = splitted_cards[i];
                                       std::tuple<char, char> tup = std::make_tuple(card[0], card[1]);
                                       i++;
                                       return tup; });
    std::sort(splitted_cards_with_values_and_suits.begin(),
              splitted_cards_with_values_and_suits.end());
    isStraight();


    /*for (auto & [first, second] : splitted_cards_with_values_and_suits)
    std::cout << first << "" << second << " ";//sort lexigrophacially + cout the input*/

}


Result compare (const PokerHand &player, const PokerHand &opponent) {
  return Result::Loss;
}

