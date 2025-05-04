#include <iostream>
#include <vector>

class Solution
{
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
	{
		auto getColumn = [&](int num)
		{
			return (int)(num % matrix[0].size());
		};

		auto getRow = [&](int num, int column)
		{
			return (num - column) / (int)matrix[0].size();
		};

		int left = 0;
		int right = (int)matrix.size() * (int)matrix[0].size() - 1;

		while (left < right)
		{
			int m_index = (right + left + 1) / 2;

			int col = getColumn(m_index);
			int row = getRow(m_index, col);
			if (matrix[row][col] <= target)
			{
				left = m_index;
			}
			else
			{
				right = m_index - 1;
			}
		}

		int col = getColumn(left);
		int row = getRow(left, col);
		return matrix[row][col] == target;
	}
};


int main()
{
	Solution solution;

	std::vector<std::vector<int>> matrix = { {1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40} };
	std::cout << solution.searchMatrix(matrix, 10) << std::endl;

	std::vector<std::vector<int>> matrix2 = {{1}};
	std::cout << solution.searchMatrix(matrix2, 10) << std::endl;

	std::vector<std::vector<int>> matrix3 = { {1}, {3} };
	std::cout << solution.searchMatrix(matrix3, 3) << std::endl;

	std::vector<std::vector<int>> matrix4 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	std::cout << solution.searchMatrix(matrix4, 20) << std::endl;

}

