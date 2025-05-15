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
private:
	std::pair<int, bool> diameterofSubTree(TreeNode* root)
	{
		if (root == nullptr)
			return { 0, true };

		auto l = diameterofSubTree(root->left);
		if (!l.second)
			return { 0, false };

		auto r = diameterofSubTree(root->right);
		if (!r.second)
			return { 0, false };

		return { 1 + std::max(l.first, r.first), abs(l.first - r.first) <= 1};
	}

public:
    bool isBalanced(TreeNode* root) 
	{
		auto res = diameterofSubTree(root);
		return res.second;
    }
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	root->right = new TreeNode(3);
	root->right->right = new TreeNode(7);
	root->right->right->right = new TreeNode(8);

	Solution solution;
	std::cout << solution.isBalanced(root);
}
