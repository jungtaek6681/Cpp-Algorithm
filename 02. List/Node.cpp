#include <vector>

using namespace std;

/*******************************************************************
 * ��� (Node)
 *
 * ���� �ڷᱸ������ ����ϴ� �⺻ ����
 * �����Ϳ� �ٸ� ��带 �����ϴ� ���� ����
 * �ٸ� ����� ������ �����ϴ� ��Ŀ� ���� ���� �ڷᱸ���� ��������
 *******************************************************************/

// <��� ����>
// ��忡 �����Ϳ� �ٸ� ��带 �����ϴ� ���� �����Ͽ� ����

// ����� ��带 ������ ���������� ���� �Ǵ� �迭�� ���� �������� ���ᱸ���� ����
// ���ᱸ���� ������ ���Ḯ��Ʈ & Ʈ�� � ���
struct LinkedListNode
{
    int data;

    LinkedListNode* prev;
    LinkedListNode* next;
};

struct BinaryTreeNode
{
    int data;

    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

struct OctTreeNode
{
    int data;

    OctTreeNode* parent;
    OctTreeNode* children[8];
};

// ����� ��带 ������ List�� ���� �������� ���ᱸ���� ����
// ���ᱸ���� �������� ���� Ʈ�� & �׷��� � ���
struct AdjacentNode
{
    int data;

    vector<AdjacentNode*> connect;
};