#ifndef COUT_H
#define COUT_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void coutVector(vector<int> v)
{
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++)
    {
        if(*it == INT_MIN) cout << "* ";
        else cout << *it << " ";
    }
    cout << endl;
}

void coutVectorVector(vector<vector<int>> v)
{
    vector<vector<int>>::iterator it;

    for(it = v.begin(); it != v.end(); it++)
    {
        coutVector(*it);
    }
    cout << endl;
}

void coutListNode(ListNode *node)
{
    while(node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
#endif