#pragma once
#include <vector>

using namespace std;

// <힙정렬>
// 힙을 이용하여 우선순위가 가장 높은 요소가 가장 마지막 요소와 교체된 후 제거되는 방법을 이용
// 배열에서 연속적인 데이터를 사용하지 않기 때문에 캐시 메모리를 효율적으로 사용할 수 없어 상대적으로 느림
// 시간복잡도 -  O(nlogn)
// 공간복잡도 -  O(1)
// 안정정렬   -  X
class HeapSort
{
public:
    static void Sort(vector<int>& container)
    {
        MakeHeap(container);

        for (int i = container.size() - 1; i > 0; i--)
        {
            swap(container[0], container[i]);
            Heapify(container, 0, i);
        }
    }

    static void MakeHeap(vector<int>& container)
    {
        for (int i = container.size() / 2 - 1; i >= 0; i--)
        {
            Heapify(container, i, container.size());
        }
    }

    static void Heapify(vector<int>& container, int index, int size)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int max = index;
        if (left < size && container[left] > container[max])
        {
            max = left;
        }
        if (right < size && container[right] > container[max])
        {
            max = right;
        }

        if (max != index)
        {
            swap(container[index], container[max]);
            Heapify(container, max, size);
        }
    }

};

