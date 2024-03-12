#pragma once
#include <vector>

using namespace std;

// <선택정렬>
// 데이터 중 가장 작은 값부터 하나씩 선택하여 정렬
// 시간복잡도 -  O(n²)
// 공간복잡도 -  O(1)
// 안정정렬   -  O
class SelectionSort
{
public:
    static void Sort(vector<int>& container)
    {
        for (int i = 0; i < container.size(); i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < container.size(); j++)
            {
                if (container[j] < container[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(container[i], container[minIndex]);
        }
    }

};
