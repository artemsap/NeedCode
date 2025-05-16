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
	TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root->val >= p->val && root->val <= q->val)
		{
			return root;
		}
		else if (root->val > p->val && root->val > q->val)
		{
			return lca(root->left, p, q);
		}
		else
		{
			return lca(root->right, p, q);
		}
	}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (p->val > q->val)
		{
			std::swap(q, p);
		}
	
		return lca(root, p, q);
    }
};


int main()
{
	Solution solution;

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(2);
	root->left->right = new TreeNode(4);

	root->right = new TreeNode(8);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(9);

	auto res = solution.lowestCommonAncestor(root, root->left, root->right);
	auto res2 = solution.lowestCommonAncestor(root, root->left, root->left->right);


    std::cout << "Hello World!\n";
}
