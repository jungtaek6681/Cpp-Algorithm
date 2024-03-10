#include <iostream>
#include <utility>
#include <list>
#include <queue>
#include <set>

using namespace std;

/*****************************************************************************
 * 함수객체 (Functor - Function Object)
 *
 * 클래스의 () 연산자를 재정의하여 함수처럼 동작하는 객체
 * 함수객체를 매개변수로 사용하여 상황에 따라 원하는 동작을 지정할 수 있음
 *****************************************************************************/

// <함수객체 구현>
// 클래스의 () 연산자를 재정의하여 기능을 구현
// 클래스 인스턴스를 생성하여 함수 호출처럼 사용
struct Functor
{
    void operator()(int data)
    {
        cout << "함수 객체 : " << data << endl;
    }
};

void Main1()
{
    Functor functor;

    functor(10);
    functor(20);
    functor(30);
}


// <함수객체 사용용도>
// 함수객체는 함수와 비교하여 두가지 장점을 제공할 수 있음
// 1. 함수객체는 다른 멤버변수를 가지고 상태를 이용하여 동작 가능
// 2. 함수객체는 매개변수로 전달하여 함수의 동작 기준을 지정 가능
struct Round
{
    int digit = 0;

    double operator()(double value)
    {
        value /= pow(10, digit);
        value = round(value);
        value *= pow(10, digit);
        return value;
    }
};

void Main2()
{
    Round round;
    cout << round(123.456) << endl;
    cout << round(456.789) << endl;

    round.digit = 2;
    cout << round(123.456) << endl;
    cout << round(456.789) << endl;

    round.digit = -1;
    cout << round(123.456) << endl;
    cout << round(456.789) << endl;
}


struct IsEven
{
    bool operator()(int value)
    {
        return (value % 2) == 0;
    }
};

struct IsOdd
{
    bool operator()(int value)
    {
        return (value % 2) == 1;
    }
};

template <typename Functor>
int CountIf(vector<int> vect, Functor functor)
{
    int count = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (functor(vect[i]))
        {
            count++;
        }
    }
    return count;
}

void Main3()
{
    vector<int> vect = { 1, 2, 4, 8, 9 };
    cout << "even count : " << CountIf(vect, IsEven()) << endl;
    cout << "odd count : " << CountIf(vect, IsOdd()) << endl;
}


// <함수객체와 자료구조>
// C++의 자료구조 중 함수객체를 포함하는 자료구조의 경우
// 함수객체를 변경하여 자료 보관의 기준을 선정가능
// 예를들어, C++의 자료구조 중 정렬기준이 있는 자료구조의 경우
// 정렬기준을 함수객체로 지정하여 저장하는 순서를 변경가능
void Main4()
{
    set<int, less<int>> lessSet = { 1, 3, 5, 7, 9, -8, -6, -4, -2 };
    set<int, greater<int>> greaterSet = { 1, 3, 5, 7, 9, -8, -6, -4, -2 };

    cout << "Set less" << endl;
    for (int element : lessSet)
    {
        cout << element << endl;
    }
    cout << endl;

    cout << "Set greater" << endl;
    for (int element : greaterSet)
    {
        cout << element << endl;
    }
    cout << endl;


    auto lessPQ = priority_queue<int, vector<int>, less<int>>();
    auto greaterPQ = priority_queue<int, vector<int>, greater<int>>();
    for (int i = 0; i < 10; i++)
    {
        lessPQ.push(i);
        greaterPQ.push(i);
    }

    cout << "Priority queue less" << endl;
    while (!lessPQ.empty())
    {
        cout << lessPQ.top() << endl;
        lessPQ.pop();
    }
    cout << endl;

    cout << "Priority queue greater" << endl;
    while (!greaterPQ.empty())
    {
        cout << greaterPQ.top() << endl;
        greaterPQ.pop();
    }
    cout << endl;
}


// <함수객체와 알고리즘>
// 함수객체를 매개변수로 함수객체를 지정하여
// 알고리즘 동작의 기준을 선정가능
// 예를 들어, 정렬알고리즘을 정렬기준만 변경하여
// 오름차순 정렬과 내림차순 정렬를 지정가능
void Main5()
{
    list<int> container = { 1, 3, 5, 7, 9, -8, -6, -4, -2 };

    cout << "Ascending sort" << endl;
    container.sort(less<int>());
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;

    cout << "Descending sort" << endl;
    container.sort(less<int>());
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;
}


// <람다식>
// 함수를 호출하거나 전달하는 위치에 동작을 지정해주기 위해 작성하는 함수객체
// 일반적으로 알고리즘 또는 비동기 함수에 몇 줄의 코드를 작성하는데 사용됨
void Main6()
{
    list<int> container = { 1, 3, 5, 7, 9, -8, -6, -4, -2 };

    cout << "Ascending sort" << endl;
    container.sort([](int left, int right) { return left < right; });
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;

    cout << "Descending sort" << endl;
    container.sort([](int left, int right) { return left > right; });
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;

    cout << "Ascending absolute sort" << endl;
    container.sort([](int left, int right) { return abs(left) < abs(right); });
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;

    cout << "Descending absolute sort" << endl;
    container.sort([](int left, int right) { return abs(left) > abs(right); });
    for (int element : container)
    {
        cout << element << endl;
    }
    cout << endl;
}


int main()
{
    
}