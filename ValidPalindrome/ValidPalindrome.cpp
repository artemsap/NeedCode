#include <iostream>

class Solution {
private:
    bool isValidChar(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(std::string s)
    {
        std::string correct_str = "";

        for (const auto c : s)
        {
            if (isValidChar(c))
            {
                correct_str += std::tolower(c);
            }
        }

        return correct_str == std::string(correct_str.rbegin(), correct_str.rend());
    }
};

int main()
{
    Solution solution;

    std::string s = "Was it a car or a cat I saw?";
    std::cout << solution.isPalindrome(s) << std::endl;

    std::string s2 = "tab a cat";
    std::cout << solution.isPalindrome(s2) << std::endl;
}
