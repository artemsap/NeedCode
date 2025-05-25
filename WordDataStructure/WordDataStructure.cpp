#include <iostream>
#include <vector>

class WordDictionary
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

    std::shared_ptr<TreeNode> root = nullptr;

public:
    WordDictionary() 
    {
        root = std::make_shared<TreeNode>();
        root->value = ' ';
    }

    void addWord(std::string word) 
    {
        insert(root, word);
    }

    bool search(std::string word) 
    {
        word += '\0';
        return searchWord(root, word);
    }

private:
    static void insert(std::shared_ptr<TreeNode> local_root, std::string word)
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

        char first_symbol = word.front();

        if (first_symbol == '.')
        {
            bool res = false;
            auto cut_str = word.substr(1);
            for (const auto child : local_root->childrens)
            {
                res |= searchWord(child, cut_str);

                if (res)
                {
                    return true;
                }
            }
            return false;
        }
        else if (auto find = local_root->findChildren(first_symbol); find)
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
    WordDictionary wordDictionary;
    wordDictionary.addWord("dog");
    //wordDictionary.addWord("bay");
    //wordDictionary.addWord("may");
    //std::cout << wordDictionary.search("say") << std::endl; // return false
    //std::cout << wordDictionary.search("day") << std::endl; // return true
    //std::cout << wordDictionary.search(".ay") << std::endl; // return true
    //std::cout << wordDictionary.search("b..") << std::endl; // return true
    std::cout << wordDictionary.search("do..");

    std::cout << "Hello World!\n";
}
