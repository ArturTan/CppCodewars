#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <set>
#include <map>

const static std::map<char, int> values_of_cards =
{
    { '2', 2 },
    { '3', 3 },
    { '4', 4 },
    { '5', 5 },
    { '6', 6 },
    { '7', 7 },
    { '8', 8 },
    { '9', 9 },
    { 'T', 10 },
    { 'J', 11 },
    { 'Q', 12 },
    { 'K', 13 },
    { 'A', 14 },
};

enum class PokerRank
{
    Nothing,
    Pair,
    TwoPair,
    Three,
    Straight,
    Flush,
    Full,
    FourOfKind,
    StraightFlush,

};


struct PokerHand {
    PokerHand (const char*);
    bool isKind();
    bool isStraight();
    bool isThree();
    bool isFull();
    bool isTwoPair();
    bool isPair();
    bool checker(int, int);
    bool CombosChecker(int, std::vector<int>, int);
    std::vector<int> getTypes() const;

    void setHand();





    std::map<int, int> map_of_results =
    {
        {  2, 0 },
        {  3, 0 },
        {  4, 0 },
        {  5, 0 },
        {  6, 0 },
        {  7, 0 },
        {  8, 0 },
        {  9, 0 },
        { 10, 0 },
        { 11, 0 },
        { 12, 0 },
        { 13, 0 },
        { 14, 0 },
    };

    void setMapper()
    {
        for (auto key : map_of_results)
            map_of_results[key.first] = std::count(splitted_cards_with_values_and_suits.begin(),
                                               splitted_cards_with_values_and_suits.end(),
                                               key.first);
    }



    void calculatePower()
    {
        power_of_all_cards = std::accumulate(splitted_cards_with_values_and_suits.begin(),
                               splitted_cards_with_values_and_suits.end(),
                               0,
                               [](auto a, auto i){ return a + i; });
    }


    bool isInSignature(int n) const
    {
        for (auto & i : signature)
            if (i == n)
                return true;
        return false;
    }

    void setPowerHand()
    {
        power_of_hand = std::accumulate(std::begin(splitted_cards_with_values_and_suits),
                                        std::end(splitted_cards_with_values_and_suits), 0,
                                        [&](auto sum, auto a) { return sum + a; });
    }

    std::vector<int> splitted_cards_with_values_and_suits;
    bool is_same_suit = true;
    PokerRank real_pokerhand = PokerRank::Nothing;
    int power_of_hand = 0;
    int power_of_all_cards;
    std::vector<int> signature;
    bool isStraight_answer = false;
    bool isFlush_answer = false;
};

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand&, const PokerHand&);
