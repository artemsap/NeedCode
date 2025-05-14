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
	void SwapChildren(TreeNode* root)
	{
		if (root == nullptr)
			return;

		std::swap(root->left, root->right);

		if (root->left != nullptr)
		{
			SwapChildren(root->left);
		}

		if (root->right != nullptr)
		{
			SwapChildren(root->right);
		}
	}

public:
	TreeNode* invertTree(TreeNode* root)
	{
		SwapChildren(root);
		return root;
	}
};


int main()
{
	Solution solution;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	solution.invertTree(root);
}
