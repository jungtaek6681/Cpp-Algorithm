#pragma once
#include <vector>

using namespace std;

template <typename T>
void Swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

template <typename T>
class PriorityQueue
{
public:
    void Push(const T& data);
    void Pop();
    T& Top();
    int Size();
    bool Empty();

private:
    vector<T> container;
};

template <typename T>
void PriorityQueue<T>::Push(const T& data)
{
    container.push_back(data);

    int curIndex = container.size() - 1;
    while (curIndex > 0)
    {
        int parentIndex = (curIndex - 1) / 2;
        if (container[curIndex] > container[parentIndex])
        {
            Swap(container[curIndex], container[parentIndex]);
            curIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void PriorityQueue<T>::Pop()
{
    Swap(container.front(), container.back());
    int curIndex = 0;
    while (curIndex < container.size() - 1)
    {
        int leftIndex = curIndex * 2 + 1;
        int rightIndex = curIndex * 2 + 2;
        int targetIndex = curIndex;

        if (leftIndex < container.size() - 1 &&
            container[leftIndex] > container[targetIndex])
        {
            targetIndex = leftIndex;
        }
        if (rightIndex < container.size() - 1 &&
            container[rightIndex] > container[targetIndex])
        {
            targetIndex = rightIndex;
        }

        if (targetIndex == curIndex)
            break;

        Swap(container[curIndex], container[targetIndex]);
        curIndex = targetIndex;
    }

    container.pop_back();
}

template <typename T>
T& PriorityQueue<T>::Top()
{
    return container.front();
}

template <typename T>
int PriorityQueue<T>::Size()
{
    return container.size();
}

template <typename T>
bool PriorityQueue<T>::Empty()
{
    return container.empty();
}