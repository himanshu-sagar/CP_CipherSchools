#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void insertInStack(int x){
    if(s.size() == 0)   s.push(x);

    else{
        int a = s.top();
        s.pop();

        insertInStack(x);

        s.push(a);
    }
}

void reverseStack(){
    if(s.size()>0){
        int x = s.top();
        s.pop();
        
        reverseStack();

        insertInStack(x);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5,6};
    for(int i=0;i<v.size();i++) s.push(v[i]);
    printStack(s);
    reverseStack();
    cout<<"\n";
    printStack(s);
}