#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
	int smallest(TreeNode* root, int k, int& counter)
	{
		if (root->left)
		{
			auto res = smallest(root->left, k, counter);
			if (res != -1)
				return res;
		}

		if (++counter == k)
		{
			return root->val;
		}

		if (root->right)
		{
			auto res = smallest(root->right, k, counter);
			if (res != -1)
				return res;
		}

		return -1;
	}

public:
	int kthSmallest(TreeNode* root, int k) 
	{
		int dummy = 0;
		return smallest(root, k, dummy);
	}
};


int main()
{
	Solution solution;

	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);

	root->right = new TreeNode(5);

	auto levels = solution.kthSmallest(root, 4);

    std::cout << "Hello World!\n";
}
