#include <vector>

using namespace std;

/************************************************************************
 * �׷��� (Graph)
 *
 * ������ ������ �� ������ �մ� ������ ������ ����
 * �� ��忡�� ����Ͽ� �ٽ� �ڱ� �ڽ��� ���� ���ƿ��� ��ȯ������ ����
 * ������ ���⼺�� ���� �ܹ��� �׷���, ����� �׷����� ����
 * ������ ����ġ�� ����   ���� �׷���, ����ġ �׷����� ����
 ************************************************************************/

// <������� �׷���>
// �׷��� ���� �� ������ ���� ���踦 ��Ÿ���� ���
// 2���� �迭�� [�������, ��������] ���� ǥ��
// ���� : �������� ������ ����
// ���� : �޸� ��뷮�� ����

// ���� - ����� ���� �׷���
vector<vector<bool>> matrixGraph1 =
{
    { false, false, false, false,  true },
    { false, false,  true, false, false },
    { false,  true, false,  true, false },
    { false, false,  true, false,  true },
    {  true, false, false,  true, false },
};

const int INF = 99999;

// ���� - �ܹ��� ����ġ �׷��� (������ ���� ������ ǥ��)
vector<vector<int>> matrixGraph2 =
{
    {   0, 132, INF, INF,  16 },
    {  12,   0, INF, INF, INF },
    { INF,  38,   0, INF, INF },
    { INF,  12, INF,   0,  54 },
    { INF, INF, INF, INF,   0 },
};


// <��������Ʈ �׷���>
// �׷��� ���� �� ������ ���� ���踦 ǥ���ϴ� ����Ʈ
// ������ �������� ����Ʈ�� �߰��Ͽ� ����
// ���� : �޸� ��뷮�� ����
// ���� : �������θ� Ȯ���ϱ� ���� ����Ʈ Ž���� �ʿ�

// ����
vector<int> listGraph1[5];              // ���� �׷���
vector<pair<int, int>> listGraph2[5];   // ����ġ �׷���
void CreateGraph()
{
    listGraph1[0].push_back(1);
    listGraph1[1].push_back(0);
    listGraph1[1].push_back(3);
    listGraph1[2].push_back(0);
    listGraph1[2].push_back(1);
    listGraph1[2].push_back(4);
    listGraph1[3].push_back(1);
    listGraph1[4].push_back(3);
}