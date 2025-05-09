#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode dummy(0);
        ListNode* merged = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                merged->next = list1;
                list1 = list1->next;
            }
            else
            {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }

        if (list1 == nullptr)
        {
            merged->next = list2;
        }
        else
        {
            merged->next = list1;
        }

        return dummy.next;
    }
};

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    /*
    list2->next->next = new ListNode(2);
    list2->next->next->next = new ListNode(3);*/

    Solution solution;
    auto res = solution.mergeTwoLists(list1, list2);

    std::cout << "Hello World!\n";
}
