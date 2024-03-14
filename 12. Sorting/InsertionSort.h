#pragma once
#include <vector>

using namespace std;

// <��������>
// �����͸� �ϳ��� ������ ���ĵ� �ڷ� �� ������ ��ġ�� �����Ͽ� ����
// �ð����⵵ -  O(n��)
// �������⵵ -  O(1)
// ��������   -  O
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

