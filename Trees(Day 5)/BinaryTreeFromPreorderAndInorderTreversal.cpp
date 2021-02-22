#include<bits/stdc++.h>
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
        Tree* curr = q.front();
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

int findInInorder(vector<int> in, int d){
    int n = in.size();
    for(int i=0;i<n;i++){
        if(in[i] == d) return i;
    }
    return -1;
}

Tree* createTree(vector<int> pre, vector<int> in, int l, int h){
    static int idx = 0;
    if(l > h) return NULL;
    Tree* root = new Tree(pre[idx++]);
    if(l == h) return root;
    int p = findInInorder(in,root->data);
    root->left = createTree(pre, in, l, p-1);
    root->right = createTree(pre, in, p+1, h);

    return root;
}

int main(){
    vector<int> pre = {1,2,4,5,3,6};
    vector<int> in = {4,2,5,1,6,3};
    Tree* root = NULL;
    root = createTree(pre, in, 0, pre.size()-1);
    preorder(root);
}