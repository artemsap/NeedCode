#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
    {
        std::map<std::string, std::vector<std::string>> mapka;

        for (const auto& str : strs)
        {
            auto str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            mapka[str_copy].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& vectors : mapka)
        {
            result.push_back(vectors.second);
        }

        return result;
    }
};

void printResult(std::vector<std::vector<std::string>>& result)
{
    for (const auto& group : result)
    {
        for (const auto& element : group)
        {
            std::cout << element << ' ';
        }

        std::cout << std::endl;
    }
}

int main()
{
    Solution solution;

    std::vector<std::string> str{ "act","pots","tops","cat","stop","hat" };
    auto result = solution.groupAnagrams(str);
    printResult(result);
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
