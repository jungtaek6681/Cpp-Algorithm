#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    vector<int> selectionContainer;
    vector<int> insertionContainer;
    vector<int> bubbleContainer;
    vector<int> mergeContainer;
    vector<int> quickContainer;
    vector<int> heapContainer;

    cout << "랜덤 데이터" << endl;
    for (int i = 0; i < 20; i++)
    {
        int random = rand() % 100;

        cout << random << " ";

        selectionContainer.push_back(random);
        insertionContainer.push_back(random);
        bubbleContainer.push_back(random);
        mergeContainer.push_back(random);
        quickContainer.push_back(random);
        heapContainer.push_back(random);
    }
    cout << endl << endl;

    cout << "선택 정렬" << endl;
    SelectionSort::Sort(selectionContainer);
    for (int element : selectionContainer)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "삽입 정렬" << endl;
    InsertionSort::Sort(insertionContainer);
    for (int element : insertionContainer)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "버블 정렬" << endl;
    BubbleSort::Sort(bubbleContainer);
    for (int element : bubbleContainer)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "병합 정렬" << endl;
    MergeSort::Sort(mergeContainer);
    for (int element : mergeContainer)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "퀵 정렬" << endl;
    QuickSort::Sort(quickContainer);
    for (int element : quickContainer)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "힙 정렬" << endl;
    HeapSort::Sort(heapContainer);
    for (int element : heapContainer)
    {
        cout << element << " ";
    }
    cout << endl;
}
