#include <iostream>
#include <stack>
#include <string>
using namespace std;

string simplifyPath(string path) {
    stack<string> st;
    string result;

    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '/') {
            continue;
        }

        string temp;

        while (i < path.length() && path[i] != '/') {
            temp += path[i];
            ++i;
        }

        if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        }
        else if (temp != "." && !temp.empty()) {
            st.push(temp);
        }
    }

    while (!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
    }

    return result.empty() ? "/" : result;
}

int main() {
    string path = "/home/";
    string simplifiedPath = simplifyPath(path);

    cout << "Simplified Path: " << simplifiedPath << endl;

    return 0;
}
