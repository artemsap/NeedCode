// EncodeAndDecodeStrings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

class Solution {
private:
    const char encode_char = '~';
public:
    std::string encode(std::vector< std::string>& strs) {
        std::string encoded_str = "";
        for (const auto& str : strs)
        {
            encoded_str += str + encode_char;
        }
        return encoded_str;
    }

    std::vector< std::string> decode(std::string s) {
        std::vector< std::string> result;

        auto find = s.find(encode_char);
        while (find != std::string::npos)
        {
            result.push_back(s.substr(0, find));
            s = s.erase(0, find + 1);
            find = s.find(encode_char);
        }

        return result;
    }
};

void printStringVector(const std::vector< std::string>& strs)
{
    for (const auto& str : strs)
    {
        std::cout << str << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    std::vector<std::string>Input{ "neet", "code", "love", "you" };
    printStringVector(Input);

    auto encoded = solution.encode(Input);
    std::cout << encoded << std::endl;

    auto decoded = solution.decode(encoded);
    printStringVector(decoded);
}
