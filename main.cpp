#include <iostream>
#include "Poker/include/Poker.hpp"
#include <assert.h>
#include <tuple>
#include <numeric>
int main()
{
//    std::vector<std::string> test {"AS", "AH", "2H", "AD", "AC"};

//    int power_of_hand = std::accumulate(std::begin(test),
//                                    std::end(test), 0,
//                                    [](auto a, auto b) { auto c = b[0] - '0';
//        std::cout << c; return a + c; });



     std::cout << "FIRST STAGE " << std::endl;
     assert( compare(PokerHand("2H 3H 4H 5H 6H"), PokerHand("KS AS TS QS JS")) == Result::Loss);
     // "Highest straight flush wins"
     std::cout << "Second STAGE " << std::endl << std::endl;
     assert  (compare(PokerHand("2H 3H 4H 5H 6H"), PokerHand( "AS AD AC AH JD")) == Result::Win );

//   // "Straight flush wins of 4 of a kind"
     std::cout << "Third STAGE "<< std::endl << std::endl;
     assert  (compare(PokerHand("AS AH 2H AD AC"), PokerHand( "JS JD JC JH 3D")) == Result::Win );
      // "Highest 4 of a kind wins"

     std::cout << "    4th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S AH 2H AS AC"), PokerHand( "JS JD JC JH AD")) == Result::Loss);
    // "4 Of a kind wins of full house"
     std::cout << "    5th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S AH 2H AS AC"), PokerHand( "2H 3H 5H 6H 7H")) == Result::Win );
    // "Full house wins of flush"
     std::cout << "    6th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("AS 3S 4S 8S 2S"), PokerHand( "2H 3H 5H 6H 7H")) == Result::Win );
    // "Highest flush wins"

    std::cout << "    7th stage    "  << std::endl << std::endl;
   assert  (compare(PokerHand("2H 3H 5H 6H 7H"), PokerHand( "2S 3H 4H 5S 6C")) == Result::Win );
   // "Flush wins of straight"
   std::cout << "    8th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S 3H 4H 5S 6C"), PokerHand( "3D 4C 5H 6H 2S")) == Result::Tie );
    // "Equal straight is tie"

    std::cout << "    9th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S 3H 4H 5S 6C"), PokerHand( "AH AC 5H 6H AS")) == Result::Win ); // "Straight wins of three of a kind"

    std::cout << "    10th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S 3H 4H 5S AC"), PokerHand( "AH AC 5H 6H AS")) == Result::Win );
    // "Low-ace straight wins of three of a kind"
    std::cout << "    11th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S 2H 4H 5S 4C"), PokerHand( "AH AC 5H 6H AS")) == Result::Loss);
    // "3 Of a kind wins of two pair"
    std::cout << "    12th stage    "  << std::endl << std::endl;
    assert  ( compare(PokerHand("2S 2H 4H 5S 4C"), PokerHand( "AH AC 5H 6H 7S")) == Result::Win );
    // "2 Pair wins of pair"
    std::cout << "    13th stage    "  << std::endl << std::endl;
    assert  ( compare(PokerHand("6S AD 7H 4S AS"), PokerHand( "AH AC 5H 6H 7S")) == Result::Loss );
    // "Highest pair wins"
    std::cout << "    14th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S AH 4H 5S KC"), PokerHand( "AH AC 5H 6H 7S")) == Result::Loss);
    // "Pair wins of nothing"
    std::cout << "    15th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S 3H 6H 7S 9C"), PokerHand( "7H 3C TH 6H 9S")) == Result::Loss);
    // "Highest card loses"
    assert  (compare(PokerHand("4S 5H 6H TS AC"), PokerHand( "3S 5H 6H TS AC")) == Result::Win );
    // "Highest card wins"
    std::cout << "    16th stage    "  << std::endl << std::endl;
    assert  (compare(PokerHand("2S AH 4H 5S 6C"), PokerHand( "AD 4C 5H 6H 2C")) == Result::Tie );
    // "Equal cards is tie"
}
