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
