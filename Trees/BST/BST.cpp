
#include "BinarySearchTree.h"
int main() {
    BinarySearchTree bst;

    // 1. Insertion Test
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(70);
    bst.Insert(60);
    bst.Insert(80);

    cout << "--- Testing Traversals ---" << endl;
    cout << "In-Fix (Sorted): \t";
    bst.TraverseInFix(); 
    cout << endl;

    cout << "Pre-Fix: \t\t";
    bst.TraversePreFix(); 
    cout << endl;

    cout << "Post-Fix: \t\t";
    bst.TraversePostFix();
    cout << endl;

    cout << "Breadth-First: \t\t";
    bst.TraverseBreadth(); 
    cout << endl << endl;

    // 2.Search Test 
    cout << "--- Testing Search ---" << endl;
    cout << "Searching for 40: ";
    bst.Search(40);
    cout << "Searching for 100: ";
    bst.Search(100);
    cout << endl;

    // 3. Max. and Min Testing
    cout << "--- Max and Min ---" << endl;
    cout << "Max value: ";
    bst.getMax();
    cout << "Min value: ";
    bst.getMin();
    cout << endl;

    // 4. Delete Test
    cout << "--- Testing Delete ---" << endl;
    
    cout << "Deleting 20 (Leaf Node)..." << endl;
    bst.DeleteItem(20);
    
    cout << "Deleting 30 (Node with children)..." << endl;
    bst.DeleteItem(30);

    cout << "Final Tree (In-Fix): ";
    bst.TraverseInFix();
    cout << endl;
    cout<<"No of Nodes In Our Tree : "<<bst.getNodesNumber();
    return 0;
}