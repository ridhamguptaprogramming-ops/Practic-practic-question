#include <iostream>
#include <queue>
using namespace std;

void print(queue<int>& q) {
   int n = q.size();
   for(int i = 0; i < n; i++) {
      cout << q.front() << " ";
      q.push(q.front());
      q.pop();
   }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    q.push(40);
    cout << q.front() << endl;
    q.pop();
    return 0;
}