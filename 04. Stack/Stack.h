#pragma once

using namespace std;

template <typename T>
class Stack
{
public:
    Stack();
    virtual ~Stack();

    size_t Size();

    void Push(const T& data);
    void Pop();
    T& Top();

private:
    T* dataArray;
    size_t size;
    size_t capacity;

    void Grow();
};

template<typename T>
Stack<T>::Stack()
{
    dataArray = new T[4];
    size = 0;
    capacity = 4;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] dataArray;
}

template<typename T>
size_t Stack<T>::Size()
{
    return size;
}

template<typename T>
void Stack<T>::Push(const T& data)
{
    if (size >= capacity)
    {
        Grow();
    }

    dataArray[size++] = data;
}

template<typename T>
void Stack<T>::Pop()
{
    if (0 == size)
        throw exception("Stack is empty");

    size--;
}

template<typename T>
T& Stack<T>::Top()
{
    if (0 == size)
        throw exception("Stack is empty");

    return dataArray[size - 1];
}

template<typename T>
void Stack<T>::Grow()
{
    T* newArray = new T[capacity + 4];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = dataArray[i];
    }

    delete[] dataArray;
    dataArray = newArray;
    capacity = capacity + 4;
}
