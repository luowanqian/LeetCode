#include <iostream>
#include "linked_list.h"
using namespace std;


int main()
{
    MyLinkedList *obj = new MyLinkedList();

    // add 1 at list head
    obj->addAtHead(1);
    // add 3 at list tail
    obj->addAtTail(3);
    // expect 1 -> 3
    obj->print_list();
    cout << endl;

    // add 2 at index 1
    obj->addAtIndex(1, 2);
    // expect 1 -> 2 -> 3
    obj->print_list();
    cout << endl;

    // get value at index 1, expect 1
    cout << obj->get(1) << endl;
    cout << endl;

    // delete node at index 1
    obj->deleteAtIndex(1);
    // expect 1 -> 3
    obj->print_list();
    cout << endl;

    // get value at index 1, expect 3
    cout << obj->get(1) << endl;

    return 0;
}
