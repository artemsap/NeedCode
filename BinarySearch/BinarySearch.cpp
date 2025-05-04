#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int search(std::vector<int>& nums, int target) 
    {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right)
        {
            int m_index = (right + left + 1) / 2;

            if (nums[m_index] <= target)
            {
                left = m_index;
            }
            else
            {
                right = m_index - 1;
            }
        }

        if (nums[left] == target)
        {
            return left;
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

    std::vector<int> nums = { 5 };
    std::cout << solution.search(nums, 5) << std::endl;

    std::vector<int> nums2 = { -1,0,2,4,6,8 };
    std::cout << solution.search(nums2, 4) << std::endl;

    std::vector<int> nums3 = { -1,0,2,4,6,8 };
    std::cout << solution.search(nums2, 3) << std::endl;
}
