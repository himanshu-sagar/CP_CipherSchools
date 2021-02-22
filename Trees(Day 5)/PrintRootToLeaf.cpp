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

void rootToLeaf(Tree* root, vector<vector<int>>& res, vector<int> temp){
    if(!root) return;
    temp.push_back(root->data);
    if(!root->left && !root->right){
        res.push_back(temp);
        return;
    }

    rootToLeaf(root->left,res,temp);
    rootToLeaf(root->right,res,temp);
}


int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *root = NULL;
    for (int i = 0; i < v.size(); i++){
        root = insertIntoTree(root, v[i]);
    }
    vector<vector<int> > res;
    vector<int> temp;
    rootToLeaf(root,res,temp);

    for(int i=0;i<res.size();i++){
        cout<<"Path "<<i+1<<" : ";
        for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}