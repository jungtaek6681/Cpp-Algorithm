#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

/******************************************************************
 * 어댑터 (Adapter)
 *
 * 한 클래스의 인터페이스를 사용하고자 하는 다른 인터페이스로 변환
 * 기존의 자료구조를 이용하여 기능을 구현한 컨테이너를 구성 가능
 ******************************************************************/

int main()
{
    stack<int, vector<int>> vectStack = stack<int, vector<int>>();
    for (int i = 0; i < 5; i++)
    {
        vectStack.push(i);
    }

    cout << "Stack adapter" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << vectStack.top() << endl;
        vectStack.pop();
    }
    cout << endl;

    queue<int, list<int>> listQueue = queue<int, list<int>>();
    for (int i = 0; i < 5; i++)
    {
        listQueue.push(i);
    }

    cout << "Queue adapter" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << listQueue.front() << endl;
        listQueue.pop();
    }
    cout << endl;
}