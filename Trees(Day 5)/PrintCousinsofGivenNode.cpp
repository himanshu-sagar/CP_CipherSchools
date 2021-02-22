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
    int k = 3;
    queue<Tree*> q;
    Tree* temp = root;
    q.push(root);
    while(!q.empty()){
        vector<int> v1;
        int n = q.size();
        for(int i=0;i<n;i++){
            Tree* curr = q.front();
            q.pop();
            v1.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(find(v1.begin(),v1.end(),k) != v1.end()){
            int m = v1.size();
            for(int i=0;i<m;i++){
                if(v1[i] == k) continue;
                cout<<v1[i]<<"  ";
            }
            break;
        }
    }
}