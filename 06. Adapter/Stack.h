#pragma once
#include <vector>

using namespace std;

template <typename T, typename Container = vector<T>>
class Stack
{
public:
    void Push(const T& data)
    {
        container.push_back();
    }

    void Pop()
    {
        container.pop_back();
    }

    void Top()
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