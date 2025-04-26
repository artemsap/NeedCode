#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::set<int> unique_sort_nums(nums.begin(), nums.end());
        int maxLongCons = 0;
        int longCons = 1;
        int prevValue = *unique_sort_nums.begin();

        for (auto iter = std::next(unique_sort_nums.cbegin(), 1); iter != unique_sort_nums.cend(); ++iter)
        {
            if (prevValue + 1 == *iter)
            {
                longCons++;
            }
            else
            {
                maxLongCons = std::max(maxLongCons, longCons);
                longCons = 1;
            }

            prevValue = *iter;
        }

        maxLongCons = std::max(maxLongCons, longCons);

        return maxLongCons;
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums{ 2, 20, 4, 10, 3, 4, 5 };
    std::cout << solution.longestConsecutive(nums) << std::endl;

    std::vector<int> nums2{ 0,3,2,5,4,6,1,1 };
    std::cout << solution.longestConsecutive(nums2) << std::endl;
}