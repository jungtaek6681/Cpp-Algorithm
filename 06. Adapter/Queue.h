#pragma once
#include <list>

using namespace std;

template <typename T, typename Container = list<T>>
class Queue
{
public:
    void Push(const T& data)
    {
        container.push_back(data);
    }

    void Pop()
    {
        container.pop_front();
    }

    T& Front()
    {
        return container.front();
    }

    T& Back()
    {
        return container.back();
    }

    int Size()
    {
        return container.size();
    }

    bool Empty()
    {
        return 0 == container.size();
    }

private:
    Container container;
};