#pragma once
#include <vector>

using namespace std;

// <��������>
// ������ �� ���� ���� ������ �ϳ��� �����Ͽ� ����
// �ð����⵵ -  O(n��)
// �������⵵ -  O(1)
// ��������   -  O
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
