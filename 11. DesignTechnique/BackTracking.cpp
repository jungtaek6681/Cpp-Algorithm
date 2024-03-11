#include <iostream>
#include <vector>

using namespace std;

/*********************************************************************
 * 백트래킹 (Backtracking)
 *
 * 모든 경우의 수를 전부 고려하는 알고리즘
 * 후보해를 검증 도중 해가 아닌경우 되돌아가서 다시 해를 찾아가는 기법
 **********************************************************************/

// 예시 - 순열
vector<int> container = vector<int>();
void Permutation(int n, int r, int count = 0)
{
    if (count == r)
    {
        for (int element : container)
        {
            cout << element << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        bool contain = false;
        for (int element : container)
        {
            if (element == i)
            {
                contain = true;
            }
        }
        if (contain)
            continue;

        container.push_back(i);
        Permutation(n, r, count + 1);
        container.pop_back();
    }
}
