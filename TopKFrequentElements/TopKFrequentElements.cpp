#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numbers_freq;
        for (const auto num : nums)
        {
            numbers_freq[num]++;
        }

        std::vector<std::pair<int, int>> vec_num_freq;
        for (const auto& it : numbers_freq) {
            vec_num_freq.push_back({ it.second, it.first });
        }
        std::sort(vec_num_freq.rbegin(), vec_num_freq.rend());

        std::vector<int> result(k);
        for (int i = 0; i < result.size(); i++) {
            result[i] = vec_num_freq[i].second;
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

    std::vector<int> nums{ 1,2,2,3,3,3 };
    auto result = solution.topKFrequent(nums, 2);
    printIntVector(result);

    std::vector<int> nums2{ 7, 7 };
    auto result2 = solution.topKFrequent(nums2, 1);
    printIntVector(result2);
}
