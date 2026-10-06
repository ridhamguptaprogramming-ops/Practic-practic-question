// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         this->val = val;
//         left = right = nullptr;
//     }
// };
// void print(Node* root) {
//     if (root == nullptr) {
//         return;
//     }
//     cout << root->val << " ";
//     print(root->left);
//     print(root->right);
// }
// int main() {
//     Node* a = new Node(1);
//     Node* b = new Node(2);
//     Node* c = new Node(3);
//     Node* d = new Node(4);
    
//     a->left = b;
//     b->left = d;
//     cout << a->left->right->val << " ";
//     cout << b->left->left->val << " ";
//     print(a);

//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         this->val = val;
//         left = right = nullptr;
//     }
// };
// void print(Node* root) {
//     if (root == nullptr) {
//         return;
//     }
//     cout << root->val << " ";
//     print(root->left);
//     print(root->right);
// }
// int main() {
//     Node* a = new Node(1);
//     Node* b = new Node(2);
//     Node* c = new Node(3);
//     Node* d = new Node(4);
//     a->left = b;
//     b->left = d;
//     cout << a->left->left->val << " ";
//     cout << b->left->left->val << " ";
//     cout << c->left->left->val << " ";
//     cout << d->left->left->val << " ";
//     print(a);
//     return 0;
// }
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

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->left = b;
    b->left = d;

    cout << a->left->left->val << " ";  // 4

    print(a);

    return 0;
}