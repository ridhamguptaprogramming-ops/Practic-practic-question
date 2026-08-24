#include <iostream>
#include <stack>
using namespace std;

int pop(stack<int> &st, int idx) {
    stack<int> helper;
    while (st.size() > idx + 1) {
        helper.push(st.top());
        st.pop();
    }
    int ans = st.top();
    st.pop();
    while (!helper.empty()) {
        st.push(helper.top());
        helper.pop();
    }
    return ans;
}
void pushAt(stack<int> &st, int idx, int val) {
    stack<int> helper;
    while (st.size() > idx) {
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while (!helper.empty()) {
        st.push(helper.top());
        helper.pop();
    }
}
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << " ";
    printStack(st);
    pushAt(st, 2, 80);
    cout << " ";
    printStack(st);
    cout << " " << pop(st, 2) << endl;
    cout << " ";
    printStack(st);
    return 0;
}