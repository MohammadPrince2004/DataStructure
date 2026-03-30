#include "CircularLinkedList.h"
int main() {
    CircularLinkedList list;

    cout << "--- Testing Insertion ---" << endl;
    list.InsertAtFirst(10); 
    list.InsertAtLast(20);   
    list.InsertAtLast(30);   
    list.InsertAtAnyPos(15, 1); 
    list.Show();

    cout << "\n--- Testing Count ---" << endl;
    cout << "Count is: " << list.Count() << " (Expected: 4)" << endl;

    cout << "\n--- Testing Deletion ---" << endl;
    list.DeleteFirstNode();  
    cout << "After Delete First:" << endl;
    list.Show();

    list.DeleteLastNode();   
    cout << "After Delete Last:" << endl;
    list.Show();

    list.DeleteAnyNode(1);  
    cout << "After Delete index 1:" << endl;
    list.Show();

    cout << "\n--- Testing Single Node Deletion ---" << endl;
    list.DeleteFirstNode(); 
    list.Show();            

    return 0;
}