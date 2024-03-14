#pragma once
#include <vector>

using namespace std;

// <���� Ž��>
// ������ �Ǿ��ִ� �ڷᱸ������ 2������ ���� �����͸� Ž��
// ��, ���� Ž���� ������ �Ǿ� �ִ� �ڷῡ�� ���� ����
// �ð����⵵ - O(logn)
class BinarySearch
{
public:
    static int Search(const vector<int>& container, int value)
    {
        int low = 0;
        int high = container.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (value < container[mid])
            {
                high = mid - 1;
            }
            else if (value > container[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};

