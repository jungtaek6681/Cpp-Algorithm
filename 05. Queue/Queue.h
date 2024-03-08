#pragma once

using namespace std;

template <typename T>
class Queue
{
public:
    Queue();
    virtual ~Queue();

    size_t Size();

    void Push(const T& data);
    void Pop();
    T& Front();
    T& Back();

private:
    T* dataArray;
    int head;
    int tail;
    size_t capacity;

    bool IsFull();
    bool IsEmpty();
    void Grow();
};

template<typename T>
Queue<T>::Queue()
{
    dataArray = new T[4];
    head = 0;
    tail = 0;
    capacity = 4;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] dataArray;
}

template<typename T>
size_t Queue<T>::Size()
{
    if (head <= tail)
    {
        return tail - head;
    }
    else
    {
        return tail + (capacity - head);
    }
}

template<typename T>
void Queue<T>::Push(const T& data)
{
    if (IsFull())
    {
        Grow();
    }

    dataArray[tail] = data;
    tail = (tail + 1) % capacity;
}

template<typename T>
void Queue<T>::Pop()
{
    if (0 == Size())
        throw exception("Queue is empty");

    head = (head + 1) % capacity;
}

template<typename T>
T& Queue<T>::Front()
{
    if (0 == Size())
        throw exception("Queue is empty");

    return dataArray[head];
}

template<typename T>
T& Queue<T>::Back()
{
    if (0 == Size())
        throw exception("Queue is empty");

    return dataArray[tail != 0 ? tail - 1 : capacity - 1];
}

template<typename T>
bool Queue<T>::IsFull()
{
    if (head > tail)
    {
        return head == tail + 1;
    }
    else
    {
        return head == 0 && tail == capacity - 1;
    }
}

template<typename T>
bool Queue<T>::IsEmpty()
{
    return head == tail;
}

template<typename T>
void Queue<T>::Grow()
{
    T* newArray = new T[capacity + 4];

    if (head < tail)
    {
        int srcIndex = head;
        int dstIndex = 0;
        while (srcIndex < tail)
        {
            newArray[dstIndex++] = dataArray[srcIndex++];
        }
        head = 0;
        tail = dstIndex;
    }
    else
    {
        int srcIndex = head;
        int dstIndex = 0;
        while (srcIndex < capacity)
        {
            newArray[dstIndex++] = dataArray[srcIndex++];
        }

        srcIndex = 0;
        while (srcIndex < tail)
        {
            newArray[dstIndex++] = dataArray[srcIndex++];
        }
        head = 0;
        tail = dstIndex;
    }

    delete[] dataArray;
    dataArray = newArray;
    capacity = capacity + 4;
}
