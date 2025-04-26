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

int main()
{
    Solution solution;

    std::vector<int> nums{ 1,2,2,3,3,3 };
    for (const auto& element : solution.topKFrequent(nums, 2))
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2{ 7, 7 };
    for (const auto& element : solution.topKFrequent(nums2, 1))
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

}
