#include <iostream>
#include <vector>

using namespace std;

/*********************************************************************
 * ��Ʈ��ŷ (Backtracking)
 *
 * ��� ����� ���� ���� ����ϴ� �˰���
 * �ĺ��ظ� ���� ���� �ذ� �ƴѰ�� �ǵ��ư��� �ٽ� �ظ� ã�ư��� ���
 **********************************************************************/

// ���� - ����
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
