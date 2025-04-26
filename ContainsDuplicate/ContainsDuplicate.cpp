#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int, int> res;

        for (const auto& num : nums)
        {
            if (++res[num] > 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums{ 1, 2, 3, 3 };
    std::cout << solution.hasDuplicate(nums) << std::endl;

    std::vector<int> nums2{ 1, 2, 3, 4 };
    std::cout << solution.hasDuplicate(nums2) << std::endl;
}
