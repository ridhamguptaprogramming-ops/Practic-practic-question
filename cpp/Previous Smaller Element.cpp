#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/// @brief Finds the previous smaller element for each array element.
/// @param arr Input array.
/// @return A vector containing the previous smaller elements, or -1 if none exists.
vector<int> prevSmaller(vector<int>& arr) {
    vector<int> result(arr.size());
    stack<int> st;

    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : arr[st.top()];
        st.push(i);
    }
    return result;       
}
int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = prevSmaller(arr);

    cout << "Previous Smaller Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;   
}