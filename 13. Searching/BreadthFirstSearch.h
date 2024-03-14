#pragma once
#include <vector>
#include <queue>

using namespace std;

// <�ʺ� �켱 Ž�� (Breadth-First Search)>
// �׷����� �б⸦ ������ �� ��� �б���� Ž���� ��,
// ���� ������ �б���� Ž��
// ť�� ���� Ž��
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