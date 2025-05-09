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
	ListNode* reverseList(ListNode* head)
	{
		if (head->next == nullptr)
			return head;

		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			auto temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}

 		return prev;
	}
};	


int main()
{
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);

	Solution solution;
	auto newhead = solution.reverseList(head);

	std::cout << "Hello World!\n";
}
