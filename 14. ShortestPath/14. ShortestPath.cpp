#include <iostream>
#include <vector>

#include "Dijkstra.h"

using namespace std;

int main()
{
    const int INF = 9999;

    vector<vector<int>> graph =
    {
        {   0, INF,   1,   7, INF, INF, INF,   5, INF},
        { INF,   0, INF, INF, INF,   4, INF, INF, INF},
        { INF, INF,   0, INF, INF, INF, INF, INF, INF},
        {   5, INF, INF,   0, INF, INF, INF, INF, INF},
        { INF, INF,   9, INF,   0, INF, INF, INF,   2},
        {   1, INF, INF, INF, INF,   0, INF,   6, INF},
        { INF, INF, INF, INF, INF, INF,   0, INF, INF},
        {   1, INF, INF, INF,   4, INF, INF,   0, INF},
        { INF,   5, INF,   2, INF, INF, INF, INF,   0}
    };

    vector<bool> visited;
    vector<int> parents;
    vector<int> distance;
    Dijkstra::ShortestPath(graph, 0, visited, parents, distance);

    cout.width(12); cout << "Vertex";
    cout.width(12); cout << "Visit";
    cout.width(12); cout << "Parent";
    cout.width(12); cout << "Distance" << endl;

    for (int i = 0; i < graph[0].size(); i++)
    {
        cout.width(12); cout << i;
        cout.width(12); cout << visited[i];
        cout.width(12); cout << parents[i];

        if (distance[i] >= INF)
        {
            cout.width(12); cout << "INF" << endl;
        }
        else
        {
            cout.width(12); cout << distance[i] << endl;
        }
    }
}
