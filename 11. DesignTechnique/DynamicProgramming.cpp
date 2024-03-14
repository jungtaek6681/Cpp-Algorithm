#include <iostream>

using namespace std;

/**********************************************************************************
 * ������ȹ�� (Dynamic Programming)
 *
 * ���������� �ش��� ū������ �ش��� �κ����� �̿��ϴ� ����� ���� ���
 * �־��� ������ �ذ��ϱ� ���� �κ� ������ ���� ���� ��������� Ȱ���� ������ ���
 ***********************************************************************************/

// ���� - �Ǻ���ġ ����
int Fibonachi(int x)
{
    int* fibonachi = new int[x + 2];
    fibonachi[1] = 1;
    fibonachi[2] = 1;

    for (int i = 3; i <= x; i++)
    {
        fibonachi[i] = fibonachi[i - 1] + fibonachi[i - 2];
    }

    int result = fibonachi[x];
    delete[] fibonachi;
    return result;
}