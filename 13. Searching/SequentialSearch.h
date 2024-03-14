#pragma once
#include <vector>

using namespace std;

// <���� Ž��>
// �ڷᱸ������ ���������� ã���� �ϴ� �����͸� Ž��
// �ð����⵵ - O(n)
class SequentialSearch
{
public:
    static int Search(const vector<int>& container, int value)
    {
        for (int i = 0; i < container.size(); i++)
        {
            if (container[i] == value)
                return i;
        }

        return -1;
    }
};

