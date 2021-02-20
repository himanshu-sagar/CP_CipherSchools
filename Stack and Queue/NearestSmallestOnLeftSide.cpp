// https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/


#include<bits/stdc++.h>
using namespace std;


void findSmallest(vector<int>& v){
    int n = v.size();
    if(n==0) return;

    stack<int> s;
    s.push(v[0]);
    v[0] = -1;
    for(int i=1;i<n;i++){
        int k = v[i];
        if(s.top()<k)   v[i] = s.top();
        
        else{

            while(!s.empty() && s.top()>v[i]) s.pop();

            if(s.empty())   v[i] = -1;

            else   v[i] = s.top();
        }
        
        s.push(k);
    }
}


int main(){
    vector<int> v = {1,4,5,3,5,10};
    findSmallest(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
}