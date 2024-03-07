#pragma once

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
class List
{
public:
    List();
    virtual ~List();

    int Size();

    void PushFront(const T& data);
    void PushBack(const T& data);
    void PopFront();
    void PopBack();
    bool Empty();
    void Clear();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    class Iterator
    {
        friend List;
    public:
        Iterator(List* list, Node<T>* node);
        virtual ~Iterator();

        T& operator*();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);

        bool operator==(const Iterator& other);
        bool operator!=(const Iterator& other);

    private:
        List<T>* list;
        Node<T>* node;
    };

    Iterator Begin();
    Iterator End();
    Iterator Insert(Iterator iter, const T& value);
    Iterator Erase(Iterator iter);
};

template<typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
List<T>::~List()
{
    Clear();
}

template<typename T>
int List<T>::Size()
{
    return size;
}

template<typename T>
void List<T>::PushFront(const T& data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (0 == size)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

template<typename T>
void List<T>::PushBack(const T& data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (0 == size)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template<typename T>
void List<T>::PopFront()
{
    if (0 == size)
        throw exception("List is empty");

    Node<T>* deleteNode = head;
    if (1 == size)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete deleteNode;

    size--;
}

template<typename T>
void List<T>::PopBack()
{
    if (0 == size)
        throw exception("List is empty");

    Node<T>* deleteNode = tail;
    if (1 == size)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete deleteNode;

    size--;
}

template<typename T>
bool List<T>::Empty()
{
    return 0 == size;
}

template<typename T>
void List<T>::Clear()
{
    Node<T>* node = head;
    Node<T>* deleteNode;
    while (node != nullptr)
    {
        deleteNode = node;
        node = node->next;
        delete deleteNode;
    }
}

template<typename T>
typename List<T>::Iterator List<T>::Begin()
{
    return Iterator(this, head);
}

template<typename T>
typename List<T>::Iterator List<T>::End()
{
    return Iterator(this, nullptr);
}

template<typename T>
typename List<T>::Iterator List<T>::Insert(Iterator iter, const T& value)
{
    Node<T>* newNode = new Node<T>();
    Node<T>* leftNode = iter.node->prev;
    Node<T>* rightNode = iter.node;

    newNode->data = value;
    newNode->prev = leftNode;
    newNode->next = rightNode;

    if (leftNode == nullptr)
    {
        head = newNode;
    }
    else
    {
        leftNode->next = newNode;
    }

    if (rightNode == nullptr)
    {
        tail = newNode;
    }
    else
    {
        rightNode->prev = newNode;
    }

    return Iterator(this, newNode);
}

template<typename T>
typename List<T>::Iterator List<T>::Erase(Iterator iter)
{
    if (iter.node == nullptr)
        throw exception("Can not erase end list iterator");

    Node<T>* deleteNode = iter.node;
    Node<T>* leftNode = iter.node->prev;
    Node<T>* rightNode = iter.node->next;

    delete deleteNode;

    if (leftNode == nullptr)
    {
        head = rightNode;
    }
    else
    {
        leftNode->next = rightNode;
    }

    if (rightNode == nullptr)
    {
        tail = leftNode;
    }
    else
    {
        rightNode->prev = leftNode;
    }

    return Iterator(this, rightNode);
}

template<typename T>
List<T>::Iterator::Iterator(List* list, Node<T>* node)
{
    this->list = list;
    this->node = node;
}

template<typename T>
List<T>::Iterator::~Iterator()
{
}

template <typename T>
T& List<T>::Iterator::operator*()
{
    if (node == nullptr)
        throw exception("Can not dereference end list iterator");

    return node->data;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
    if (node == nullptr)
        throw exception("Can not increment end list iterator");

    node = node->next;
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
    Iterator iter = *this;
    ++(*this);
    return iter;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
    if (node == list->head)
        throw exception("Can not decrement begin list iterator");

    if (node == nullptr)
    {
        node = list->tail;
        return *this;
    }
    else
    {
        node = node->prev;
        return *this;
    }
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int)
{
    Iterator iter = *this;
    --(*this);
    return iter;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other)
{
    if (this->list == other.list &&
        this->node == other.node)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other)
{
    return !(*this == other);
}