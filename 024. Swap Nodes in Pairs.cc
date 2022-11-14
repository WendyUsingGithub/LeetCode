/*
 * 兩兩一組進行交換
 * 需要注意的是
 * 函式 ListNode** swapPairsRecursive(ListNode** head)
 * 他吃的參數是 ListNode** 回傳的參數也是 ListNode**
 * 因為我們想要改變的是 head pointer 指向的方向
 * 而不是他指向的內容
 * 如果只是傳 ptr 我們只能改動 head 指向的物件的內容
 * 但是我們傳了 ptr of ptr 作為參數
 * 所以可以讓 head 指向被交換之後的 node
 * 
 * 回傳不但是一個 ptr of ptr
 * 他必須是 &(newNext->next)
 * 我們回傳這個 ptr of ptr 是因為我們想要改動到 newNext->next
 * 因為下一組 node 交換之後 
 * newNext->next 需要指向更新後的 node
 */

#include <iostream>
#include "cout.h"

ListNode* swapPairs(ListNode* head);
ListNode** swapPairsRecursive(ListNode** head);

int main()
{
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(4);
    ListNode l5 = ListNode(5);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    coutList(swapPairs(&l1));
    return 0;
}

ListNode* swapPairs(ListNode* head)
{
    ListNode *newHead;
    ListNode **headPtr = &head;

    if(!head) return nullptr;
    if(!head->next) return head;
    newHead = head->next;

    while(1)
    {
        headPtr = swapPairsRecursive(headPtr);
        if(!headPtr) return newHead;
    }
}

ListNode** swapPairsRecursive(ListNode** head)
{
    if(!(*head)) return nullptr;
    if(!(*head)->next) return nullptr;

    ListNode *newNext = (*head);
    ListNode *newHead = (*head)->next;
    ListNode *next2 = (*head)->next->next;

    *head = newHead;
    newHead->next = newNext;
    newNext->next = next2;
    return &(newNext->next);
}
