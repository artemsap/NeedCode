#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int localmaxSum = 0, globalmaxSum = -100000000;
        for (size_t i = 0; i < nums.size(); i++)
        {
            localmaxSum += nums[i];
            globalmaxSum = std::max(globalmaxSum, localmaxSum);

            if (localmaxSum < 0)
            {
                localmaxSum = 0;
            }
        }

        return globalmaxSum;
    }
};



int main()
{
    Solution sol;
    std::vector<int> nums = { 2, -3, 4, -2, 2, 1, -1, 4 };
    std::cout << sol.maxSubArray(nums);

    std::vector<int> nums2 = { -1 };
    std::cout << sol.maxSubArray(nums2);;
}