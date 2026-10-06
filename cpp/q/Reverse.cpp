#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue<int>& q) {
    stack<int> s;
    while (q.size() > 0) {
        s.push(q.front());
        q.pop();
    }
    while (q.size() >0 ) {
        q.push(s.top());
        s.pop();
    }
}
int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    reverse(q);
    
    return 0;
}

// void print(queue<int> q) {
//     while (q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;
// }