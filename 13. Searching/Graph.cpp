#include <vector>

using namespace std;

/************************************************************************
 * 그래프 (Graph)
 *
 * 정점의 모음과 이 정점을 잇는 간선의 모음의 결합
 * 한 노드에서 출발하여 다시 자기 자신의 노드로 돌아오는 순환구조를 가짐
 * 간선의 방향성에 따라 단방향 그래프, 양방향 그래프가 있음
 * 간선의 가중치에 따라   연결 그래프, 가중치 그래프가 있음
 ************************************************************************/

// <인접행렬 그래프>
// 그래프 내의 각 정점의 인접 관계를 나타내는 행렬
// 2차원 배열을 [출발정점, 도착정점] 으로 표현
// 장점 : 인접여부 접근이 빠름
// 단점 : 메모리 사용량이 많음

// 예시 - 양방향 연결 그래프
vector<vector<bool>> matrixGraph1 =
{
    { false, false, false, false,  true },
    { false, false,  true, false, false },
    { false,  true, false,  true, false },
    { false, false,  true, false,  true },
    {  true, false, false,  true, false },
};

const int INF = 99999;

// 예시 - 단방향 가중치 그래프 (단절은 높은 값으로 표현)
vector<vector<int>> matrixGraph2 =
{
    {   0, 132, INF, INF,  16 },
    {  12,   0, INF, INF, INF },
    { INF,  38,   0, INF, INF },
    { INF,  12, INF,   0,  54 },
    { INF, INF, INF, INF,   0 },
};


// <인접리스트 그래프>
// 그래프 내의 각 정점의 인접 관계를 표현하는 리스트
// 인접한 간선만을 리스트에 추가하여 관리
// 장점 : 메모리 사용량이 적음
// 단점 : 인접여부를 확인하기 위해 리스트 탐색이 필요

// 예시
vector<int> listGraph1[5];              // 연결 그래프
vector<pair<int, int>> listGraph2[5];   // 가중치 그래프
void CreateGraph()
{
    listGraph1[0].push_back(1);
    listGraph1[1].push_back(0);
    listGraph1[1].push_back(3);
    listGraph1[2].push_back(0);
    listGraph1[2].push_back(1);
    listGraph1[2].push_back(4);
    listGraph1[3].push_back(1);
    listGraph1[4].push_back(3);
}