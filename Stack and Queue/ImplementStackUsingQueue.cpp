#include<bits/stdc++.h>
using namespace std;

void pushInStack(queue<int>& q, int n){
    q.push(n);
    return;
}

int popFromStack(queue<int>& q){

    if(q.empty()){
        cout<<"Stack is empty!!";
        return -1;
    }
    int res;
    queue<int> q1;
    while(q.size() != 1){
        q1.push(q.front());
        q.pop();
    }
    res = q.front();
    q.pop();
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
    }

    return res;
}

int main(){
    vector<int> v = {1,2,3,4,5,6};
    queue<int> q1;
    for(int i=0;i<v.size();i++) pushInStack(q1,v[i]);

    cout<<popFromStack(q1);
}