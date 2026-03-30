#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;


int main() {
    DoubleLinkedList list;

    cout << "--- Testing Insertion ---" << endl;
    list.InsertAtLast(10);
    list.InsertAtLast(20);
    list.InsertAtLast(30);
    list.InsertAtLast(40);
    list.InsertAtLast(50);
    list.Show(); 


    cout << "\n--- Testing Delete at First (Removes 10) ---" << endl;
    list.deleteAtFirst();
    list.Show();
   

    cout << "\n--- Testing Delete at Last (Removes 50) ---" << endl;
    list.delteAtLast();
    list.Show();

    cout << "\n--- Testing Delete at Position 1 (Removes 30) ---" << endl;
   
    list.delteAtAnyPos(1);
    list.Show();

    cout << "\n--- Final List (Reverse Check) ---" << endl;
    list.ShowReverse();

    return 0;
}