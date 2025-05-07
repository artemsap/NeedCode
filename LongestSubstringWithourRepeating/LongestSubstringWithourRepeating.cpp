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
        for (size_t left = 0, right = 1; right < s.size();)
        {
            auto found = chars.find(s[right]);
            if (found == chars.end())
            {
                int length = right - left + 1;
                maxLength = std::max(length, maxLength);
                chars.insert(s[right]);
                right++;
            }
            else
            {
                chars.erase(s[left]);
                left++;
            }
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
