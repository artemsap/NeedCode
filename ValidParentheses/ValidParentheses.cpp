#include <iostream>
#include <stack>

class Solution
{
private:
    bool IsOpenBracket(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }

    bool IsCloseBracket(char c)
    {
        return c == ')' || c == ']' || c == '}';
    }

    char GetOpositeBracket(char c)
    {
        if (c == ')')
            return '(';
        if (c == ']')
            return '[';
        if (c == '}')
            return '{';
        return ' ';
    }

public:
    bool isValid(std::string s)
    {
        std::stack<char> mystack;
        for (const char c : s)
        {
            if (IsOpenBracket(c))
            {
                mystack.push(c);
            }
            else if (IsCloseBracket(c))
            {
                if (mystack.empty() || mystack.top() != GetOpositeBracket(c))
                {
                    return false;
                }

                mystack.pop();
            }
            else
            {
                return false;
            }
        }

        return mystack.empty();
    }
};


int main()
{
    Solution solution;
    std::cout << solution.isValid("([{}])") << std::endl;
    std::cout << solution.isValid("()[]{}(((())))") << std::endl;
    std::cout << solution.isValid("(") << std::endl;
}
