#pragma once

using namespace std;

template <typename T>
struct BinaryNode
{
    T data;
    BinaryNode* parent;
    BinaryNode* left;
    BinaryNode* right;
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    int Size();
    bool Empty();
    void Clear();

    void Insert(const T& data);
    void Erase(const T& data);
    bool Contain(const T& data);

private:
    BinaryNode<T>* root;
    int size;

    void Remove(BinaryNode<T>* node);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
    size = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    Clear();
}

template<typename T>
int BinarySearchTree<T>::Size()
{
    return size;
}

template<typename T>
bool BinarySearchTree<T>::Empty()
{
    return 0 == size;
}

template<typename T>
void BinarySearchTree<T>::Clear()
{
    while (!Empty())
    {
        Remove(root);
    }
}

template<typename T>
void BinarySearchTree<T>::Insert(const T& data)
{
    if (Empty())
    {
        BinaryNode<T>* newNode = new BinaryNode<T>();
        newNode->data = data;
        root = newNode;
        size++;
        return;
    }

    BinaryNode<T> current = root;
    while (nullptr != current)
    {
        if (data < current->data)
        {
            if (nullptr == current->left)
            {
                BinaryNode<T>* newNode = new BinaryNode<T>();
                newNode->data = data;
                newNode->parent = current;
                current->left = newNode;
                size++;
                break;
            }

            current = current->left;
        }
        else if (data > current->data)
        {
            if (nullptr == current->right)
            {
                BinaryNode<T>* newNode = new BinaryNode<T>();
                newNode->data = data;
                newNode->parent = current;
                current->right = newNode;
                size++;
                break;
            }

            current = current->right;
        }
        else
        {
            break;
        }
    }
}

template<typename T>
void BinarySearchTree<T>::Erase(const T& data)
{
    BinaryNode<T> current = root;
    while (nullptr != current)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            Remove(current);
            break;
        }
    }
}

template<typename T>
bool BinarySearchTree<T>::Contain(const T& data)
{
    BinaryNode<T> current = root;
    while (nullptr != current)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            return true;
        }
    }

    return false;
}

template<typename T>
void BinarySearchTree<T>::Remove(BinaryNode<T>* node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        BinaryNode<T>* parent = node->parent;
        if (parent == nullptr)
        {
            root = nullptr;
        }
        else if (parent->left == node)
        {
            parent->left = nullptr;
        }
        else if (parent->right == node)
        {
            parent->right = nullptr;
        }
        delete node;
        size--;
    }
    else if (node->left == nullptr || node->right == nullptr)
    {
        BinaryNode<T>* parent = node->parent;
        BinaryNode<T>* child = node->left != nullptr ? node->left : node->right;
        if (parent == nullptr)
        {
            root = child;
            child->parent = nullptr;
        }
        else if (parent->left == node)
        {
            parent->left = child;
            child->parent = parent;
        }
        else if (parent->right == node)
        {
            parent->right = child;
            child->parent = parent;
        }
        delete node;
        size--;
    }
    else
    {
        BinaryNode<T>* nextNode = node->right;
        while (nextNode->left != nullptr)
        {
            nextNode = nextNode->left;
        }
        node->data = nextNode->data;
        Remove(nextNode);
    }
}
