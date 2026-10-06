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
int product(Node* root) {
    if (root == nullptr) {
        return 1;
    }
    return root->val * product(root->left) * product(root->right);
}
int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->left = b;
    a->right = c;
    b->left = d;
    cout << "Product = " << product(a);
    return 0;
}