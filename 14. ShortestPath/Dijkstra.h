#pragma once
#include <vector>

using namespace std;

// <다익스트라 최단거리 알고리즘 (Dijkstra Algorithm)>
// 특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단경로를 구함
// 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택 후
// 해당 노드를 거쳐 다른 노드로 가는 비용을 계산
class Dijkstra
{
public:
    static void ShortestPath(const vector<vector<int>>& graph, int start, vector<bool>& visited, vector<int>& parents, vector<int>& distance)
    {
        const int INF = 9999;

        int size = graph[0].size();
        visited = vector<bool>(size);
        parents = vector<int>(size);
        distance = vector<int>(size);

        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
            parents[i] = -1;
            distance[i] = INF;
        }
        distance[start] = 0;

        for (int i = 0; i < size; i++)
        {
            // 1. 방문하지 않은 정점 중 가장 가까운 정점을 선택
            int next = -1;
            int minCost = INF;
            for (int j = 0; j < size; j++)
            {
                if (distance[j] < minCost &&
                    visited[j] == false)
                {
                    next = j;
                    minCost = distance[j];
                }
            }
            if (next == -1)
                break;
            visited[next] = true;

            // 2. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산
            for (int j = 0; j < size; j++)
            {
                // distance[j] : 목적지까지 직접 연결된 거리
                // distance[next] : 탐색중인 정점까지 거리
                // graph[next, j] : 탐색중인 정점부터 목적지의 거리
                if (distance[j] > distance[next] + graph[next][j])
                {
                    distance[j] = distance[next] + graph[next][j];
                    parents[j] = next;
                }
            }
        }
    }
};