/*
 * fast/slow pointer
 * fast pointer 走了 N 步之後
 * slow pointr 才出發
 * fast pointer 走到底的時候
 * slow pointer 恰好在從後面數來 N 步的地方
 * 
 * CASE : N = 2
 * 
 *  slow         fast
 *   |            |                      
 * head 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
 * 
 *                    slow          fast
 *                     |             |                      
 * head 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
 */

#include <iostream>
#include "tree.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n);

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

    coutList(removeNthFromEnd(&l1, 5));
    return 0;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = head;

    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while(fast != nullptr)
    {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    if(slow == head) head = slow->next;
    else prev->next = slow->next;
    return head;
}