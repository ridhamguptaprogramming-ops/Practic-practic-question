#include <iostream>
#include <stack>
using namespace std;

void removeElement(stack<int> &st) {
    stack<int> temp;
    while (st.size() > 1) {
        temp.push(st.top());
        st.pop();
    }
    st.pop();
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> st;

    cout << st.size() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}