#pragma once
#include <vector>

using namespace std;

// <������>
// �ϳ��� �ǹ��� �������� �������� ū���� 2�����Ͽ� ����
// �־��� ���(�ǹ��� �ּҰ� �Ǵ� �ִ밪)�� ��� �ð����⵵�� O(n��)
// �ð����⵵ -  ��� : O(nlogn)   �־� : O(n��)
// �������⵵ -  O(1)
// ��������   -  X
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

