// https://www.geeksforgeeks.org/merging-intervals/

#include<bits/stdc++.h>
using namespace std;

struct  Intervals{
    int a; int b;
};

bool compare(Intervals i1, Intervals i2){
    return i1.a < i2.a;
}

void mergeIntervals(vector<Intervals> v, stack<Intervals>& s){
    int n = v.size();
    if(n==0) return;

    sort(v.begin(), v.end(), compare);

    s.push(v[0]);
    for(int i=1;i<n;i++){
        Intervals in = s.top();

        if(in.b < v[i].a) s.push(v[i]);
        
        else if(in.b < v[i].b){
            in.b = v[i].b;
            s.pop();
            s.push(in);
        }
    }
}


int main(){
    vector<Intervals> v = { {6,8}, {1,9}, {2,4}, {4,7} };
    stack<Intervals> s;
    mergeIntervals(v,s);
    while(!s.empty()){
        cout<<"( "<<s.top().a<<" , "<<s.top().b<<" )\n";
        s.pop();
    }
}