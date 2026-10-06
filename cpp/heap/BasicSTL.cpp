#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;
    vector<int>v={3,7,1,2,9,4};
    for(int i=0; i<6; i++){
        pq.push(v[i]);
    }
    for(int i=0; i<6; i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}