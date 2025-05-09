#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution 
{
public:
    bool hasCycle(ListNode* head) 
    {
        std::unordered_map<ListNode*, int> links;

        while (head)
        {
            if (++links[head] > 1)
            {
                return true;
            }
            head = head->next;
        }

        return false;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
