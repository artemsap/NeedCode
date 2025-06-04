#include <iostream>
#include <vector>
#include <queue>

class Solution 
{
public:
    int findKthLargest(std::vector<int>& nums, int k) 
    {
        auto greater = [](int a, int b)
        {
            return a > b;
        };

        std::make_heap(nums.begin(), nums.end(), greater);

        while (nums.size() > k)
        {
            std::pop_heap(nums.begin(), nums.end(), greater);
            nums.pop_back();
        }

        return nums.front();
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 3,2,1,5,6,4 };
    std::cout << sol.findKthLargest(nums, 2) << std::endl;
}
