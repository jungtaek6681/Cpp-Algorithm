#pragma once
#include <vector>

using namespace std;

// <깊이 우선 탐색 (Depth-First Search)>
// 그래프의 분기를 만났을 때 최대한 깊이 내려간 뒤,
// 분기의 탐색을 마쳤을 때 다음 분기를 탐색
// 스택(함수호출스택)을 통해 구현
class DepthFirstSearch
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

        SearchNode(graph, start, visited, parents);
    }

private:
    static void SearchNode(const vector<vector<bool>>& graph, int vertex, vector<bool>& visited, vector<int>& parents)
    {
        int size = graph[0].size();
        visited[vertex] = true;
        for (int i = 0; i < size; i++)
        {
            if (graph[vertex][i] &&
                visited[i] == false)
            {
                parents[i] = vertex;
                SearchNode(graph, i, visited, parents);
            }
        }
    }
};
