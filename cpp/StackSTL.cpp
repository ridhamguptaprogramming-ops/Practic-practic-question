#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st) {

    stack<int> helper;

    while (!st.empty()) {
        cout << st.top() << " ";
        helper.push(st.top());
        st.pop();
    }

    while (!helper.empty()) {
        st.push(helper.top());
        helper.pop();
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

    return 0;
}