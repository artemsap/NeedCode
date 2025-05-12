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
private:
	int GetNum(ListNode* const lst)
	{
		int listsize = 0;
		float num = 0;
		ListNode* lstcopy = lst;
		while (lstcopy)
		{
			num += lstcopy->val;
			num /= 10;
			lstcopy = lstcopy->next;
			listsize++;
		}

		for (size_t i = 0; i < listsize; i++)
		{
			num *= 10;
		}

		return std::round(num);
	}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int num1 = GetNum(l1);
		int num2 = GetNum(l2);

		int summ = num1 + num2;
		ListNode dummy(0);
		ListNode* result = &dummy;
		
		if (summ == 0)
		{
			result->next = new ListNode(0);
		}
		else
		{
			while (summ != 0)
			{
				result->next = new ListNode(summ % 10);
				result = result->next;
				summ /= 10;
			}
		}

		return dummy.next;
    }
};

int main()
{
	ListNode* list1 = new ListNode(0);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(3);
	list1->next->next->next = new ListNode(4);

	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(2);
	list2->next->next = new ListNode(3);
	list2->next->next->next = new ListNode(4);

	Solution solution;
	auto listsumm = solution.addTwoNumbers(list1, list2);

    std::cout << "Hello World!\n";
}
