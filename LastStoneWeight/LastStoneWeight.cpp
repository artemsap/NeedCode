#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    int lastStoneWeight(std::vector<int>& stones) 
    {
        std::make_heap(stones.begin(), stones.end());

        while (stones.size() > 1)
        {
            int top_weight_1 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int top_weight_2 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int new_weight_1 = top_weight_1 - top_weight_2;

            if (new_weight_1 != 0)
            {
                stones.push_back(new_weight_1);
                std::push_heap(stones.begin(), stones.end());
            }
        }

        if (stones.size() == 0)
        {
            return 0;
        }
        else
        {
            return stones.front();
        }
    }
};

int main()
{
    std::vector<int> stones = { 2, 3, 6, 2, 4 };

    Solution sol;
    std::cout << sol.lastStoneWeight(stones) << std::endl;
}
