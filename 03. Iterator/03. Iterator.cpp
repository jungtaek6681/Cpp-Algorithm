#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

/*************************************************************************************
 * 반복기 (Iterator)
 *
 * 자료구조에 저장되어 있는 요소들을 반복하고 개별 요소에 대해 접근을 제공하는 객체
 * 반복기의 시작 범위는 첫번째 요소부터 마지막 요소의 다음 요소(빈공간)으로 정의
 * C++의 모든 자료구조는 반복기를 제공
 * C++의 알고리즘들은 반복기를 통해 구현하기 때문에 자료구조 종류와 무관하게 동작가능
 *************************************************************************************/

// <반복기>
// 자료구조에 저장되어 있는 요소들을 반복하고 개별 요소에 대해 접근을 제공하는 객체
//
//      반복기                     반복기                     반복기
//      ↓                          ↓                          ↓          
// ┌─┬─┬─┬─┬─┬─┬─┬─┐ ←이전─ ┌─┬─┬─┬─┬─┬─┬─┬─┐ ←이전─ ┌─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│        │1│2│3│4│5│6│7│8│        │1│2│3│4│5│6│7│8│
// └─┴─┴─┴─┴─┴─┴─┴─┘ ─다음→ └─┴─┴─┴─┴─┴─┴─┴─┘ ─다음→ └─┴─┴─┴─┴─┴─┴─┴─┘


// <반복기 범위>
// 반복기의 시작 범위는 첫번째 요소부터 마지막 요소의 다음 요소(빈공간)으로 정의
//
//  begin()             end()
//  ↓                   ↓              
// ┌─┬─┐  ┌─┬─┐  ┌─┬─┐
// │1│───→│2│───→│3│ │  X
// └─┴─┘  └─┴─┘  └─┴─┘


// <자료구조와 반복기>
// C++의 모든 자료구조는 반복기를 제공함
// 
// 순차리스트 반복기 : index를 하나씩 증가시키며 반복
//  반복기                       반복기                       반복기
//  ↓                            ↓                            ↓          
// ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│ │ │ │ │ │ │ -다음→ │1│2│3│ │ │ │ │ │ │ -다음→ │1│2│3│ │ │ │ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┴─┘
//
// 연결리스트 반복기 : next Node를 이동하며 반복
//  반복기                            반복기                            반복기
//  ↓                                 ↓                                 ↓          
// ┌─┬─┐  ┌─┬─┐  ┌─┬─┐        ┌─┬─┐  ┌─┬─┐  ┌─┬─┐        ┌─┬─┐  ┌─┬─┐  ┌─┬─┐
// │1│───→│2│───→│3│ │ -다음→ │1│───→│2│───→│3│ │ -다음→ │1│───→│2│───→│3│ │
// └─┴─┘  └─┴─┘  └─┴─┘        └─┴─┘  └─┴─┘  └─┴─┘        └─┴─┘  └─┴─┘  └─┴─┘


// <반복기 사용방법>
// 반복기 객체를 자료구조에서 생성하여 자료구조의 데이터들을 확인가능
void Main1()
{
    vector<int> container = vector<int>();
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    // 반복기 객체 생성
    vector<int>::iterator iter = container.begin();

    // 반복기 객체가 현재 가리키는 데이터 확인
    int value = *iter;

    // 반복기 객체가 다음 데이터를 가리키도록 이동
    iter++;

    // 반복기 객체가 이전 데이터를 가리키도록 이동
    iter--;

    // 반복기 객체가 같은 데이터를 가리키는지 비교
    vector<int>::iterator other = container.begin();
    bool compare = iter == other;

    // 반복기 객체가 마지막 요소 다음에 나오는 위치(end)를 가리키는 경우
    // 더이상 데이터가 없음을 의미
    for (auto iter = container.begin(); iter != container.end(); iter++)
    {
        cout << *iter << ", ";
    }
}


