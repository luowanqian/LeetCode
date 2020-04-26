#include "linked_list.h"
#include <iostream>


MyLinkedList::MyLinkedList()
{
    head = NULL;
}

int MyLinkedList::get(int index)
{
    SinglyListNode *node;
    int pos;

    if (index < 0)
        return -1;

    node = head;
    pos = 0;
    while (NULL != node) {
        if (pos == index)
            return node->val;
        node = node->next;
        pos++;
    }

    return -1;
}

void MyLinkedList::addAtHead(int val)
{
    SinglyListNode *node;

    node = new SinglyListNode(val);
    node->next = head;
    head = node;
}

void MyLinkedList::addAtTail(int val)
{
    SinglyListNode *node, *pre_node, *cur_node;

    node = new SinglyListNode(val);

    if (NULL == head) {
        head = node;
        return;
    }

    pre_node = NULL;
    cur_node = head;
    while (NULL != cur_node) {
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    pre_node->next = node;

}

void MyLinkedList::addAtIndex(int index, int val)
{
    SinglyListNode *node, *pre_node, *cur_node;
    int pos;

    if (index < 0) {
        addAtHead(val);
        return;
    }

    node = new SinglyListNode(val);
    pos = 0;
    pre_node = NULL;
    cur_node = head;
    while (NULL != cur_node) {
        if (index == pos)
            break;
        pos++;
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    if (NULL == pre_node) {
        node->next = head;
        head = node;
    } else if (index <= pos) {
        node->next = pre_node->next;
        pre_node->next = node;
    }
}

void MyLinkedList::deleteAtIndex(int index)
{
    SinglyListNode *pre_node, *cur_node;
    int pos;

    if (index < 0) {
        return;
    }
    if (index == 0 && NULL != head) {
        // delete head
        cur_node = head->next;
        delete head;
        head = cur_node;
        return;
    }

    pos = 0;
    pre_node = NULL;
    cur_node = head;
    while (NULL != cur_node) {
        if (pos == index) {
            pre_node->next = cur_node->next;
            delete cur_node;
            break;
        }
        pos++;
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
}

void MyLinkedList::print_list()
{
    SinglyListNode *node;

    node = head;
    std::cout << "List: ";
    while (NULL != node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}