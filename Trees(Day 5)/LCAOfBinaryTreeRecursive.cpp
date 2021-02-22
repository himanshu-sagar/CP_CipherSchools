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

Tree* LCA(Tree* root, int a, int b){
    if(!root) return NULL;
    if(root->data == a || root->data == b) return root;

    Tree* l = LCA(root->left, a, b);
    Tree* r = LCA(root->right, a, b);

    if(l!=NULL && r!=NULL) return root;
    else return (l!=NULL)?l:r;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = insertIntoTree(root, v[i]);
    Tree* res = LCA(root, 9, 8);
    cout<<res->data;
}