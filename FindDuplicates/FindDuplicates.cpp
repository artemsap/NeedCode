#include <iostream>
#include <vector>
#include <unordered_map>

class Solution 
{
public:
    int findDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int, int> nums_count;

        for (const auto num : nums)
        {
            if (++nums_count[num] > 1)
                return num;
        }

        return -1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
