#include <iostream>
#include <queue>
using namespace std;
void get(queue<int>& q, int k) {
    int n = q.size();
    if (k > n || k <= 0) {
        cout << "Invalid value of k" << endl;
        return;
    }
    for (int i = 1; i < k; i++) {
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
}
int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    get(q, 3);
    return 0;
}