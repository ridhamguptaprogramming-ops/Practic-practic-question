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
void print(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int size(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int sum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->left = b;
    b->left = d;
    cout << "Size = " << size(a) << endl;
    print(a);
    return 0;
}