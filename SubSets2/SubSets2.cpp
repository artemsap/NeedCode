#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    void backtracking(size_t index, std::vector<int>& localsubset, std::vector<std::vector<int>>& subsets, const std::vector<int>& nums)
    {
        if (index >= nums.size())
        {
            std::sort(localsubset.begin(), localsubset.end());

            if (std::find(subsets))
            subsets.push_back(localsubset);
            return;
        }

        localsubset.push_back(nums[index]);
        backtracking(index + 1, localsubset, subsets, nums);

        localsubset.pop_back();
        backtracking(index + 1, localsubset, subsets, nums);
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {
        //std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> subsets;
        std::vector<int> localsubset;
        backtracking(0, localsubset, subsets, nums);
        return subsets;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 1, 2, 1 };
    auto res = sol.subsetsWithDup(nums);

    std::cout << "Hello World!\n";
}
