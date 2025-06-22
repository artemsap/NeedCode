#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
private:
    void backtracking(int target_sum, std::vector<int>& combination, std::vector<std::vector<int>>& allcombination, const std::vector<int>& nums, size_t i)
    {
        if (target_sum == 0)
        {
            allcombination.push_back(combination);
        }
        
        if (target_sum <= 0 || i >= nums.size())
        {
            return;
        }

        combination.push_back(nums[i]);
        backtracking(target_sum - nums[i], combination, allcombination, nums, i);

        combination.pop_back();
        backtracking(target_sum, combination, allcombination, nums, i + 1);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) 
    {
        std::vector<std::vector<int>> allcombination;
        std::vector<int> combination;
        backtracking(target, combination, allcombination, nums, 0);
        return allcombination;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 2,5,6,9 };
    sol.combinationSum(nums, 9);
    std::cout << "Hello World!\n";
}