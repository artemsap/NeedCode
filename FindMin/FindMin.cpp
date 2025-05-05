#include <iostream>
#include <vector>

class Solution 
{
public:
    int findMin(std::vector<int>& nums)
    {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right)
        {
            int m_index = (right + left) / 2;

            if (nums[left] > nums[m_index] && nums[m_index] < nums[right])
            {
                right = m_index;
            }
            else if(nums[left] <= nums[m_index] && nums[m_index] <= nums[right])
            {
                return nums[left];
            }
            else
            {
                left = m_index + 1;
            }
        }

        return nums[left];
    }
};


int main()
{
    Solution solution;

    std::vector<int> nums = { 3, 4, 5, 6, 1, 2 };
    std::cout << solution.findMin(nums) << std::endl;

    std::vector<int> nums2 = { 1, 2, 3, 4, 5, 6 };
    std::cout << solution.findMin(nums2) << std::endl;
}
