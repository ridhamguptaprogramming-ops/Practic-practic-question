#include <iostream>
#include <stack>
using namespace std;

int get(stack<int> &st, int idx) {
    stack<int> helper;
    int size = st.size();
    while (st.size() > idx + 1) {
        helper.push(st.top());
        st.pop();
    }
    int ans = st.top();
    while (helper.size() > 0) {
        st.push(helper.top());
        helper.pop();
    }
    return ans;
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
    
    cout << st.size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.size() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(80);
    printStack(st);
    cout << "Element: " << get(st, 2) << endl;
    return 0;
}