// MinStack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class MyStack
{
private:
    template <typename V>
    class Node
    {
    public:
        V value;
        Node* pNext;

        Node(V value = {}, Node* pNext = nullptr)
        {
            this->value = value;
            this->pNext = pNext;
        }
    };
public:
    MyStack() : numElements(0), topNode(nullptr) {}

    virtual ~MyStack()
    {
        clear();
    }

    virtual void push(T val)
    {
        topNode = new Node<T>(val, topNode);
        numElements++;
    }

    virtual void pop()
    {
        Node<T>* oldNode = topNode;
        topNode = oldNode->pNext;
        delete oldNode;
        
        numElements--;

        if (numElements == 0)
        {
            topNode = nullptr;
        }
    }

    virtual T top()
    {
        return topNode->value;
    }

    virtual void clear()
    {
        while (topNode)
        {
            pop();
        }
    }

    bool Empty()
    {
        return numElements == 0;
    }

private:
    Node<T>* topNode;
    size_t numElements;
};

class MinStack : public MyStack<int>
{
public:
    MinStack() {}

    void push(int val) override 
    {
        if (minValuesStack.Empty())
        {
            minValuesStack.push(val);
        }
        else
        {
            int newMinValue = std::min(minValuesStack.top(), val);
            minValuesStack.push(newMinValue);
        }

        MyStack::push(val);
    }

    void pop() override
    {
        minValuesStack.pop();
        MyStack::pop();
    }

    int getMin() 
    {
        return minValuesStack.top();
    }

private:
    MyStack<int> minValuesStack;
};

int main()
{
    MinStack minStack; 
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    std::cout << minStack.getMin() << std::endl; // return 0
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // return 2
    std::cout << minStack.getMin() << std::endl; // return 1
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
