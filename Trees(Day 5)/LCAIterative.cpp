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

bool path(Tree* root, vector<int>& v, int d){
    if(!root) return false;
    v.push_back(root->data);
    if(root->data == d){
        return true;
    }
    if(path(root->left,v,d) || path(root->right,v,d)) return true;
    v.pop_back();
    return false;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = insertIntoTree(root, v[i]);
    vector<int> p1, p2;
    path(root, p1, 8);
    path(root, p2, 9);
    int res = p1[0];
    int i = 1, j =1;
    while(i!=p1.size() && j!=p2.size()){
        if(p1[i] != p2[j]) break;
        res = p2[j];
        i++;
        j++;
    }
    cout<<res;
}