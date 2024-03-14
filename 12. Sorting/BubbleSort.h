#pragma once
#include <vector>

using namespace std;

// <��������>
// ���� ������ �����͸� ���Ͽ� ����
// �ð����⵵ -  O(n��)
// �������⵵ -  O(1)
// ��������   -  O
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

