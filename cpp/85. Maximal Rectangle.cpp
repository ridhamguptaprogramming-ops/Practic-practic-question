#include <iostream>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        stack<int> st;
        for (int j = 0; j <= cols; j++) {
            while (!st.empty() && (j == cols || heights[j] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(j);
        }
    }
    return maxArea;  
}
int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int maxArea = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << maxArea << endl;
    return 0;
}