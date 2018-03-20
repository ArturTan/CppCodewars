/*The drawing below gives an idea of how to cut a given "true" rectangle into squares ("true" rectangle meaning that the two dimensions are different).

alternative text

Can you translate this drawing into an algorithm?

You will be given two dimensions

a positive integer length (parameter named lng)
a positive integer width (parameter named wdth)
You will return an array with the size of each of the squares.

Shell bash returns a string.

squaresInRect  5  3 `shouldBe` Just [3,2,1,1]
squaresInRect  3  5 `shouldBe` Just [3,2,1,1]
squaresInRect 20 14 `shouldBe` Just [14, 6, 6, 2, 2, 2]
#Note: lng == wdth as a starting case would be an entirely different problem and the drawing is planned to be interpreted with lng != wdth. See kata, Square into Squares. Protect trees!.

When the initial parameters are so that lng == wdth, the solution [lng] would be the most obvious but not in the spirit of this kata so, in that case, return None/nil/null/Nothing. Return {} with C++. Return the string "nil" with Bash.

In that case the returned structure of C will have its sz component equal to 0. (See the "Solution" and "Examples" tabs)

squaresInRect 5 5 `shouldBe` Nothing

*/

#include <vector>
#include <iostream>
#include <algorithm>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth);
};

std::vector <int> SqInRect::sqInRect(int lng, int wdth)
{
     std::vector<int> v;
     if (wdth != lng)
         while (true)
         {
             int n;

             if (wdth > lng)
                 std::swap(lng, wdth);
             if (!wdth)
             {
                 std::fill_n(std::back_inserter(v), wdth, 1);
                 break;
             }
             v.push_back(wdth);
             lng -= wdth;
         }

     return v;
}


int main()
{

    for (auto & i : SqInRect::sqInRect(5,3))
        std::cout << i << std::endl;
}
