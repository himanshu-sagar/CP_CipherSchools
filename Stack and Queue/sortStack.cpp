// https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"  ";
        s.pop();
    }
}

void sortInsert(stack<int>& s, int k){
    if(s.empty() || k > s.top()) s.push(k);
    else{
        int temp = s.top();
        s.pop();
        sortInsert(s, temp);
        s.push(temp);
    }
    return;
}

void sortStack(stack<int>& s){
    if(!s.empty()){
        int k = s.top();
        s.pop();
        sortStack(s);
        sortInsert(s,k);
    }
}

int main(){
    stack<int> s;
    vector<int> v = {1,4,2,5,3,6,10};
    for(int i=0;i<v.size();i++) s.push(v[i]);
    printStack(s);
    sortStack(s);
    cout<<"\n";
    printStack(s);
}