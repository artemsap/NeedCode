#include <iostream>
#include <vector>
#include <list>

class Solution 
{
private:
    void backtracking(std::vector<size_t> indexes, std::vector<int> localpermutation, std::vector<std::vector<int>>& allpermutation, const std::vector<int>& nums)
    {
        if (indexes.empty())
        {
            allpermutation.push_back(localpermutation);
            return;
        }

        for (size_t i = 0; i < indexes.size(); i++)
        {
            localpermutation.push_back(nums[indexes[i]]);
            auto copy = indexes;
            copy.erase(copy.begin() + i);
            backtracking(copy, localpermutation, allpermutation, nums);
            localpermutation.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        std::vector<size_t> indexes;
        for (size_t i = 0; i < nums.size(); i++)
        {
            indexes.push_back(i);
        }
        std::vector<std::vector<int>> allpermutation;
        backtracking(indexes, std::vector<int>(), allpermutation, nums);
        return allpermutation;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 1,2,3 };
    sol.permute(nums);

    std::cout << "Hello World!\n";
}
