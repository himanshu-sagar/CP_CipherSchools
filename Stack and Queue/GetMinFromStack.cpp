#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int index;
    int capacity;
    int gmin;

    public:
        Stack(int n){
            this->gmin = INT_MAX;
            this->index = -1;
            this->capacity = n;
            this->arr = new int(this->capacity);
        }


        void push(int n){
            this->index++;
            if(this->index >= this->capacity){
                this->index--;
                cout<<"Stack OverFlow";
                return;
            }
            else{
                this->gmin = min(this->gmin, n);
                this->arr[this->index] = n;
                return;
            }
        }

        int pop(){
            if(this->index == -1){
                cout<<"Stack is empty!!";
                return -1;
            }
            int res = this->arr[this->index];
            this->index--;
            if(res == this->gmin){
                this->gmin = INT_MAX;
                for(int i=0;i<this->index;i++){
                    gmin = min(gmin, this->arr[i]);
                }
            }
            return res;
        }

        int getMin(){
            return this->gmin;
        }

        void print(){
            if(this->index == -1){
                cout<<"Stack is Empty";
                return;
            }
            for(int i=0;i<this->index;i++) cout<<this->arr[i]<<" ";
            cout<<"\n";
        }
};


int main(){
    Stack s(5);
    s.push(10);
    s.push(11);
    s.print();
    cout<<s.getMin()<<"\n";
    s.push(2);
    s.push(5);
    s.push(20);
    s.push(22);
    cout<<"\n"<<s.pop();
}