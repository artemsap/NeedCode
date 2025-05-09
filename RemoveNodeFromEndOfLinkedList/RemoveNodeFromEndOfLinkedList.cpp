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
	int GetListSize(ListNode* const head)
	{
		int listSize = 0;

		ListNode* tmp = head;
		while (tmp)
		{
			listSize++;
			tmp = tmp->next;
		}

		return listSize;
	}

public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* tmp = head;
		int listSize = GetListSize(head);
		
		if (n == listSize)
		{
			auto next = head->next;
			delete head;
			return next;
		}

		if (n == 0)
		{
			while (head->next->next)
			{
				head = head->next;
			}
			delete head->next;
			head->next = nullptr;
			return tmp;
		}

		while (listSize - n > 1)
		{
			head = head->next;
			listSize--;
		}

		auto prev = head;
		auto todelete = head->next;
		auto next = head->next->next;

		prev->next = next;
		delete todelete;

		return tmp;
	}
};

int main()
{
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(3);
	list1->next->next->next = new ListNode(4);

	Solution solution;
	list1 = solution.removeNthFromEnd(list1, 2);

	ListNode* list2 = new ListNode(5);
	list2 = solution.removeNthFromEnd(list2, 1);

	std::cout << "Hello World!\n";
}
