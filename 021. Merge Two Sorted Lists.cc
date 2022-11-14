#include <iostream>
#include "tree.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main()
{
    ListNode l10 = ListNode(10);
    ListNode l20 = ListNode(20);
    ListNode l30 = ListNode(30);
    ListNode l40 = ListNode(40);
    ListNode l50 = ListNode(50);

    ListNode l15 = ListNode(15);
    ListNode l25 = ListNode(25);
    ListNode l35 = ListNode(35);
    ListNode l45 = ListNode(45);
    ListNode l55 = ListNode(55);

    l10.next = &l20;
    l20.next = &l30;
    l30.next = &l40;
    l40.next = &l50;

    l15.next = &l25;
    l25.next = &l35;
    l35.next = &l45;
    l45.next = &l55;

    coutList(mergeTwoLists(&l10, &l15));
    return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode *head;
    ListNode *current;
    int val1 = 0;
    int val2 = 0;

    if(!list1 && !list2) return nullptr;
    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2 -> next;
    }
    current = head;

    while(list1 && list2)
    {
        val1 = list1->val;
        val2 = list2->val;
        
        if(val1 <= val2)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if(list1 || list2)
    {
        if(list1) current->next = list1;
        else current->next = list2;
    }
    return head;
}