#include <vector>

using namespace std;

/*******************************************************************
 * 노드 (Node)
 *
 * 여러 자료구조에서 사용하는 기본 단위
 * 데이터와 다른 노드를 참조하는 값을 가짐
 * 다른 노드의 참조를 연결하는 방식에 따라 여러 자료구조를 구현가능
 *******************************************************************/

// <노드 구현>
// 노드에 데이터와 다른 노드를 참조하는 값을 구성하여 구현

// 연결된 노드를 가지는 일정갯수의 변수 또는 배열을 통해 고정적인 연결구조를 가짐
// 연결구조가 일정한 연결리스트 & 트리 등에 사용
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

// 연결된 노드를 가지는 List를 통해 유동적인 연결구조를 가짐
// 연결구조가 일정하지 않은 트리 & 그래프 등에 사용
struct AdjacentNode
{
    int data;

    vector<AdjacentNode*> connect;
};