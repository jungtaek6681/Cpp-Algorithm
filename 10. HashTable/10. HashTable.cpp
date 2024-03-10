﻿#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/***********************************************************************************
 * 해시테이블 (HashTable)
 *
 * 키 값을 해시함수로 해싱하여 해시테이블의 특정 위치로 직접 엑세스하도록 만든 방식
 * 해시 : 임의의 길이를 가진 데이터를 고정된 길이를 가진 데이터로 매핑
 ***********************************************************************************/

// <해시테이블 구현>
// 데이터를 담을 테이블을 이미 크게 확보해 놓은 후
// 입력받은 키를 해싱하여 테이블 고유한 index를 계산하고 데이터를 담아 보관
// 
//           해싱
//          ┌────┐
//     27 ─→│    │─→  27
//    385 ─→│해시│─→ 192
//    581 ─→│함수│─→   2
//   1031 ─→│    │─→  66
//          └────┘
//
//   [0]   [1]   [2]       [27]       [66]       [191] [192] [193]
// ┌─────┬─────┬─────┬─  ─┬────┬─  ─┬──────┬─  ─┬─────┬─────┬─────┐
// │     │     │ 582 │....│ 27 │....│ 1031 │....│     │ 385 │     │
// └─────┴─────┴─────┴─  ─┴────┴─  ─┴──────┴─  ─┴─────┴─────┴─────┘


// <해시함수>
// 키값을 해싱하여 고유한 index를 만드는 함수
// 조건 : 하나의 키값을 해싱하는 경우 반드시 항상 같은 index를 반환해야 함
// 효율 : 1. 해시함수 과정이 빠를수록 좋음
//        2. 해시함수의 결과 index의 분산이 클수록 좋음
//        3. 해시함수의 결과가 충돌이 적을수록 좋음
//
// 나눗셈법   : 데이터 % 테이블크기       예시 : 132031 → (132031 % 1000) = 31
// 자리수접기 : 데이터의 각 자리수의 합   예시 : "hash" → h(104) + a(97) + s(115) + h(104) = 420


// <해시테이블 주의점 - 충돌>
// 해시함수가 서로 다른 입력 값에 대해 동일한 해시테이블 주소를 반환하는 것
// 모든 입력 값에 대해 고유한 해시 값을 만드는 것은 불가능하며 충돌은 피할 수 없음
//
//           해싱
//          ┌────┐
//    274 ─→│해시│─→  81
//    660 ─→│함수│─→  81
//          └────┘
//
//   [0]   [1]   [2]         [81]         [191] [192] [193]
// ┌─────┬─────┬─────┬─  ─┬─────────┬─  ─┬─────┬─────┬─────┐
// │     │     │     │....│ 274 660 │....│     │     │     │
// └─────┴─────┴─────┴─  ─┴─────────┴─  ─┴─────┴─────┴─────┘


// <충돌해결방안 - 체이닝>
// 해시 충돌이 발생하면 연결리스트로 데이터들을 연결하는 방식
// 장점 : 해시테이블에 자료상승률에 따른 성능저하가 적음
// 단점 : 해시테이블 외 추가적인 저장공간이 필요, 삽입삭제시 오버헤드가 발생
//
//           해싱
//          ┌────┐
//    274 ─→│해시│─→  81
//    660 ─→│함수│─→  81
//          └────┘
//
//   [0]   [1]   [2]        [81]      [191] [192] [193]
// ┌─────┬─────┬─────┬─  ─┬─────┬─  ─┬─────┬─────┬─────┐
// │     │     │     │....│  │  │....│     │     │     │
// └─────┴─────┴─────┴─  ─┴──│──┴─  ─┴─────┴─────┴─────┘
//                           ↓
//                        ┌─────┬─┐ ┌─────┬─┐
//                        │ 274 │──→│ 660 │ │
//                        └─────┴─┘ └─────┴─┘


