#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

class Solution
{
private:
    std::set<std::vector<int>> twoSum(const std::vector<int>& numbers, int targetIndex)
    {
        std::set<std::vector<int>> twoSum;
        for (int left = 0, right = numbers.size() - 1; left < right;)
        {
            if (left == targetIndex)
            {
                left++;
            }

            if (right == targetIndex)
            {
                right--;
            }

            if (left == right)
                break;

            int sum = numbers[left] + numbers[right];
            if (sum == -numbers[targetIndex])
            {
                twoSum.insert({ numbers[left], numbers[right] });
                left++;
            }
            else if (sum > -numbers[targetIndex])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return twoSum;
    }

public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>> triplets_set;
        for (int i = 0; i < nums.size(); i++)
        {
            auto res = twoSum(nums, i);
            if (res.empty())
            {
                continue;
            }

            for (const auto& el : res)
            {
                auto triplet = std::vector<int>{ el[0], el[1], nums[i] };
                std::sort(triplet.begin(), triplet.end());
                triplets_set.insert(triplet);
            }
        }

        return std::vector<std::vector<int>>(triplets_set.begin(), triplets_set.end());
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums = { -1,0,1,0 };
    auto res = solution.threeSum(nums);
    std::cout << "Hello World!\n";
}
