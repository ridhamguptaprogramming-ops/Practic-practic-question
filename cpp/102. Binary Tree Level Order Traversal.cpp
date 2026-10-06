// #include <iostream>

// using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> result;
//     if (root == nullptr) {
//         return result;
//     }
//     queue<TreeNode*> q;
//     q.push(root);
//     while (!q.empty()) {
//         int levelSize = q.size();
//         vector<int> currentLevel;
//         for (int i = 0; i < levelSize; ++i) {
//             TreeNode* currentNode = q.front();
//             q.pop();
//             currentLevel.push_back(currentNode->val);
//             if (currentNode->left != nullptr) {
//                 q.push(currentNode->left);
//             }
//             if (currentNode->right != nullptr) {
//                 q.push(currentNode->right);
//             }
//         }
//         result.push_back(currentLevel);
//     }
//     return result;
// }
// int main(){

  
// }
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();
            currentLevel.push_back(currentNode->val);
            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
        result.push_back(currentLevel);
    }
    return result;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = levelOrder(root);
    for (vector<int> level : result) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
