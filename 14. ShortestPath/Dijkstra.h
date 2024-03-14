#pragma once
#include <vector>

using namespace std;

// <���ͽ�Ʈ�� �ִܰŸ� �˰��� (Dijkstra Algorithm)>
// Ư���� ��忡�� ����Ͽ� �ٸ� ���� ���� ������ �ִܰ�θ� ����
// �湮���� ���� ��� �߿��� �ִ� �Ÿ��� ���� ª�� ��带 ���� ��
// �ش� ��带 ���� �ٸ� ���� ���� ����� ���
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
            // 1. �湮���� ���� ���� �� ���� ����� ������ ����
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

            // 2. �ش� ��带 ���� �ٸ� ���� ���� ����� ���
            for (int j = 0; j < size; j++)
            {
                // distance[j] : ���������� ���� ����� �Ÿ�
                // distance[next] : Ž������ �������� �Ÿ�
                // graph[next, j] : Ž������ �������� �������� �Ÿ�
                if (distance[j] > distance[next] + graph[next][j])
                {
                    distance[j] = distance[next] + graph[next][j];
                    parents[j] = next;
                }
            }
        }
    }
};