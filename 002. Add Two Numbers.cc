/*
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 *         9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> Null
 *         9 -> 9 -> 9 -> 9 -> Null
 * --------------------------------------------------
 * carryIn      *              *    *    *    *
 *         8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
 */

#include <vector>
#include "cout.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    ListNode l2(2);
    ListNode l4(4);
    ListNode l3(3);

    l2.next = &l4;
    l4.next = &l3;

    ListNode l5(5);
    ListNode l6(6);
    ListNode l1(1);

    l5.next = &l6;
    l6.next = &l1;

    coutList(addTwoNumbers(&l2, &l5));
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *node;
    ListNode *nodePrev;
    ListNode *nodeHead;
    int carryIn = 0;
    int sum = 0;
    int v1 = 0;
    int v2 = 0;

    nodeHead = new ListNode();
    nodePrev = nodeHead;

    while(l1 != nullptr && l2 != nullptr)
    {
        v1 = l1->val;
        v2 = l2->val;
        sum = v1 + v2 + carryIn;;
        carryIn = sum / 10;
        node = new ListNode(sum % 10);
        nodePrev->next = node;
        nodePrev = node;
        l1 = l1->next;
        l2 = l2->next;
    }    

    if(l1 == nullptr) l1 = l2;

    while(l1 != nullptr)
    {
        v1 = l1->val;
        sum = v1 + carryIn;;
        carryIn = sum / 10;
        node = new ListNode(sum % 10);
        nodePrev->next = node;
        nodePrev = node;
        l1 = l1->next;
    }

    if(carryIn == 1)
    {
        node = new ListNode(1);
        nodePrev->next = node;
    }

    return (nodeHead == nullptr) ? nullptr : nodeHead->next;
}