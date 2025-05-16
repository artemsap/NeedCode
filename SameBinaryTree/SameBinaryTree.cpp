#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (!p && !q)
		{
			return true;
		}

		if (p && q && p->val == q->val) 
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else 
		{
			return false;
		}
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

	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(5);

	root1->right = new TreeNode(3);
	root1->right->right = new TreeNode(7);
	root1->right->right->right = new TreeNode(8);

	Solution solution;
	std::cout << solution.isSameTree(root, root1);
}
