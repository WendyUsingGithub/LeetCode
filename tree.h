#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define null INT_MIN

class TreeNode;
TreeNode* buildTree(vector<int> v);
void coutTree(TreeNode *root);
bool queueAllNull(queue<TreeNode *> q);

class TreeNode 
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int> v)
{
    queue<TreeNode *> q;
    TreeNode *currentNode;
    TreeNode *parentNode;
    TreeNode *root;
    int vIndex = 0;
    int size = 0;
    int vSize = 0;

    if(v[0] == INT_MIN) return nullptr;
    root = new TreeNode(v[0]);

    q.push(root);
    q.push(root);
    vIndex++;

    vSize = v.size();
    while(!q.empty() && vIndex < vSize)
    {
        size = q.size();
        for(int i = 0;i < size && vIndex < vSize; i++)
        {
            currentNode = q.front();
            if(v[vIndex] != INT_MIN)
            {
                parentNode = currentNode;
                currentNode = new TreeNode();
                currentNode->val = v[vIndex];

                if(i % 2 == 0) parentNode->left = currentNode;
                else parentNode->right = currentNode;
                
                currentNode->left = nullptr;
                q.push(currentNode);
                currentNode->right = nullptr;
                q.push(currentNode);
            }
            vIndex++;
            q.pop();
        }
    }
    return root;
}

void coutTree(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *currentNode;
    int size = 0;

    q.push(root);
    while(!q.empty() && !queueAllNull(q))
    {
        size = q.size();
        for(int i = 0;i < size; i++)
        {
            currentNode = q.front();
            if(currentNode == nullptr) cout << "* ";
            else cout << currentNode->val << " ";

            if(currentNode != nullptr)
            {
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
            q.pop();
        }
        cout << endl;
    }
    return;
}

bool queueAllNull(queue<TreeNode *> q)
{
    int size = q.size();

    for(int i = 0; i < size; i++)
    {
        if(q.front() != nullptr) return false;
        q.pop();
    }
    return true;
}

#endif