#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <bitset>

class Solution
{
private:
    bool isValid(std::bitset<32> bitset_, int size)
    {
        std::stack<char> mystack;
        for (size_t i = 0; i < size; i++)
        {
            char c = bitset_[i];

            if (c == 0)
            {
                mystack.push(c);
            }
            else
            {
                if (mystack.empty() || mystack.top() != !c)
                {
                    return false;
                }

                mystack.pop();
            }
        }

        return mystack.empty();
    }
    
    std::string BitsetToSkobki(std::bitset<32> bitset_, int stringsize)
    {
        std::string skobki(stringsize, ' ');
        for (int i = 0; i < stringsize; i++)
        {
            if (bitset_[i] == 0)
            {
                skobki[i] = '(';
            }
            else
            {
                skobki[i] = ')';
            }
        }
        return skobki;
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        const int string_size = n * 2;

        std::vector<std::bitset<32>> bitset_skobka;

        int min = 0;
        int max = 0;
        for (size_t i = 0; i < n; i++)
        {
            min = min << 2;
            min += 1;
            max = max << 1;
            max += 1;
        }
        max = max << n;

        for (size_t i = min; i <= max; i++)
        {
            auto bitset = std::bitset<32>(i);

            if (isValid(bitset, string_size) && bitset.count() == n)
            {
                bitset_skobka.push_back(bitset);
            }
        }

        std::vector<std::string> vec_skobka(bitset_skobka.size());
        for (size_t i = 0; i < bitset_skobka.size(); i++)
        {
            vec_skobka[i] = BitsetToSkobki(bitset_skobka[i], string_size);
        }

        return vec_skobka;
    }
};

int main()
{
    Solution solution;
    for (const auto& skobki : solution.generateParenthesis(3))
    {
        std::cout << skobki << std::endl;
    }
}
