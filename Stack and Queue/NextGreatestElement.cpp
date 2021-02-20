// https://www.geeksforgeeks.org/next-greater-element/

#include<bits/stdc++.h>
using namespace std;

void nextGreatestElement(vector<int>& v){
    int n = v.size();
    if(n==0) return;
    stack<int> s;
    s.push(v[n-1]);
    v[n-1] = -1;
    for(int i=n-2;i>=0;i--){
        int k = v[i];
        if(s.top()>k){
             v[i] = s.top();
             s.push(k);
        }
        else{
            while(!s.empty() && s.top()<k){
                s.pop();
            }
            if(s.empty()){
                v[i] = -1;
            }
            else{
                v[i] = s.top();
            }
            s.push(k);
        }
    }
}

int main(){
    vector<int> v = {3,4,2,6,10,5};
    nextGreatestElement(v);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}