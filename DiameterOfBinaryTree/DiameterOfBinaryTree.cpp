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
	int diameterofSubTree(TreeNode* root, int& res)
	{
		if (root == nullptr)
			return 0;

		int lHeight = diameterofSubTree(root->left, res);
		int rHeight = diameterofSubTree(root->right, res);

		res = std::max(res, lHeight + rHeight);

		return 1 + std::max(lHeight, rHeight);
	}

public:
	int diameterOfBinaryTree(TreeNode* root) 
	{
		int res = 0;
		diameterofSubTree(root, res);
		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
