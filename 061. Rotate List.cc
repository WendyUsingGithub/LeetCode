/*
 * 向右轉 k 個代表倒數第 k 個 node 要做新的 head
 * 第 k - 1 個 node 要成為新的尾端, next 指向 null
 * 原本的尾端變成一個普通的 node, next 指向原本的 head
 */

#include "cout.h"

ListNode* rotateRight(ListNode* head, int k);

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

    coutList(rotateRight(&l1, 2));
    return 0;
}

ListNode* rotateRight(ListNode* head, int k)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *lastFast = nullptr;
    ListNode *lastSlow = nullptr;
    int count = 0;

    while(fast != nullptr)
    {
        count++;
        fast = fast->next;
    }
    cout << count << endl;
    fast = head;
    
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return head;
    if(k == 0) return head;

    k = k % count;
    if(k == 0) return head;

    for(int i = 0; i < k; i++)
    {
        if(fast->next == nullptr) fast = head;
        else fast = fast->next;
    }

    if(fast == head) return head;

    while(fast != nullptr)
    {
        lastSlow = slow;
        slow = slow->next;
        lastFast = fast;
        fast = fast->next;
    }

    lastSlow->next = nullptr;
    lastFast->next = head;
    return slow;
}