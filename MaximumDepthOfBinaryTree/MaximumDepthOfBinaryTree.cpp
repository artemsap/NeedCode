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
	int max = 0;

	void maxDepth(TreeNode* root, int curDepth)
	{
		if (root == nullptr)
			return;

		max = std::max(max, ++curDepth);

		if (root->left != nullptr)
		{
			maxDepth(root->left, curDepth);
		}

		if (root->right != nullptr)
		{
			maxDepth(root->right, curDepth);
		}
	}

public:
    int maxDepth(TreeNode* root) 
	{
		max = 0;
		maxDepth(root, 0);
		return max;
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
	root->right->right->right = new TreeNode(8);

    std::cout << solution.maxDepth(root);
}
