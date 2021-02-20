#include<bits/stdc++.h>
using namespace std;

void pushInQueue(stack<int>& s, int n){
    s.push(n);
    return;
}

int popFromQueue(stack<int>& s){
    int res;
    if(s.empty()){
        cout<<"Queue is empty!!";
        return -1;
    }
    stack<int> s1;
    while(s.size()!=1){
        s1.push(s.top());
        s.pop();
    }

    res = s.top();
    s.pop();

    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }

    return res;
}

int main(){
    stack<int> s;
    vector<int> v = {1,2,3,4,5,6};
    for(int i=0;i<v.size();i++) pushInQueue(s,v[i]);

    cout<<popFromQueue(s);
}