#include <iostream>

using namespace std;

/**********************************************************************************
 * 동적계획법 (Dynamic Programming)
 *
 * 작은문제의 해답을 큰문제의 해답의 부분으로 이용하는 상향식 접근 방식
 * 주어진 문제를 해결하기 위해 부분 문제에 대한 답을 계속적으로 활용해 나가는 기법
 ***********************************************************************************/

// 예시 - 피보나치 수열
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