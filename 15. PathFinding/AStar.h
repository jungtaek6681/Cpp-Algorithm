#pragma once
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <algorithm>

#include "Point.h"

using namespace std;

// <A* �˰���>
// ���ͽ�Ʈ�� �˰����� Ȯ���Ͽ� ���� �ִܰ�� Ž���˰���
// ��� Ž���� �켱������ �ΰ� ������ �غ��� �켱������ Ž��
class AStar
{
public:
    static list<Point> PathFinding(vector<vector<bool>> tilemap, Point start, Point end)
    {
        int ySize = tilemap.size();
        int xSize = tilemap[0].size();

        Point direction[] =
        {
            Point( 0, +1),  // ��
            Point( 0, -1),  // ��
            Point(-1,  0),  // ��
            Point(+1,  0),  // ��
            Point(-1, +1),  // �»�
            Point(-1, -1),  // ����
            Point(+1, +1),  // ���
            Point(+1, -1),  // ����
        };
        
        priority_queue<ASNode, vector<ASNode>, ASNodeCompare> pq;
        vector<vector<ASNode>> map = vector<vector<ASNode>>(ySize);
        for (int i = 0; i < ySize; i++)
        {
            map[i] = vector<ASNode>(xSize);
        }


        // 0. ���� ������ ����
        ASNode startNode = ASNode(start, Point(), 0, Heuristic(start, end));
        pq.push(startNode);

        while (pq.size() > 0)
        {
            // 1. �������� Ž���� ������ Ž��
            ASNode nextNode = pq.top();
            pq.pop();
            if (map[nextNode.point.y][nextNode.point.x].checked == true)
                continue;

            map[nextNode.point.y][nextNode.point.x].checked = true;

            // 2. �������� Ž���ϴ� ������ �������� ���
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

            // 3. ������ �������� ������ ���
            for (Point dir : direction)
            {
                int x = nextNode.point.x + dir.x;
                int y = nextNode.point.y + dir.y;

                // 3-0. Ž���ϸ� �ȵǴ� ��� ����
                // ���� ����� ���
                if (x < 0 || x >= xSize || y < 0 || y >= ySize)
                    continue;
                // ���� ���
                if (tilemap[y][x] == false)
                    continue;
                // �̹� Ž���� ������ ���
                if (map[y][x].checked == true)
                    continue;
                
                // 3-1. Ž���ϴ� ������ �����
                int g = nextNode.g + (nextNode.point.x == x || nextNode.point.y == y) ? COST_STRAIGHT : COST_DIAGONAL;
                int h = Heuristic(Point(x, y), end);
                ASNode newNode = ASNode(Point(x, y), nextNode.point, g, h);

                // 3-2. ����� ������ ���� ������ ���Ͽ� �� ���� ��� ����
                ASNodeCompare comparer;
                if (comparer(newNode, map[y][x]))
                {
                    map[y][x] = newNode;
                    pq.push(newNode);
                }
            }
        }

        // ��ΰ� ���� ��� �� ����Ʈ�� ��ȯ
        return list<Point>();
    }

private:
    static const int INF = 9999;
    static const int COST_STRAIGHT = 10;    // ���� �̵� ����ġ
    static const int COST_DIAGONAL = 14;    // �밢�� �̵� ����ġ

    // �޸���ƽ : ���� ���� �Ÿ�
    static int Heuristic(Point start, Point end)
    {
        int xSize = abs(start.x - end.x);   // ���η� �����ϴ� Ƚ��
        int ySize = abs(start.y - end.y);   // ���η� �����ϴ� Ƚ��

        // ����ư �Ÿ� : ������ ���� �̵��ϴ� �Ÿ�
        // return CostStraight * (xSize + ySize);

        // ��Ŭ���� �Ÿ� : �밢���� ���� �̵��ϴ� �Ÿ�
        // return CostStraight * sqrt(xSize * xSize + ySize * ySize);

        // Ÿ�ϸ� �Ÿ� : ������ �밢���� ���� �̵��ϴ� �Ÿ�
        int straightCount = abs(xSize - ySize);
        int diagonalCount = max(xSize, ySize) - straightCount;
        return COST_STRAIGHT * straightCount + COST_DIAGONAL * diagonalCount;
    }

    // ������ ���� ����
    struct ASNode
    {
        bool checked;       // Ž�� ����

        Point point;        // ���� ������ ��ǥ
        Point parent;       // �� ������ Ž���� ��ǥ

        int f;              // ���� �ִ� �Ÿ� : f = g + h
        int g;              // ���� �̵� �Ÿ�
        int h;              // ���� ���� �Ÿ�

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

    // ���� �� �������� Ž���� ������ �����ϱ� ���� ���� �Լ���ü
    struct ASNodeCompare
    {
        bool operator()(const ASNode& left, const ASNode& right) const
        {
            if (left.f != right.f)
            {
                return left.f < right.f;    // f�� ���� ���� �������� �켱 Ž��
            }
            else  // f�� ������ ���
            {
                return left.h < right.h;    // h�� ���� �������� �켱 Ž��
            }
        }
    };
};
