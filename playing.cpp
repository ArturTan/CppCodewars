/*Everyone knows passphrases. One can choose passphrases from poems,
songs, movies names and so on but frequently they can be guessed due to common cultural references. You can get your passphrases stronger by different means. One is the following:

choose a text in capital letters including or not digits and non alphabetic characters,

shift each letter by a given number but the transformed letter must be a letter (circular shift),
replace each digit by its complement to 9,
keep such as non alphabetic and non digit characters,
downcase each letter in odd position, upcase each letter in even position (the first character is in position 0),
reverse the whole result.
#Example:

your text: "BORN IN 2015!", shift 1

1 + 2 + 3 -> "CPSO JO 7984!"

4 "CpSo jO 7984!"

5 "!4897 Oj oSpC"

With longer passphrases it's better to have a small and easy program. Would you write it?

https://en.wikipedia.org/wiki/Passphrase*/

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <cctype>

class PlayPass
{
  public:
  static std::string playPass(const std::string &s, int n);
};

std::string PlayPass::playPass(const std::string &s, int n)
{
     std::map<char, int> transgression;
     auto alphabet_to_up = [x = 'A', &n, &transgression] () mutable
     {
         char temp = x + n;
         if (x > (90 - n))
         {
             temp = 64 + (n - (90 - x));
         };
         transgression[x] = temp;
         x++;
     };

     for ( int it = 0; it <= 122-97; ++it)
         alphabet_to_up();

     for (auto & pair : transgression)
         transgression[::tolower(pair.first)] = ::tolower(pair.second);

     for (auto i = '0'; i <= '9'; ++i)
         transgression[i] = '9' - (i - '0');


     //for (auto & c : transgression)
       //  std::cout << c.first << " " << c.second << std::endl;
     std::string new_s = s;
     auto changer = [place = 1, &transgression]( unsigned char letter) mutable -> unsigned char
     {
         char letter2 = letter;
         auto it = transgression.find(letter);
         if (it != transgression.end())
         {
             if(std::isdigit(it->first))
             {
                 letter2 = it->second;
             }
             else
             {
                   if (!(place%2))
                       letter2 = ::tolower(it->second);
                   else
                       letter2 = ::toupper(it->second);
             }
         }
         place++;

         return letter2;
     };

     std::transform(s.begin(), s.end(), new_s.begin(), changer);
     std::reverse(new_s.begin(), new_s.end());
     std::cout << s << " ===> " << new_s << std::endl;
     return new_s;
}

int main()
{
    PlayPass::playPass("I LOVE YOU!!!", 1);
}

