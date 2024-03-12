#pragma once
#include <vector>

using namespace std;

// <퀵정렬>
// 하나의 피벗을 기준으로 작은값과 큰값을 2분할하여 정렬
// 최악의 경우(피벗이 최소값 또는 최대값)인 경우 시간복잡도가 O(n²)
// 시간복잡도 -  평균 : O(nlogn)   최악 : O(n²)
// 공간복잡도 -  O(1)
// 안정정렬   -  X
class QuickSort
{
public:
    static void Sort(vector<int>& container)
    {
        Sort(container, 0, container.size() - 1);
    }

    static void Sort(vector<int>& container, int start, int end)
    {
        if (start >= end)
            return;

        int pivot = start;
        int left = pivot + 1;
        int right = end;

        while (left <= right)
        {
            while (container[left] <= container[pivot] && left < right)
            {
                left++;
            }
            while (container[right] > container[pivot] && left <= right)
            {
                right--;
            }

            if (left < right)
            {
                swap(container[left], container[right]);
            }
            else
            {
                swap(container[pivot], container[right]);
                break;
            }
        }

        Sort(container, start, right - 1);
        Sort(container, right + 1, end);
    }

};

