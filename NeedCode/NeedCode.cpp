#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isValidChar(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) 
    {
        string correct_str = "";

        for (const auto c : s)
        {
            if (isValidChar(c))
            {
                correct_str += std::tolower(c);
            }
        }

        return correct_str == string(correct_str.rbegin(), correct_str.rend());
    }
};


int main()
{
    Solution sol;

    std::cout << sol.isPalindrome("Was it a car or a cat I saw?");
}