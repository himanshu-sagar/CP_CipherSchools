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


void verticalTraversal(map<int, vector<int> >& m, Tree* root, int i){
    if(!root)   return;
    m[i].push_back(root->data);
    verticalTraversal(m,root->left,i-1);
    verticalTraversal(m,root->right,i+1);
}

void leftView(Tree* root, vector<int>& l){
    if(!root) return;
    l.push_back(root->data);
    if(root->left) leftView(root->left, l);
    else leftView(root->right, l);
}

void rightView(Tree* root, vector<int>& rv){
    if(!root) return;
    rv.push_back(root->data);
    if(root->right) rightView(root->right, rv);
    else rightView(root->left, rv);
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Tree* root = NULL;
    for(int i=0;i<v.size();i++) root = insertIntoTree(root,v[i]);
    map<int, vector<int>> m;
    verticalTraversal(m,root,0);
    vector<int> lv, rv;
    // topView(root);
    // bottomView(root);
    leftView(root, lv);
    rightView(root, rv);
    cout<<"Top View : ";
    for(auto x=m.begin(); x!=m.end(); x++){
        cout<<x->second[0]<<" ";
    }
    cout<<"\nBottom View : ";
    for(auto x=m.begin(); x!=m.end(); x++){
        int n = x->second.size();
        cout<<x->second[n-1]<<" ";
    }
    cout<<"\nLeft View : ";
    for(int i=0;i<lv.size();i++) cout<<lv[i]<<" ";
    cout<<"\nRight View :   ";
    for(int i=0;i<rv.size();i++) cout<<rv[i]<<" ";
}