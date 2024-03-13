#pragma once
#include <vector>
#include <queue>

using namespace std;

// <너비 우선 탐색 (Breadth-First Search)>
// 그래프의 분기를 만났을 때 모든 분기들을 탐색한 뒤,
// 다음 깊이의 분기들을 탐색
// 큐를 통해 탐색
class BreadthFirstSearch
{
public:
    static void Search(const vector<vector<bool>>& graph, int start, vector<bool>& visited, vector<int>& parents)
    {
        int size = graph[0].size();
        visited = vector<bool>(size);
        parents = vector<int>(size);

        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
            parents[i] = -1;
        }

        queue<int> container;
        container.push(start);
        visited[start] = true;

        while (container.size() > 0)
        {
            int next = container.front();
            container.pop();

            for (int i = 0; i < size; i++)
            {
                if (graph[next][i] &&
                    visited[i] == false)
                {
                    visited[i] = true;
                    parents[i] = next;
                    container.push(i);
                }
            }
        }
    }
};