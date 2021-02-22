#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

Tree *insertIntoTree(Tree *root, int n)
{
    if (!root)
        return new Tree(n);
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        else
        {
            curr->left = new Tree(n);
            return root;
        }
        if (curr->right)
            q.push(curr->right);
        else
        {
            curr->right = new Tree(n);
            return root;
        }
    }
    return root;
}

void findAllNodes(Tree *root, int k)
{
    if (!root || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << "  ";
        return;
    }
    findAllNodes(root->left, k - 1);
    findAllNodes(root->right, k - 1);
}

int findTargetAndGetValue(Tree *root, Tree *target, int k)
{
    if (!root)
        return -1;
    if (root == target)
    {
        findAllNodes(root, k);
        return 0;
    }

    int checkLeft = findTargetAndGetValue(root->left, target, k);
    if (checkLeft != -1)
    {
        if (checkLeft + 1 == k)
            cout << root->data << " ";
        else
            findAllNodes(root->right, k - checkLeft - 2);
        return 1 + checkLeft;
    }

    int checkRight = findTargetAndGetValue(root->right, target, k);
    if (checkRight != -1)
    {
        if (checkRight + 1 == k)
            cout << root->data << " ";
        else
            findAllNodes(root->left, k - checkRight - 2);
        return 1 + checkRight;
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *root = NULL;
    for (int i = 0; i < v.size(); i++)
    {
        root = insertIntoTree(root, v[i]);
    }
    int k = 2;
    Tree *target = root->left;
    findTargetAndGetValue(root, target, k);
}