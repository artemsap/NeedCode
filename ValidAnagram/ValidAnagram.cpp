#include <algorithm>
#include <string>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.isAnagram("racecar", "carrace") << std::endl;

    std::cout << solution.isAnagram("jar", "jam") << std::endl;
}
