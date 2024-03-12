#pragma once
#include <vector>

using namespace std;

// <삽입정렬>
// 데이터를 하나씩 꺼내어 정렬된 자료 중 적합한 위치에 삽입하여 정렬
// 시간복잡도 -  O(n²)
// 공간복잡도 -  O(1)
// 안정정렬   -  O
class InsertionSort
{
public:
    static void Sort(vector<int>& container)
    {
        for (int i = 1; i < container.size(); i++)
        {
            int key = container[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (container[j] < key)
                    break;

                swap(container[j], container[j + 1]);
            }
        }
    }
};

