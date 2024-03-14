#include <iostream>

using namespace std;

/*************************************************************************
 * �������� (Divide and Conquer)
 *
 * ū ������ ���� ������ ������ Ǫ�� ����� ���� ���
 * ������ ���ؼ� �ذ��ϱ� ���� ���� ������ ���� �� ������ �� �����ϴ� ����
 **************************************************************************/

// ���� - �ŵ� ����
int Pow(int x, int n)
{
    if (n == 1)
    {
        return x;
    }

    int halfPow = Pow(x, n / 2);
    if (n % 2 == 0)
    {
        return halfPow * halfPow;
    }
    else
    {
        return halfPow * halfPow * x;
    }
}