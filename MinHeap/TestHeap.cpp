#include "MinHeap.h"
template <typename TYPE>
int main() {
    MinHeap<int> heap;

    cout << "--- Inserting elements: 50, 10, 40, 5, 20 ---" << endl;
    heap.Insert(50);
    heap.Insert(10);
    heap.Insert(40);
    heap.Insert(5);
    heap.Insert(20);

    cout << "\nCurrent Heap State:" << endl;
    heap.Display();

    cout << "\n--- Extracting elements in order ---" << endl;
    while (!heap.isEmpty()) {
        cout << "Extracted Min: " << heap.ExtractMin() << endl;
    }

    return 0;
}