// <반복기 사용용도>
// 반복기를 사용하는 경우 자료구조종류와 내부구조에 무관하게 알고리즘을 적용가능
// 
//  알고리즘          반복기          자료구조
// ┌────────┐                        ┌────────┐
// │  정렬  │ ──┐                ┌─→ │ 리스트 │
// └────────┘   │                │   └────────┘
// ┌────────┐   │   ┌────────┐   │   ┌────────┐
// │  반전  │ ──┼─→ │ 반복기 │ ──┼─→ │  트리  │
// └────────┘   │   └────────┘   │   └────────┘
//    ....      │                │      ....
// ┌────────┐   │                │   ┌────────┐
// │  탐색  │ ──┘                └─→ │ 테이블 │
// └────────┘                        └────────┘

template <typename Iterator, typename Type>
bool Exist(Iterator begin, Iterator end, const Type& value)
{
    for (Iterator iter = begin; iter != end; iter++)
    {
        if (value == *iter)
            return true;
    }
    return false;
}

void Main2()
{
    vector<int> vectContainer = vector<int>();
    list<int> listContainer = list<int>();
    for (int i = 0; i < 10; i++)
    {
        vectContainer.push_back(i);
        listContainer.push_back(i);
    }

    // 반복기를 이용한 함수의 경우 자료구조 종류와 무관하게 동작가능
    bool vectExist = Exist(vectContainer.begin(), vectContainer.end(), 5);
    bool listExist = Exist(listContainer.begin(), listContainer.end(), 5);

    // 표준 템플릿 라이브러리 algorithm의 함수 또한 반복기를 이용하여 동작가능
    reverse(vectContainer.begin(), vectContainer.end());
    reverse(listContainer.begin(), listContainer.end());
}


// <반복기를 이용한 순회>
// C++의 모든 자료구조를 반복기를 가지고 있으며 반복기를 이용하여 순회를 진행가능
// 범위 기반 반복문을 구성하는 경우 코드를 간결하게 작성할 수 있음
void Main3()
{
    vector<int> container = vector<int>();
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    // 반복기를 이용한 순회
    cout << "For loop with Iterator" << endl;
    for (vector<int>::iterator iter = container.begin(); iter != container.end(); iter++)
    {
        cout << *iter << ", ";
    }
    cout << endl;

    // 범위 기반 반복문 : 반복기를 이용한 순회의 간편한 표현
    cout << "Range-based for Statement" << endl;
    for (int& element : container)
    {
        cout << element << ", ";
    }
    cout << endl;
}


// <반복기 종류>
// 자료구조는 용도에 따라 다양한 반복기를 제공
// 보통의 경우 정방향 & 역방향 여부와 입출력 여부를 조합
void Main4()
{
    vector<int> container = { 1, 2, 3, 4, 5 };

    // 반복기 종류
    vector<int>::iterator iter = container.begin();                     // 정방향 + 입출력 반복기
    vector<int>::reverse_iterator riter = container.rbegin();           // 역방향 + 입출력 반복기
    vector<int>::const_iterator citer = container.cbegin();             // 정방향 + 출력 반복기
    vector<int>::const_reverse_iterator criter = container.crbegin();   // 정방향 + 출력 반복기

    // 방향에 따른 범위 반복
    cout << "iterator" << endl;
    for (iter = container.begin(); iter != container.end(); iter++)
    {
        cout << *iter << ", ";      // 출력 : 1, 2, 3, 4, 5,
    }
    cout << endl;

    cout << "reverse iterator" << endl;
    for (riter = container.rbegin(); riter != container.rend(); riter++)
    {
        cout << *riter << ", ";     // 출력 : 5, 4, 3, 2, 1,
    }
    cout << endl;

    // 입출력에 따른 기능
    iter = container.begin();
    citer = container.cbegin();

    int value1 = *iter;
    int value2 = *citer;

    *iter = 1;
    // *citer = 2;     // error : 출력 반복기는 입력이 기능이 없음
}


