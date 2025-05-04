#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
private:
    int GetHourEatingBananas(int speed, std::vector<int>& piles)
    {
        int monkey_hour = 0;
        for (auto pile : piles)
        {
            int ostatok = pile % speed;
            monkey_hour += pile / speed;

            if (ostatok != 0)
                monkey_hour++;
        }
        return monkey_hour;
    }
public:
    int minEatingSpeed(std::vector<int>& piles, int goal_h) 
    {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        int min_h = right;
        while (left < right)
        {
            int m_index = (right + left) / 2;

            int local_h = GetHourEatingBananas(m_index, piles);
            if (local_h <= goal_h && min_h > m_index)
            {
                right = m_index;
                min_h = m_index;
            }
            else
            {
                left = m_index + 1;
            }
        }

        return left;
    }
};


int main()
{
    Solution solution;

    std::vector<int>  piles = { 1, 4, 3, 2 };
    std::cout << solution.minEatingSpeed(piles, 9) << std::endl;

    std::vector<int>  piles2 = { 25, 10, 23, 4 };
    std::cout << solution.minEatingSpeed(piles2, 4) << std::endl;
}
