#include <iostream>

class TreeNode
{
    int m_key;
    int m_counter;

    TreeNode* ptr_left;
    TreeNode* ptr_right;

public:
    
    TreeNode()
    {
        m_key = 0;
        m_counter = 1;
        ptr_left = nullptr;
        ptr_right = nullptr;
    }
    TreeNode(int key)
    {
        m_key = key;
        m_counter = 1;
        ptr_left = nullptr;
        ptr_right = nullptr;
    }

    void print(TreeNode* root)
    {
        std::cout << "( ";
        std::cout << root->m_key;
        std::cout << " - ";
        std::cout << root->m_counter;
        std::cout << " )";
        if (root->ptr_right != nullptr)
        {
            std::cout << " --RIGHT-> ";
            print(root->ptr_right);
        }
        if (root->ptr_left != nullptr)
        {
            std::cout << "\n";
            std::cout << " --LEFT-> ";
            print(root->ptr_left);
        }
        
        return;
    }

    /*
    
    Выбирается среднее число. И вставляется в корень дерева.

    Варианты балансировки:

            1 Вариант               2 Вариант

                 0                      5
               /   \                /      \
              1     2              4        6
             / \   / \            / \      / \
            3   4 5   6          2   3    7   8
             ...   ...          /        / \
                               1        9  10
    

    
    */


    // Балансировка первым вариантом
    void balance(TreeNode* root)
    {
        
    } 

    void insert(int key, TreeNode* root)
    {
        if (root->m_key == key)
        {
            root->m_counter++;
            return;
        }

        if (key > root->m_key)
        {
            if (root->ptr_right == nullptr)
            {
                root->ptr_right = new TreeNode(key);
                return;
            }
            insert(key, root->ptr_right);
        }
        else {
            if (root->ptr_left == nullptr)
            {
                root->ptr_left = new TreeNode(key);
                return;
            }
            insert(key, root->ptr_left);
        }
        
        return;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);

    root->insert(2, root);
    root->insert(1, root);
    root->insert(2, root);
    root->insert(2, root);
    root->insert(5, root);
    root->insert(5, root);
    root->balance(root);
    root->print(root);
}