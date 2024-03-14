#pragma once
#include <vector>

using namespace std;

// <���� �켱 Ž�� (Depth-First Search)>
// �׷����� �б⸦ ������ �� �ִ��� ���� ������ ��,
// �б��� Ž���� ������ �� ���� �б⸦ Ž��
// ����(�Լ�ȣ�⽺��)�� ���� ����
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
