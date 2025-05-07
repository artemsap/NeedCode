#include <iostream>
#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
            return 0;

        std::unordered_set<char> chars;
        chars.insert(s[0]);

        int maxLength = 1;
        for (int left = 0, right = 1; right < s.size(); right++)
        {
            while (chars.find(s[right]) != chars.end())
            {
                chars.erase(s[left]);
                left++;
            }

            maxLength = std::max(right - left + 1, maxLength);
            chars.insert(s[right]);
        }

        return maxLength;
    }
};


int main()
{
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("zxyzxyz") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("xxxx") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("zxyxzxzx") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("dvdf") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;
}