// <충돌해결방안 - 개방주소법>
// 해시 충돌이 발생하면 다른 빈 공간에 데이터를 삽입하는 방식
// 해시 충돌시 선형탐색, 제곱탐색, 이중해시 등을 통해 다른 빈 공간을 선정
// 장점 : 추가적인 저장공간이 필요하지 않음, 삽입삭제시 오버헤드가 적음
// 단점 : 해시테이블에 자료사용률이 임계치 이후 급격한 성능저하가 발생
//
// 개방주소법 해시테이블의 공간 사용률이 높을 경우(통계적으로 70% 이상) 급격한 성능저하가 발생
// 이런 경우 재해싱을 통해 공간 사용률을 낮추어 다시 효율을 확보함
// 재해싱 : 해시테이블의 크기를 늘리고 테이블 내의 모든 데이터를 다시 해싱하여 보관
//
//           해싱
//          ┌────┐
//    274 ─→│해시│─→  81
//    660 ─→│함수│─→  81
//          └────┘
//                          
//   [0]   [1]   [2]        [81]  [82]      [191] [192] [193]
// ┌─────┬─────┬─────┬─  ─┬─────┬─────┬─  ─┬─────┬─────┬─────┐
// │     │     │     │....│ 274 │     │....│     │     │     │
// └─────┴─────┴─────┴─  ─┴─────┴─────┴─  ─┴─────┴─────┴─────┘
//                          ↑660(충돌)
//
//   [0]   [1]   [2]        [81]  [82]      [191] [192] [193]
// ┌─────┬─────┬─────┬─  ─┬─────┬─────┬─  ─┬─────┬─────┬─────┐
// │     │     │     │....│ 274 │ 660 │....│     │     │     │
// └─────┴─────┴─────┴─  ─┴─────┴─────┴─  ─┴─────┴─────┴─────┘
//                                ↑(다음위치에 저장)


int main()
{
    // unordered_set : 해시테이블 기반의 중복이 없는 저장소
    unordered_set<int> valueContainer = unordered_set<int>();

    // 추가
    valueContainer.insert(5);
    valueContainer.insert(1);
    valueContainer.insert(2);
    valueContainer.insert(4);
    valueContainer.insert(3);
    valueContainer.insert(1);   // 중복 추가는 무시됨

    // 삭제
    valueContainer.erase(4);

    // 탐색
    valueContainer.find(3);

    // 순회
    cout << "Unordered Set iteration" << endl;
    for (const int& element : valueContainer)
    {
        cout << element << endl;    // output : 5, 1, 2, 3
    }
    cout << endl;


    // unordered_map : 해시테이블 기반의 중복이 없는 key - value 저장소
    unordered_map<int, string> keyValueContainer = unordered_map<int, string>();

    // 추가
    keyValueContainer.insert(make_pair(4, "Beryllium"));
    keyValueContainer.insert(make_pair(2, "Helium"));
    keyValueContainer.insert(make_pair(1, "Hydrogen"));
    keyValueContainer.insert(make_pair(8, "Oxygen"));
    keyValueContainer.insert(make_pair(3, "Lithium"));

    // 삭제
    keyValueContainer.erase(8);

    // 탐색
    keyValueContainer.find(3);

    // 순회
    cout << "Unordered Map iteration" << endl;
    for (pair<int, string> element : keyValueContainer)
    {
        cout << element.first << " : " << element.second << endl;
    }
    cout << endl;

    // unordered_map의 간소화된 사용법
    // unordered_map의 경우 [] 연산자에 key 값을 이용하여 추가, 확인이 가능
    unordered_map<string, string> container = unordered_map<string, string>();
    container["key1"] = "value1";
    container["key2"] = "value2";
    container["key3"] = "value3";

    cout << "key1 : " << container["key1"] << endl;
    cout << "key2 : " << container["key2"] << endl;
    cout << "key3 : " << container["key3"] << endl;
    cout << "key4 : " << container["key4"] << endl;     // 없었던 요소의 경우 기본값
}