#include "BinarySearchTree.hpp"
#include "BinarySearchTree.hpp"
#include<iostream>

using namespace std;
typedef BinarySearchTree::DataType DataType;

BinarySearchTree::Node::Node (DataType newval)
{
    val = newval;
    left = NULL;
    right = NULL;
};

BinarySearchTree::BinarySearchTree()
{
    root_ = NULL;
    size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    if(root_ != NULL)
    {
        Node** arr = new Node*[size_];
        arr[0] = root_;
        Node* temp = root_;
        int index = 0;
        
        while(arr[0] != NULL && index >= 0)
        {
            //changing and printing temporary
            temp = arr[index];
            
            //if temp has RC, push
            if(temp -> right != NULL)
            {
                arr[index] = temp -> right;
                index++;
            }
            //if temp has LC, push
            if(temp -> left != NULL)
            {
                arr[index] = temp -> left;
                index++;
            }
            delete temp;
            index--;
        }
    }
}

bool BinarySearchTree::insert(DataType val)
{
    Node* newNode = new Node(val);
    Node* temp = root_;
    
    if(temp == NULL)
    {
        root_ = newNode;
        size_++;
        newNode = NULL;
        return true;
    }
    
    while(temp != NULL)
    {
        if(val > temp->val)
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                newNode = NULL;
                size_++;
                return true;
            }
            temp = temp->right;
        }
        else if(val < temp -> val)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                newNode = NULL;
                size_++;
                return true;
            }
            temp = temp->left;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool BinarySearchTree::remove(DataType val)
{
    Node* temp = root_;
    Node* parent = new Node(val);
    
    //if tree is empty, return false
    if(temp == NULL)
    {
        return false;
    }
    
    //locate the wanted node
    while(temp != NULL)
    {
        if(temp -> val == val)
        {
            break;
        } else if(temp -> val > val)
        {
            parent = temp;
            temp = temp -> left;
        } else if(temp -> val < val)
        {
            parent = temp;
            temp  = temp -> right;
        } else
        {
            break;
        }
    }
    
    if(temp == NULL)
    {
        return false;
    }
    
    //Case 1: no child
    if(temp -> left == NULL && temp -> right == NULL)
    {
        if(temp == root_)
        {
            root_ = NULL;
        } else if(temp -> val > parent -> val)
        {
            parent -> right = NULL;
        } else
        {
            parent -> left = NULL;
        }
        delete(temp);
        size_--;
        return true;
    }
    
    //Case 2: 1 child
    else if(temp -> left == NULL || temp -> right == NULL)
    {
        if(temp == root_)
        {
            if(temp -> left != NULL)
            {
                root_ = root_ -> left;
                root_ -> left = NULL;
            }
            else
            {
                root_ = root_ -> right;
                root_ -> right = NULL;
            }
        } else if(temp -> val > parent -> val)
        {
            if(temp -> left != NULL)
            {
                parent -> right = temp -> left;
            }
            else
            {
                parent -> right = temp -> right;
            }
        }
        else
        {
            if(temp -> left != NULL)
            {
                parent -> left = temp -> left;
            }
            else
            {
                parent -> left = temp -> right;
            }
        }
        delete(temp);
        size_--;
        return true;
    }
    //Case 3: 2 children
    else
    {
        Node* rept = temp -> left;
        while(rept -> right != NULL)
        {
            rept = rept -> right;
        }
        DataType reptVal = rept -> val;
        if (remove(reptVal) ==  false)
            return false;
        temp -> val = reptVal;
        return true;
    }
    
    return false;
}

bool BinarySearchTree::exists(DataType val) const
{
    Node* temp = root_;
    if(temp == NULL)
    {
        return false;
    } else
    {
        while(temp != NULL)
        {
            if(val > temp->val)
            {
                temp = temp->right;
            } else if(val < temp->val)
            {
                temp = temp->left;
            } else
            {
                return true;
            }
        }
        return true;
    }
    return false;
}

DataType BinarySearchTree::min() const
{
    if(root_ == NULL)
    {
        return -999;
    } else
    {
        Node* temp = root_;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->val;
    }
}

DataType BinarySearchTree::max() const
{
    if(root_ == NULL)
    {
        return -1;
    } else
    {
        Node* temp = root_;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->val;
    }
}

unsigned int BinarySearchTree::size() const
{
    return size_;
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    if(n == NULL)
    {
        return -1;
    }
    
    int leftDepth = getNodeDepth(n->left);
    int rightDepth = getNodeDepth(n->right);
    if(leftDepth > rightDepth)
    {
        return 1 + leftDepth;
    } else
    {
        return 1 + rightDepth;
    }
}

unsigned int BinarySearchTree::depth() const
{
    return getNodeDepth(root_);
}







