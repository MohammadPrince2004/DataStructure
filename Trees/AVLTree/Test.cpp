#include "AVL.h"

int main() {
    AVLTree tree;

    int values[] = {10, 20, 30, 40, 50, 25};

    cout << "--- Phase 1: Inserting Elements ---" << endl;
    for (int v : values) {
        cout << "Inserting: " << v << endl;
        tree.InsertData(v);
    }

   
    cout << "\n--- Phase 2: In-Order Traversal (Should be sorted) ---" << endl;
    tree.InOrderTraverse();

    
    cout << "\n--- Phase 3: Pre-Order Traversal (Checking Structure) ---" << endl;
    tree.PreOrderTraverse();

    cout << "\n--- Phase 4: Testing Search ---" << endl;
    cout << "Searching for 25: "; tree.Search(25);
    cout << "Searching for 100: "; tree.Search(100);

 
    cout << "\n--- Phase 5: Deleting Element 30 ---" << endl;
    tree.DeleteItem(30);

    cout << "\n--- Phase 6: Structure After Deletion (Pre-Order) ---" << endl;
    tree.PreOrderTraverse();

    return 0;
}