#include <iostream>
#include <vector>
#include <memory>

class PrefixTree
{
private:
    class TreeNode
    {
    public:
        char value;
        std::vector<std::shared_ptr<TreeNode>> childrens;

        std::shared_ptr<TreeNode> findChildren(char el) const
        {
            for (const auto child : childrens)
            {
                if (child->value == el)
                {
                    return child;
                }
            }

            return nullptr;
        }
    };

    std::shared_ptr<TreeNode> root;
public:
    PrefixTree()
    {
        root = std::make_shared<TreeNode>();
        root->value = ' ';
    }

    void insert(std::string word) 
    {
        insert(this->root, word);
    }

    bool search(std::string word) 
    {
        word += '\0';
        return searchWord(root, word);
    }

    bool startsWith(std::string prefix) 
    {
        return searchWord(root, prefix);
    }

private:
    void insert(std::shared_ptr<TreeNode> local_root, std::string word)
    {
        if (word.empty())
        {
            auto endWord = std::make_shared<TreeNode>();
            endWord->value = '\0';
            local_root->childrens.push_back(endWord);
            return;
        }

        auto find = local_root->findChildren(word.front());
        if (!find)
        {
            find = std::make_shared<TreeNode>();
            find->value = word.front();
            local_root->childrens.push_back(find);
        }

        insert(find, word.substr(1));
    }

    bool searchWord(std::shared_ptr<TreeNode> local_root, std::string word)
    {
        if (word.empty())
        {
            return true;
        }

        if (auto find = local_root->findChildren(word.front()); find)
        {
            return searchWord(find, word.substr(1));
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    PrefixTree tree;
    tree.insert("Hello");
    tree.insert("Hella");

    auto res = tree.search("Hello");
    auto res2 = tree.search("Helle");
    auto res3 = tree.startsWith("He");
    auto res4 = tree.startsWith("Ho");

}
