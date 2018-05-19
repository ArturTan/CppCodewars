#include "../include/Poker.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <set>



std::vector<std::string> splitter (const char* pokerhand)
{
    std::vector<std::string> splitted_cards;
    std::string splitted_pokerhand(pokerhand);

    auto it = splitted_pokerhand.begin();
    while (true)
    {
        auto finded_split = std::find(it, splitted_pokerhand.end(), ' ');
        std::string card{it, finded_split};
        splitted_cards.push_back(card);
        if (finded_split == splitted_pokerhand.end())
           break;
        it = finded_split+1;
    }
    return splitted_cards;
}

bool PokerHand::checker(int number_of_concern, int checks)
{
    for (auto key : map_of_results)
    {
        if (key.second == number_of_concern)
        {
            return true;
        }
    }
    return false;
}


bool PokerHand::isKind()
{
    if (checker(4, 2))
    {
         real_pokerhand = PokerRank::FourOfKind;
         return true;
    }
    return false;;
}

bool PokerHand::isThree()
{
    if (checker(3, 3))
    {
         real_pokerhand = PokerRank::Three;
         return true;
    }
    return false;
}

bool PokerHand::isStraight()
{
    auto minor = splitted_cards_with_values_and_suits.begin();
    int step = 1;

    if(map_of_results[*minor] == 1)
    {
        while (minor != splitted_cards_with_values_and_suits.end())
        {

            std::cout << "MINI " << (*minor)<< std::endl;
            auto x = *(minor+1);

            if (!((*minor)+1 == x))
            {
               std::cout << "MIN ch " << *(minor) << std::endl;
               minor++;

               break;
            }
            std::cout << x << std::endl;
            minor++;
            step++;



        }
    }

    std::cout << "Second try" << std::endl;

    if (map_of_results[14] == 1 && map_of_results[2] == 1)
    {

        while (minor != splitted_cards_with_values_and_suits.end())
        {
            std::cout << "MINI " << (*minor)<< std::endl;
            auto x = *(minor+1);
            if (!((*minor)+1 == x))
            {
               std::cout << "MIN ch " << *(minor) << std::endl;
               if(*minor == 14)
                   step++;
               break;
            }
            std::cout << x << std::endl;
            minor++;
            step++;
        }
    }

    std::cout << "STEPS " << step << std::endl;
    if(step == 5)
    {
        std::cout << "A straight " << std::endl;
        isStraight_answer = true;
        return true;
    }
    std::cout << "NOT A straight " << std::endl;
    return false;
}

bool PokerHand::CombosChecker(int checks, std::vector<int> to_be_checked, int patterns)
{

    std::map<int,int> candidates;
    for (auto & par : to_be_checked)
    {
        for (auto & key : map_of_results)
            if (par == key.second && candidates.find(key.first) == candidates.end())
                candidates[key.first] = key.second;
    }


    if (candidates.size() != patterns )
        return false;


    return true;

}

bool PokerHand::isFull()
{

    if (CombosChecker(4, {3,2}, 2))
    {
        real_pokerhand = PokerRank::Full;
        std::cout << "FULL" << std::endl;
        return true;
    }
    return false;
}



bool PokerHand::isTwoPair()
{
    if (CombosChecker(3, {2,2}, 2))
    {
        real_pokerhand = PokerRank::TwoPair;
        return true;
    }
    return false;
}

bool PokerHand::isPair()
{
    if (CombosChecker(4, {2}, 1))
    {
        real_pokerhand = PokerRank::Pair;
        return true;
    }
    return false;
}


PokerHand::PokerHand (const char* pokerhand)
{
    std::vector<std::string> splitted_cards = splitter(pokerhand);
    std::generate_n(std::back_inserter(splitted_cards_with_values_and_suits),
                    splitted_cards.size(),
                    [&, color = splitted_cards[0][1], i = 0]() mutable {  auto card = splitted_cards[i];
                                       int tup = values_of_cards.at(card[0]);
                                       if (is_same_suit)
                                           if(card[1] != color)
                                               is_same_suit = false;
                                       color = card[1];
                                       i++;
                                       return tup; });


    std::sort(splitted_cards_with_values_and_suits.begin(),
              splitted_cards_with_values_and_suits.end()); // here sort

    setMapper();

    calculatePower();

    setHand();

}


void PokerHand::setHand()
{
    if (isStraight() && is_same_suit)
    {
        std::cout << "SF" << std::endl;
        real_pokerhand = PokerRank::StraightFlush;
        setPowerHand();

        return;
    }

    if (is_same_suit)
    {
        real_pokerhand = PokerRank::Flush;
        setPowerHand();
        return;
    }



    if (isStraight_answer)
    {
        real_pokerhand = PokerRank::Straight;
        setPowerHand();
        return;
    }



    if(isKind() || isTwoPair() || isFull() || isPair() || isThree())
        return;





    real_pokerhand = PokerRank::Nothing;
}

Result compare (const PokerHand &player, const PokerHand &opponent) {


    PokerRank player_pokerhand = player.real_pokerhand;
    PokerRank opponent_pokerhand = opponent.real_pokerhand;
    int player_poh = player.power_of_all_cards;
    int opponent_poh = opponent.power_of_all_cards;

    if (player_pokerhand > opponent_pokerhand)
    {

        return Result::Win;}

    if (player_pokerhand == opponent_pokerhand)
    {

        if (player_poh > opponent_poh)
            return Result::Win;



        auto player_types = player.getTypes();
        auto opponent_types = opponent.getTypes();

        for (int i = opponent_types.size()-1; i >= 0; i--)
        {


            if (opponent_types[i] > player_types[i]){
                return Result::Loss;}
            else if (opponent_types[i] < player_types[i])
            {
                return Result::Win;
            }
        }





            return Result::Tie;

   }
    return Result::Loss;
}

std::vector<int> PokerHand::getTypes() const
{
    std::vector<int> types;

    for (auto i = 4; i >= 0; i--)
    {
        int to_be_checked = splitted_cards_with_values_and_suits[i];
        if(isInSignature(to_be_checked))
            continue;
        types.push_back(to_be_checked);
    }

    std::sort(types.begin(), types.end());
    return types;

}
