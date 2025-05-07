#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::vector<int> result;

        int maximum = nums[0];
        for (size_t left = 0, right = k; right <= nums.size(); left++, right++ )
        {
            auto max = *std::max_element(nums.data() + left, nums.data() + right);
            result.push_back(max);
        }

        return result;
    }
};


int main()
{
    Solution solution;

    std::vector<int> nums = { 1, 2, 1, 0, 4, 2, 6 };
    auto res = solution.maxSlidingWindow(nums, 3);

    std::cout << "Hello World!\n";
}
