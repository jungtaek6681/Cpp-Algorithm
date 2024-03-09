#include <vector>

using namespace std;

/*******************************************************************************
 * 트리 (Tree)
 *
 * 계층적인 자료를 나타내는데 자주 사용되는 자료구조
 * 부모노드가 여러자식노드들을 가질 수 있는 1 대 다 구조
 * 한 노드에서 출발하여 다시 자기 자신의 노드로 돌아오는 순환구조를 가지지 않음
 ********************************************************************************/

// <트리 구성>
// 부모(Parent) : 루트 노드 방향으로 직접 연결된 노드
// 자식(Child)  : 루트 노드 반대방향으로 직접 연결된 노드
//
// 뿌리(root)   : 부모노드가 없는 최상위 노드, 트리의 깊이 0에 하나만 존재
// 가지(Branch) : 부모노드와 자식노드가 모두 있는 노드, 트리의 중간에 존재
// 잎(Leaf)     : 자식노드가 없는 노드, 트리의 끝에 존재
//
// 길이(Length) : 출발 노드에서 도착 노드까지 거치는 수
// 깊이(Depth)  : 루트 노드부터의 길이
// 차수(Degree) : 자식노드의 갯수
//
//             뿌리                  - 깊이 0
//        ┌─────┼─────┐
//       가지  가지  가지            - 깊이 1
//  ┌─────┤     │     │
// 가지  가지   잎   가지            - 깊이 2
//  │     │           ├────┬────┐
//  잎    잎         가지  잎   잎   - 깊이 3
//                    ├────┐
//                    잎   잎        - 깊이 4


// <트리 사용처>
// 주로 계층구조를 가질 수 있는 자료나 효율적인 검색에 많이 사용됨
// ex) 윈도우의 폴더 구조, 문서의 목차, 데이터 베이스 & 검색 엔진의 구조
//     상위스킬을 배워야 하위스킬을 배울 수 있는 스킬트리


// <트리 구현>
// 노드를 기반으로 부모노드와 자식노드들을 보관할 수 있도록 구성
// 자식노드들의 최대갯수가 정해져 있는 경우 배열로, 정해지지 않은 경우 리스트로 구현
struct TreeNode
{
    int item;
    TreeNode* parent;
    vector<TreeNode*> children;
};


// <이진 트리>
// 부모노드가 자식노드를 최대 2개까지만 가질 수 있는 트리
// n개의 자식을 가질 수 있는 트리를 연결구조를 변경하여 이진트리로 변환 가능
// 그러므로, 특별한 이유가 없는 이상은 이진 트리로 구현하는 것이 일반적
struct BinaryNode
{
    int item;
    BinaryNode* parent;
    BinaryNode* left;
    BinaryNode* right;
};


// <이진트리 순회>
// 트리는 비선형 자료구조로 순차적 처리를 위해 순서에 대해 규칙을 선정해야 함
// 순회의 방식은 크게 전위, 중위, 후위 순회가 있음
// 전위순회(Pre-Order)  : 노드, 왼쪽, 오른쪽
// 중위순회(In-Order)   : 왼쪽, 노드, 오른쪽
// 후위순회(Post-Order) : 왼쪽, 오른쪽, 노드
//
//        A
//    ┌───┴───┐
//    B       C
//  ┌─┴─┐   ┌─┴─┐
//  D   E   F   G
//
// 전위순회 : A, (B, D, E), (C, F, G) => A, B, D, E, C, F, G
// 중위순회 : (D, B, E), A, (F, C, G) => D, B, E, A, F, C, G
// 후위순회 : (D, E, B), (F, G, C), A => D, E, B, F, G, C, A
