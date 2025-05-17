#include <iostream>
#include <vector>

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
	void rightSide(TreeNode* root, int cur_level, std::vector<int>& rightView)
	{
		if (!root)
			return;

		cur_level++;

		if (rightView.size() < cur_level)
		{
			rightView.push_back(root->val);
		}

		rightSide(root->right, cur_level, rightView);
		rightSide(root->left, cur_level, rightView);
	}

public:
    std::vector<int> rightSideView(TreeNode* root)
    {
		std::vector<int> right;
		rightSide(root, 0, right);
		return right;
    }
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution solution;
	auto res = solution.rightSideView(root);

    std::cout << "Hello World!\n";
}
