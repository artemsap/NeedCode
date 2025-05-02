#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
    {
        std::vector<int> warmerTemperatures(temperatures.size(), 0);

        for (size_t i = 0; i < temperatures.size(); i++)
        {
            for (size_t j = i; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    warmerTemperatures[i] = j - i;
                    break;
                }
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

    std::vector<int> temperatures{ 30, 38, 30, 36, 35, 40, 28 };
    auto res = solution.dailyTemperatures(temperatures);
    printVectorInt(res);
}
