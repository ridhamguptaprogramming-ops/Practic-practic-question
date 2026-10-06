// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;

// string removeDuplicates(string s) {
//     string<char> st;
//     st.push(s[0]);
//     for (int i = 1; i < s.size(); i++) {
//         if (s[i] == st.top()) st.pop();
//     }
//     s = "";
//     while (st.size()>0){
//         s += st.top();
//         st.pop();
//     } 
//     reverse(s.begin(), s.end());
//     return s;
// }

// int main(){
//    string s = "abbaca";
//    cout << removeDuplicates(s) << endl;
//    s = "azxxzy";
//    cout << removeDuplicates(s) << endl;
// }
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {

        if (!st.empty() && s[i] == st.top()) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }

    string ans = "";

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;

    s = "azxxzy";
    cout << removeDuplicates(s) << endl;

    return 0;
}