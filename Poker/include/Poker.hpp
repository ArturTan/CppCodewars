#pragma once
#include <vector>

struct PokerHand {
    PokerHand (const char*);
    void isStraight();

private:
    std::vector<std::tuple<char, char>> splitted_cards_with_values_and_suits;
    bool is_same_suit;
    bool isStraight_ = false;
};

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand&, const PokerHand&);
