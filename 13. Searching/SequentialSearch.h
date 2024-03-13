#pragma once
#include <vector>

using namespace std;

// <순차 탐색>
// 자료구조에서 순차적으로 찾고자 하는 데이터를 탐색
// 시간복잡도 - O(n)
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

