#include <iostream>
#include <vector>

class Solution 
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int profit = 0;
        int maxProfit = 0;

        for (size_t left = 0, right = 1; right < prices.size(); right++)
        {
            if (prices[right] > prices[left])
            {
                profit = prices[right] - prices[left];
                maxProfit = std::max(profit, maxProfit);
            }
            else
            {
                left = right;
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution solution;

    std::vector<int> prices = {10, 1, 5, 6, 7, 1};
    std::cout << solution.maxProfit(prices) << std::endl;
}
