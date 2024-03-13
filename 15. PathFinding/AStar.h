#pragma once
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <algorithm>

#include "Point.h"

using namespace std;

// <A* 알고리즘>
// 다익스트라 알고리즘을 확장하여 만든 최단경로 탐색알고리즘
// 경로 탐색의 우선순위를 두고 유망한 해부터 우선적으로 탐색
class AStar
{
public:
    static list<Point> PathFinding(vector<vector<bool>> tilemap, Point start, Point end)
    {
        int ySize = tilemap.size();
        int xSize = tilemap[0].size();

        Point direction[] =
        {
            Point( 0, +1),  // 상
            Point( 0, -1),  // 하
            Point(-1,  0),  // 좌
            Point(+1,  0),  // 우
            Point(-1, +1),  // 좌상
            Point(-1, -1),  // 좌하
            Point(+1, +1),  // 우상
            Point(+1, -1),  // 우하
        };
        
        priority_queue<ASNode, vector<ASNode>, ASNodeCompare> pq;
        vector<vector<ASNode>> map = vector<vector<ASNode>>(ySize);
        for (int i = 0; i < ySize; i++)
        {
            map[i] = vector<ASNode>(xSize);
        }


        // 0. 시작 정점을 생성
        ASNode startNode = ASNode(start, Point(), 0, Heuristic(start, end));
        pq.push(startNode);

        while (pq.size() > 0)
        {
            // 1. 다음으로 탐색할 정점을 탐색
            ASNode nextNode = pq.top();
            pq.pop();
            if (map[nextNode.point.y][nextNode.point.x].checked == true)
                continue;

            map[nextNode.point.y][nextNode.point.x].checked = true;

            // 2. 다음으로 탐색하는 정점이 도착지인 경우
            if (nextNode.point == end)
            {
                list<Point> path = list<Point>();

                Point curPoint = end;
                while (curPoint != start)
                {
                    path.push_front(curPoint);
                    curPoint = map[curPoint.y][curPoint.x].parent;
                }
                path.push_front(start);

                return path;
            }

            // 3. 인접한 정점들의 점수를 계산
            for (Point dir : direction)
            {
                int x = nextNode.point.x + dir.x;
                int y = nextNode.point.y + dir.y;

                // 3-0. 탐색하면 안되는 경우 제외
                // 맵을 벗어나는 경우
                if (x < 0 || x >= xSize || y < 0 || y >= ySize)
                    continue;
                // 벽일 경우
                if (tilemap[y][x] == false)
                    continue;
                // 이미 탐색한 정점인 경우
                if (map[y][x].checked == true)
                    continue;
                
                // 3-1. 탐색하는 정점의 만들기
                int g = nextNode.g + (nextNode.point.x == x || nextNode.point.y == y) ? COST_STRAIGHT : COST_DIAGONAL;
                int h = Heuristic(Point(x, y), end);
                ASNode newNode = ASNode(Point(x, y), nextNode.point, g, h);

                // 3-2. 계산한 점수와 이전 점수를 비교하여 더 작은 경우 갱신
                ASNodeCompare comparer;
                if (comparer(newNode, map[y][x]))
                {
                    map[y][x] = newNode;
                    pq.push(newNode);
                }
            }
        }

        // 경로가 없는 경우 빈 리스트를 반환
        return list<Point>();
    }

private:
    static const int INF = 9999;
    static const int COST_STRAIGHT = 10;    // 직선 이동 가중치
    static const int COST_DIAGONAL = 14;    // 대각선 이동 가중치

    // 휴리스틱 : 예상 남은 거리
    static int Heuristic(Point start, Point end)
    {
        int xSize = abs(start.x - end.x);   // 가로로 가야하는 횟수
        int ySize = abs(start.y - end.y);   // 세로로 가야하는 횟수

        // 맨허튼 거리 : 직선을 통해 이동하는 거리
        // return CostStraight * (xSize + ySize);

        // 유클리드 거리 : 대각선을 통해 이동하는 거리
        // return CostStraight * sqrt(xSize * xSize + ySize * ySize);

        // 타일맵 거리 : 직선과 대각선을 통해 이동하는 거리
        int straightCount = abs(xSize - ySize);
        int diagonalCount = max(xSize, ySize) - straightCount;
        return COST_STRAIGHT * straightCount + COST_DIAGONAL * diagonalCount;
    }

    // 정점에 대한 정보
    struct ASNode
    {
        bool checked;       // 탐색 여부

        Point point;        // 현재 정점의 좌표
        Point parent;       // 이 정점을 탐색한 좌표

        int f;              // 최종 최단 거리 : f = g + h
        int g;              // 현재 이동 거리
        int h;              // 예상 남은 거리

        ASNode()
        {
            this->checked = false;
            this->point = Point();
            this->parent = Point();
            this->g = INF;
            this->h = INF;
            this->f = INF;
        }

        ASNode(Point point, Point parent, int g, int h)
        {
            this->checked = false;
            this->point = point;
            this->parent = parent;
            this->g = g;
            this->h = h;
            this->f = g + h;
        }

        bool operator==(const ASNode& other)
        {
            return this->point == other.point;
        }

        bool operator!=(const ASNode& other)
        {
            return !(*this == other);
        }
    };

    // 정점 중 다음으로 탐색할 정점을 선정하기 위한 기준 함수객체
    struct ASNodeCompare
    {
        bool operator()(const ASNode& left, const ASNode& right) const
        {
            if (left.f != right.f)
            {
                return left.f < right.f;    // f가 가장 작은 정점부터 우선 탐색
            }
            else  // f가 동일한 경우
            {
                return left.h < right.h;    // h가 작은 정점부터 우선 탐색
            }
        }
    };
};
