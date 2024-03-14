#pragma once
#include <vector>

using namespace std;

// <��������>
// �����͸� 2�����Ͽ� ���� �� ����
// ������ ������ŭ�� �߰����� �޸𸮰� �ʿ�
// �ð����⵵ -  O(nlogn)
// �������⵵ -  O(n)
// ��������   -  O
class MergeSort
{
public:
    static void Sort(vector<int>& container)
    {
        Sort(container, 0, container.size() - 1);
    }

    static void Sort(vector<int>& container, int start, int end)
    {
        if (start == end)
            return;

        int mid = (start + end) / 2;
        Sort(container, start, mid);
        Sort(container, mid + 1, end);
        Merge(container, start, mid, end);
    }

    static void Merge(vector<int>& container, int start, int mid, int end)
    {
        vector<int> sorted = vector<int>();
        int leftIndex = start;
        int rightIndex = mid + 1;

        while (leftIndex <= mid && rightIndex <= end)
        {
            if (container[leftIndex] < container[rightIndex])
            {
                sorted.push_back(container[leftIndex++]);
            }
            else
            {
                sorted.push_back(container[rightIndex++]);
            }
        }

        if (leftIndex > mid)
        {
            for (int i = rightIndex; i <= end; i++)
            {
                sorted.push_back(container[i]);
            }
        }
        else // if (rightIndex > end)
        {
            for (int i = leftIndex; i <= mid; i++)
            {
                sorted.push_back(container[i]);
            }
        }

        for (int i = 0; i < sorted.size(); i++)
        {
            container[start + i] = sorted[i];
        }
    }

};
