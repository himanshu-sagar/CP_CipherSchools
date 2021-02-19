// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include<bits/stdc++.h>
using namespace std;


void findLargestInSubarray(vector<int> v, int k, vector<int>& res){
    stack<int> s;
    int n = v.size();
    if(n==0) return;
    int i = 0;
    while(i!=n){
        for(int j=0;j<k;j++){
            if(i+j >= n) return;
            if(s.empty()){
                 s.push(v[i+j]);
            }
            else{
                if(s.top()<v[i+j]){
                    s.pop();
                    s.push(v[i+j]);
                }
            }
        }
        int curr = s.top();
        s.pop();
        res.push_back(curr);
        i++;
    }
}


int main(){
    vector<int> v = {1,2,3,3,3,4,5,6,6,6,7,8,9,10};
    int k = 3;
    vector<int> res;
    findLargestInSubarray(v,k,res);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}