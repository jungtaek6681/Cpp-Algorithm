#pragma once
#include <vector>

using namespace std;

// <이진 탐색>
// 정렬이 되어있는 자료구조에서 2분할을 통해 데이터를 탐색
// 단, 이진 탐색은 정렬이 되어 있는 자료에만 적용 가능
// 시간복잡도 - O(logn)
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

