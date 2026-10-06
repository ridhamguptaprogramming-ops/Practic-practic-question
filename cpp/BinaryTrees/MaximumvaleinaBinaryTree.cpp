#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        left = right = nullptr;
    }
};
int maximum(Node* root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    return max(root->val, max(maximum(root->left), maximum(root->right)));
}
int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->left = b;
    a->right = c;
    b->left = d;
    cout << "Maximum = " << maximum(a);
    return 0;
}