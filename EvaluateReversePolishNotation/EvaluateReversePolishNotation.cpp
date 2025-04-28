#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution
{
private:
    void calcOperation(std::stack<int>& operations, std::string operation)
    {
        int rightValue = operations.top();
        operations.pop();
        int leftValue = operations.top();
        operations.pop();

        if (operation == "+")
        {
            leftValue += rightValue;
        }
        else if (operation == "-")
        {
            leftValue -= rightValue;
        }
        else if (operation == "*")
        {
            leftValue *= rightValue;
        }
        else
        {
            leftValue /= rightValue;
        }

        operations.push(leftValue);
    }
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> operations;

        for (const auto& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                calcOperation(operations, token);
            }
            else
            {
                operations.push(std::stoi(token));
            }
        }

        return operations.top();
    }
};


int main()
{
    Solution solution;

    std::vector<std::string> tokens = { "1", "2", "+", "3", "*", "4", "-" };
    std::cout << solution.evalRPN(tokens) << std::endl;
}
