#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string> &arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == "+") {
            int top = st.top();
            st.pop();
            int newTop = top + st.top();
            st.push(top);
            st.push(newTop);
        }
        else if (arr[i] == "D") {
            st.push(2 * st.top());
        }
        else if (arr[i] == "C") {
            st.pop();
        }
        else {
            st.push(stoi(arr[i]));
        }
    }
    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}
int main() {
    vector<string> arr = {"8", "1", "D", "3", "4", "C", "+", "+"};
    cout << calPoints(arr) << endl;
    return 0;
}