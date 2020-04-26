/*
 * 单链表实现
 * Source: https://leetcode-cn.com/explore/learn/card/linked-list/193/singly-linked-list/741/
 */

#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include <cstdio>

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

/**
 * 单链表，所有节点都是 0-index 的
 */
class MyLinkedList {
private:
    SinglyListNode *head;
public:
    /** Initialize your data structure here. */
    MyLinkedList();

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    /** 获取链表中第 index 个节点的值。如果索引无效，则返回-1 */
    int get(int index);

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked list. */
    /** 在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点 */
    void addAtHead(int val);

    /** Append a node of value val to the last element of the linked list. */
    /** 将值为 val 的节点追加到链表的最后一个元素 */
    void addAtTail(int val);

    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    /** 在链表中的第 index 个节点之前添加值为 val  的节点。
     * 如果 index 等于链表的长度，则该节点将附加到链表的末尾。
     * 如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点 */
    void addAtIndex(int index, int val);

    /** Delete the index-th node in the linked list, if the index is valid. */
    /** 如果索引 index 有效，则删除链表中的第 index 个节点 */
    void deleteAtIndex(int index);

    /** 打印链表 */
    void print_list();
};

#endif //_SINGLY_LINKED_LIST_H
