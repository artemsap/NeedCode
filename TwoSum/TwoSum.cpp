#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return std::vector<int>{i, j};
                }
            }
        }
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums{ 3, 4, 5, 6 };
    int target = 7;
    for (const auto& num : solution.twoSum(nums, target))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2{ 4, 5, 6 };
    int target2 = 10;
    for (const auto& num : solution.twoSum(nums2, target2))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3{ 5, 5 };
    int target3 = 10;
    for (const auto& num : solution.twoSum(nums3, target3))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
