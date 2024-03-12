#pragma once
#include <vector>

using namespace std;

// <버블정렬>
// 서로 인접한 데이터를 비교하여 정렬
// 시간복잡도 -  O(n²)
// 공간복잡도 -  O(1)
// 안정정렬   -  O
class BubbleSort
{
public:
    static void Sort(vector<int>& container)
    {
        for (int i = 1; i < container.size(); i++)
        {
            for (int j = 0; j < container.size() - i; j++)
            {
                if (container[j] > container[j + 1])
                {
                    swap(container[j], container[j + 1]);
                }
            }
        }
    }
};

