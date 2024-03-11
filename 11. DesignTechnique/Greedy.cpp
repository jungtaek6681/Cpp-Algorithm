#include <iostream>

using namespace std;

/************************************************************
 * 탐욕 알고리즘 (Greedy Algorithm)
 *
 * 문제를 해결하는데 사용되는 근시안(짧은시야)적 방법
 * 문제를 직면한 당시에 당장 최적인 답을 선택하는 과정을 반복
 * 단, 반드시 최적의 해를 구해준다는 보장이 없음
 *************************************************************/

// 예시 - 자판기 거스름돈
void CoinMachine(int money)
{
    int coinType[] = {500, 100, 50, 10, 5, 1};

    for (int coin : coinType)
    {
        while (money >= coin)
        {
            cout << coin << " 코인 배출" << endl;
            money -= coin;
        }
    }
}