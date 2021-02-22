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

void preorder(Tree *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int maxPathSum(Tree *root, int &d)
{
   if(!root) return 0;

   if(!root->left && !root->right) return root->data;

    int l = maxPathSum(root->left, d);
    int r = maxPathSum(root->right, d);

    if(root->left && root->right){
        d = max(d, l+r+root->data);

        return max(l,r) + root->data;
    }

    return (l)? l+root->data : r+root->data;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *root = NULL;
    for (int i = 0; i < v.size(); i++)
        root = insertIntoTree(root, v[i]);
    int diameter = 0;
    int res = maxPathSum(root, diameter);
    cout<<max(res, diameter);
}