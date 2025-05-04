#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int search(std::vector<int>& nums, int target) 
    {
        std::sort(nums.rbegin(), nums.rend());

        int left = 0;
        int right = (int)nums.size();

        while (left < right)
        {
            int m_index = (right + left) / 2;

            if (nums[m_index] <= target)
            {
                right = m_index;
            }
            else
            {
                left = m_index + 1;
            }
        }

        if (nums[left] == target)
        {
            return nums.size() - left - 1;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums = { -1,0,3,5,9,12 };
    std::cout << solution.search(nums, 9) << std::endl;
}
