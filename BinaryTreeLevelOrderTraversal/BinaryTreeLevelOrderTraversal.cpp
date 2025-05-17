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
	void addtovec(TreeNode* root, int cur_level, std::vector<std::vector<int>>& levels)
	{
		if (!root)
			return;

		cur_level++;

		if (levels.size() < cur_level)
		{
			levels.push_back(std::vector<int>(1, root->val));
		}
		else
		{
			levels[cur_level - 1].push_back(root->val);
		}

		addtovec(root->left, cur_level, levels);
		addtovec(root->right, cur_level, levels);
	}

public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root)
	{
		std::vector<std::vector<int>> levels;
		addtovec(root, 0, levels);
		return levels;
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

	auto levels = solution.levelOrder(root);

    std::cout << "Hello World!\n";
}
