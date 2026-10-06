#include <iostream>
using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights) {
 stack<int> st;
    int n = heights.size();
    vector<int> result(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[i] > heights[st.top()]) {
            result[i]++;
            st.pop();
        }
        if (!st.empty()) {
            result[i]++;
        }
        st.push(i);
    }

    return result;
}
int main(){
  int n;
  cin >> n;
  vector<int> heights(n);
  for(int i = 0; i < n; i++){
    cin >> heights[i];  
  }
}