// <반복기 범주>
// 자료구조의 종류에 따라 반복기의 기능의 제공 범위가 달라짐
// ┌─────────────────┬───────────────────────────────────────────────────────────────────────────┐
// │                 │           Random access                                                   │
// │                 ├────────────────────────────────────────────┐                              │
// │                 │           Bidirectional                    │                              │
// │       All       ├─────────────────────────────────────┐      │                              │
// │                 │           Forward                   │      │                              │
// │                 ├─────────────────┬────────┐          │      │                              │
// │                 │      Input      │ Output │          │      │                              │
// ├──────────┬──────┼────────┬────────┼────────┼──────────┼──────┼──────────┬──────────┬────────┤
// │ 복사생성 │ 증가 │  비교  │ 역참조 │  참조  │ 기본생성 │ 감소 │ 산술연산 │ 위치비교 │ 인덱스 │
// │          │      │        │        │        │          │      │          │          │        │
// │  X b(a); │ ++a  │ a == b │ t = *a │ *a = t │   X a;   │ --a  │  a + n   │  a < b   │  a[n]  │
// │  b = a;  │ a++  │ a != b │  a->m  │        │   X();   │ a--  │  a - n   │  a > b   │        │
// │          │      │        │        │        │          │      │  a += n  │  a <= b  │        │
// │          │      │        │        │        │          │      │  a -= n  │  a >= b  │        │
// └──────────┴──────┴────────┴────────┴────────┴──────────┴──────┴──────────┴──────────┴────────┘
void Main5()
{
    // 반복기 범주와 기능
    vector<int> vectContainer = { 0, 1, 2, 3, 4 };
    list<int> listContainer = { 0, 1, 2, 3, 4 };
    forward_list<int> flistContainer = { 0, 1, 2, 3, 4 };

    // vector iterator : Random access iterator
    vector<int>::iterator vectIter = vectContainer.begin();
    // list iterator : Bidirectional iterator
    list<int>::iterator listIter = listContainer.begin();
    // forward list iterator : Forward directional iterator
    forward_list<int>::iterator flistIter = flistContainer.begin();


    int value1 = vectIter[0];       // 백터의 반복기는 임의접근 반복기로 index 접근 기능이 있음
    // int value2 = listIter[0];    // 양방향 리스트의 반복기는 양방향 반복기로 index 접근 기능이 없음
    // int value3 = flistIter[0];   // 단방향 리스트의 반복기는 단방향 반복기로 index 접근 기능이 없음

    vectIter--;                     // 백터의 반복기는 임의접근 반복기로 -- 연산 기능이 있음
    listIter--;                     // 양방향 리스트의 반복기는 양방향 반복기로 -- 연산 기능이 있음
    // flistIter--;                 // 단방향 리스트의 반복기는 단방향 반복기로 -- 연산 기능이 없음

    vectIter++;                     // 백터의 반복기는 임의접근 반복기로 ++ 연산 기능이 있음
    listIter++;                     // 양방향 리스트의 반복기는 양방향 반복기로 ++ 연산 기능이 있음
    flistIter++;                    // 단방향 리스트의 반복기는 단방향 반복기로 ++ 연산 기능이 있음


    // 반복기 요구 범주에 따른 적용 가능 알고리즘

    // 임의접근 반복기를 요구하는 알고리즘 sort<RanIt>
    sort(vectContainer.begin(), vectContainer.end());           // 정상 동작 : 임의접근 반복기
    // sort(listContainer.begin(), listContainer.end());        // 오류 발생 : 양방향 반복기
    // sort(flistContainer.begin(), flistContainer.end());      // 오류 발생 : 단방향 반복기

    // 양방향 반복기를 요구하는 알고리즘 reverse<BidIt>
    reverse(vectContainer.begin(), vectContainer.end());        // 정상 동작 : 임의접근 반복기
    reverse(listContainer.begin(), listContainer.end());        // 정상 동작 : 양방향 반복기
    // reverse(flistContainer.begin(), flistContainer.end());   // 오류 발생 : 단방향 반복기
    
    // 단방향 반복기를 요구하는 알고리즘 fill<FwdIt>
    fill(vectContainer.begin(), vectContainer.end(), 0);        // 정상 동작 : 임의접근 반복기
    fill(listContainer.begin(), listContainer.end(), 0);        // 정상 동작 : 양방향 반복기
    fill(flistContainer.begin(), flistContainer.end(), 0);      // 정상 동작 : 단방향 반복기
}

int main()
{
    
}
