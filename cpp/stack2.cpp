// #include <iostream>
// #include <stack>
// using namespace std;

// bool isBalanced(string s) {
//     if (s.length() % 2 != 0) return false;
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == '(') {
//             st.push(s[i]);
//         } else {
//             if (st.empty()) return false;
//             st.pop();
//         }
//     }
//     return st.empty(); 
// }
// int main() {
//     string s = "()()()";
//     cout << isBalanced(s) << endl; 
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n - 1; 
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1]) {
            ans--;
        }
    }
    
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}