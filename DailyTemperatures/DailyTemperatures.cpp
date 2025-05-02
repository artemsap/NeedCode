#include <iostream>
#include <vector>
#include <stack>

class Solution 
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
    {
        std::vector<int> warmerTemperatures(temperatures.size(), 0);

        std::stack<std::pair<size_t, int>> index_temp;
        for (int i = 0; i < temperatures.size() - 1; i++)
        {
            index_temp.emplace(std::make_pair(i, temperatures[i]));

            size_t nextIndex = i + 1;
            while (!index_temp.empty() && index_temp.top().second < temperatures[nextIndex])
            {
                size_t index = index_temp.top().first;
                warmerTemperatures[index] = nextIndex - index;
                index_temp.pop();
            }
        }

        return warmerTemperatures;
    }
};

void printVectorInt(std::vector<int>& temperatures)
{
    for (const auto temp : temperatures)
    {
        std::cout << temp << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    std::vector<int> temperatures{ 30,40,50,60 };
    auto res = solution.dailyTemperatures(temperatures);
    printVectorInt(res);
}
