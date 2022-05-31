#include <iostream>
#include <queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void coutTree(TreeNode *root);
int minDepth(TreeNode* root);
bool queueAllNull(queue<TreeNode *> q);

int main()
{
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node2.right = &node3;
    node3.right = &node4;
    node4.right = &node5;
    node5.right = &node6;

    coutTree(&node2);
    cout << minDepth(&node2) << endl;
    return 0;
}

int minDepth(TreeNode* root) 
{
    queue<TreeNode *> q;
    TreeNode *currentNode;
    int size = 0;
    int depth = 0;

    if(root == nullptr) return 0;
    q.push(root);

    while(!q.empty())
    {
        depth++;
        size = q.size();
        for(int i = 0;i < size; i++)
        {
            currentNode = q.front();
            if(currentNode->left == nullptr && currentNode->right == nullptr) return depth;
            if(currentNode->left != nullptr) q.push(currentNode->left);
            if(currentNode->right != nullptr) q.push(currentNode->right);
            q.pop();
        }
    }
    return depth;
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