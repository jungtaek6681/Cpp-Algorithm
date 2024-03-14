#pragma once
#include <vector>

using namespace std;

// <������>
// ���� �̿��Ͽ� �켱������ ���� ���� ��Ұ� ���� ������ ��ҿ� ��ü�� �� ���ŵǴ� ����� �̿�
// �迭���� �������� �����͸� ������� �ʱ� ������ ĳ�� �޸𸮸� ȿ�������� ����� �� ���� ��������� ����
// �ð����⵵ -  O(nlogn)
// �������⵵ -  O(1)
// ��������   -  X
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

