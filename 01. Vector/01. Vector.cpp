﻿#include <iostream>
#include <vector>

using namespace std;

/*******************************************************
 * 순차리스트 (Sequential List)
 *
 * 런타임 중 크기를 확장할 수 있는 배열기반의 자료구조
 * 배열요소의 갯수를 특정할 수 없는 경우 사용이 용이
 *******************************************************/

// <순차리스트 구현>
// 순차리스트는 배열기반의 자료구조이며, 배열은 동작 중 크기변경이 불가하므로
// 순차리스트는 동작 중 크기를 확장하기 위해 포함한 데이터 갯수보다 더욱 큰 배열을 사용
//
// 크기 = 3, 용량 = 8       크기 = 4, 용량 = 8       크기 = 5, 용량 = 8
// ┌─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│ │ │ │ │ │        │1│2│3│4│ │ │ │ │        │1│2│3│4│5│ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┘


// <순차리스트 추가>
// 데이터를 추가하는 경우 크기가 증가하고 가장 마지막 위치에 새로운 데이터를 추가
// 
// 크기 = 4, 용량 = 8       크기 = 5, 용량 = 8
// ┌─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│ │ │ │ │   =>   │1│2│3│4│A│ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┘
//        ↑                          ↑


// <순차리스트 삭제>
// 데이터를 삭제하는 경우 크기가 감소하고 가장 마지막 위치에 새로운 데이터를 삭제
//
// 크기 = 5, 용량 = 8       크기 = 4, 용량 = 8
// ┌─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┐ 
// │1│2│3│4│A│ │ │ │   =>   │1│2│3│4│ │ │ │ │ 
// └─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┘ 
//          ↑                      ↑


// <순차리스트 용량>
// 용량을 가득 채운 상황에서 데이터를 추가하는 경우
// 더 큰 용량의 배열을 새로 생성한 뒤 데이터를 복사하여 새로운 배열을 사용
//
// 1. 순차리스트가 가득찬 상황에서 새로운 데이터 추가 시도
// 크기 = 8, 용량 = 8
// ┌─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│ ← A 추가
// └─┴─┴─┴─┴─┴─┴─┴─┘
//
// 2. 새로운 더 큰 배열 생성
// 크기 = 8, 용량 = 8          크기 = 0, 용량 = 16
// ┌─┬─┬─┬─┬─┬─┬─┬─┐           ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│ ← A 추가  │ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┘           └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
//
// 3. 새로운 배열에 기존의 데이터 복사
// 크기 = 8, 용량 = 8          크기 = 8, 용량 = 16
// ┌─┬─┬─┬─┬─┬─┬─┬─┐           ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│ ← A 추가  │1│2│3│4│5│6│7│8│ │ │ │ │ │ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┘           └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
//
// 4. 기본 배열 대신 새로운 배열을 사용
// 크기 = 8, 용량 = 16
// ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│ │ │ │ │ │ │ │ │ ← A 추가
// └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
//
// 5. 빈공간에 데이터 추가
// 크기 = 9, 용량 = 16
// ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│A│ │ │ │ │ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘

int main()
{
    // 순차리스트 생성
    vector<string> container = vector<string>(3);
    container[0] = "기본 데이터 0";
    container[1] = "기본 데이터 1";
    container[2] = "기본 데이터 2";


    // 추가
    container.push_back("추가 데이터 0");
    container.push_back("추가 데이터 1");
    container.push_back("추가 데이터 2");


    // 삭제
    container.pop_back();


    // 순회
    for (int i = 0; i < container.size(); i++)
    {
        cout << container[i] << endl;
    }
}