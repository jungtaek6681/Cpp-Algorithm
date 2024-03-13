#include <iostream>
#include <vector>
#include <list>

#include "AStar.h"

using namespace std;

void PrintResult(vector<vector<bool>> map, list<Point> path)
{
    int ySize = map.size();
    int xSize = map[0].size();

    vector<vector<char>> pathMap = vector<vector<char>>(map.size());
    for (int y = 0; y < ySize; y++)
    {
        pathMap[y] = vector<char>(xSize);
        for (int x = 0; x < xSize; x++)
        {
            if (map[y][x] == 0)
            {
                pathMap[y][x] = '#';
            }
            else
            {
                pathMap[y][x] = ' ';
            }
        }
    }

    for (Point point : path)
    {
        pathMap[point.y][point.x] = '*';
    }
    Point start = path.front();
    Point end = path.back();
    pathMap[start.y][start.x] = 'S';
    pathMap[end.y][end.x] = 'E';

    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            cout << pathMap[y][x];
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<bool>> map =
    {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };

    list<Point> path = AStar::PathFinding(map, Point(1, 1), Point(7, 7));
    if (path.empty() == false)
    {
        PrintResult(map, path);
    }
    else
    {
        cout << "경로를 찾을 수 없습니다." << endl;
    }
}
