#include <iostream>
#include <stack>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
        
//     }
// };

bool check(string & s){
  stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(st.empty()){
                return false;
            }
            char top = st.top();
            if((ch == '(' && top == ')') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main() {
    string s = "({[]})";
    cout << check(s) << endl;
    return 0;
}