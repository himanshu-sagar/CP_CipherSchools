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



int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *root = NULL;
    for (int i = 0; i < v.size(); i++){
        root = insertIntoTree(root, v[i]);
    }
    vector<int> res;
    
    queue<Tree*> q;
    Tree* curr = root;
    q.push(curr);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        res.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }

    for(int i=res.size()-1;i>=0;i--) cout<<res[i]<<"   ";
}