#include <iostream>
#include <map>

class Solution 
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        std::map<char, int> chars_in_s1;
        for (const auto c1 : s1)
        {
            chars_in_s1[c1]++;
        }

        std::map<char, int> chars_in_win_s2;
        for (size_t i = 0; i < s1.size(); i++)
        {
            chars_in_win_s2[s2[i]]++;
        }

        for (size_t left = 0, right = s1.size(); right <= s2.size(); left++, right++)
        {
            if (chars_in_s1 == chars_in_win_s2)
            {
                return true;
            }

            if (--chars_in_win_s2[s2[left]] == 0)
            {
                chars_in_win_s2.erase(s2[left]);
            }

            if (right < s2.size())
            {
                chars_in_win_s2[s2[right]]++;
            }
        }

        return false;
    }
};


int main()
{
    Solution solution;
    solution.checkInclusion("abc", "lecabee");
    solution.checkInclusion("adc", "dcda");

    std::cout << "Hello World!\n";
}
