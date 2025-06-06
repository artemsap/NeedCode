#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
            [](std::vector<int>& interval1, std::vector<int>& interval2)
            {
                return interval1[0] < interval2[0];
            });

        std::vector<std::vector<int>> res;
        res.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++)
        {
            int start = res.back()[0];
            int end = res.back()[1];

            if (intervals[i][0] <= end && intervals[i][1] > end)
            {
                res[res.size() - 1][1] = intervals[i][1];
            }
            else if (intervals[i][0] > end)
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> intervals = {{1, 4}, {2, 3}};
    Solution sol;
    sol.merge(intervals);
    std::cout << "Hello World!\n";
}
