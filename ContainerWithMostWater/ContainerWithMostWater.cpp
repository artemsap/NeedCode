#include <iostream>
#include <vector>

class Solution 
{
public:
    int maxArea(std::vector<int>& heights)
    {
        int maxArea = 0;
        for (int left = 0, right = heights.size() - 1; left < right;)
        {
            int area = (right - left) * std::min(heights[left], heights[right]);
            maxArea = std::max(area, maxArea);

            if (heights[left] > heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution solution;

    std::vector<int> height{ 1,7,2,5,4,7,3,6 };
    std::cout << solution.maxArea(height) << std::endl;

    std::vector<int> height2{ 2,2,2 };
    std::cout << solution.maxArea(height2) << std::endl;
}
