#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
	{
		std::vector<std::vector<int>> res;
		size_t n = intervals.size(), i = 0;

		while (i < n && intervals[i][1] < newInterval[0])
		{
			res.push_back(intervals[i]);
			i++;
		}

		while (i < n && newInterval[1] >= intervals[i][0])
		{
			newInterval[0] = std::min(newInterval[0], intervals[i][0]);
			newInterval[1] = std::max(newInterval[1], intervals[i][1]);
			i++;
		}
		res.push_back(newInterval);

		while (i < n)
		{
			res.push_back(intervals[i]);
			i++;
		}

		return res;
	}
};

int main()
{
	std::vector<std::vector<int>> intervals = { {1,5} };
	std::vector<int> newInterval = { 0, 6 };

	Solution sol;
	auto res = sol.insert(intervals, newInterval);

	std::cout << "Hello World!\n";
}
