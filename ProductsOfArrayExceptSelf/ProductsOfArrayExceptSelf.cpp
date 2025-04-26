#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int prod_all_num = 1;
        int zero_count = false;

        for (const auto& num : nums)
        {
            if (num == 0)
            {
                zero_count++;
                continue;
            }

            prod_all_num *= num;
        }

        if (zero_count > 1)
        {
            return std::vector<int>(nums.size(), 0);
        }

        std::vector<int> result(nums.size(), prod_all_num);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (zero_count > 0 && nums[i] != 0)
            {
                result[i] = 0;
            }
            else if (zero_count == 0)
            {
                result[i] /= nums[i];
            }
        }

        return result;
    }
};

void printIntVector(const std::vector<int>& nums)
{
    for (const auto& num : nums)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    std::vector<int> nums{ 1,2,4,6 };
    auto result = solution.productExceptSelf(nums);
    printIntVector(result);

    std::vector<int> nums2{ -1,0,1,2,3 };
    auto result2 = solution.productExceptSelf(nums2);
    printIntVector(result2);
}
