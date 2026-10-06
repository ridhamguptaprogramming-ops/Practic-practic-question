#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size();

    vector<int> span(n);

    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] <= arr[i]) {
         st.pop();
         }

        if (st.empty()) {
            span[i] = i + 1;
        }
        else {
            span[i] = i - st.top();
        }

        st.push(i);
    }

    return span;
}

int main() {

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = calculateSpan(arr);

    for (int s : span) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}