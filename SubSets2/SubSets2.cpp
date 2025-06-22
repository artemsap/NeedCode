#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void backtracking(int i, std::vector<int> localsubset, std::vector<std::vector<int>>& res, std::vector<int>& nums)
    {
        if (i == nums.size())
        {
            res.push_back(localsubset);
            return;
        }

        localsubset.push_back(nums[i]);
        backtracking(i + 1, localsubset, res, nums);

        localsubset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        backtracking(i + 1, localsubset, res, nums);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        backtracking(0, {}, res, nums);
        return res;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 1, 2, 1 };
    auto res = sol.subsetsWithDup(nums);

    std::cout << "Hello World!\n";
}
