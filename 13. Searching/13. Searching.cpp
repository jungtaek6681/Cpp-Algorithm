#include <iostream>
#include <vector>
#include <queue>

#include "SequentialSearch.h"
#include "BinarySearch.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"

using namespace std;

int main()
{
    // 선형 자료구조 탐색
    int index;
    vector<int> container = { 1, 3, 5, 7, 9, 8, 6, 4, 2, 0 };
    cout << "데이터" << endl;
    for (int element : container)
    {
        cout << element << ", ";
    }
    cout << endl << endl;
    
    // 순차탐색
    index = SequentialSearch::Search(container, 2);
    cout << "순차탐색 결과 위치 : " << index << endl << endl;


    // 이진탐색
    index = BinarySearch::Search(container, 2);
    cout << "정렬 전 이진탐색 결과 : " << index << endl << endl;
    sort(container.begin(), container.end());
    index = BinarySearch::Search(container, 2);
    cout << "정렬 후 이진탐색 결과 : " << index << endl << endl;


    // 비선형 자료구조 탐색
    vector<vector<bool>> graph =
    {
        { false,  true, false, false, false, false, false, false },
        {  true, false,  true, false, false,  true, false, false },
        { false,  true, false, false,  true,  true, false, false },
        { false, false, false, false, false,  true, false, false },
        { false, false,  true, false, false, false,  true,  true },
        { false,  true,  true,  true, false, false, false, false },
        { false, false, false, false,  true, false, false, false },
        { false, false, false, false,  true, false, false, false },
    };

    // 깊이 우선 탐색
    vector<bool> dfsVisited;
    vector<int> dfsParents;
    cout << "깊이 우선 탐색" << endl;
    DepthFirstSearch::Search(graph, 0, dfsVisited, dfsParents);
    cout.width(8); cout << "Vertex";
    cout.width(8); cout << "Visit";
    cout.width(8); cout << "Parent" << endl;
    for (int i = 0; i < graph[0].size(); i++)
    {
        cout.width(8); cout << i;
        cout.width(8); cout << dfsVisited[i];
        cout.width(8); cout << dfsParents[i] << endl;
    }
    cout << endl;

    // 너비 우선 탐색
    vector<bool> bfsVisited;
    vector<int> bfsParents;
    cout << "너비 우선 탐색" << endl;
    BreadthFirstSearch::Search(graph, 0, bfsVisited, bfsParents);
    cout.width(8); cout << "Vertex";
    cout.width(8); cout << "Visit";
    cout.width(8); cout << "Parent" << endl;
    for (int i = 0; i < graph[0].size(); i++)
    {
        cout.width(8); cout << i;
        cout.width(8); cout << bfsVisited[i];
        cout.width(8); cout << bfsParents[i] << endl;
    }
}
