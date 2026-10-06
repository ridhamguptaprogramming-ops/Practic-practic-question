#include <iostream>
#include <utility>
using namespace std;

class pair{
public:
    int size;
    int sum;

    pair(int size, int sum) {
        size = f;
        sum = s;
    }
}

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> sizeSum(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }
    pair<int, int> left = sizeSum(root->left);
    pair<int, int> right = sizeSum(root->right);
    int size = 1 + left.first + right.first;
    int sum = root->data + left.second + right.second;
    return make_pair(size, sum);
}
Triplet maxMinIsBST(Node* root) {
    if (root == NULL) {
        return Triplet(INT_MIN, INT_MAX, true);
    }
    Triplet left = maxMinIsBST(root->left);
    Triplet right = maxMinIsBST(root->right);
    int maxVal = max(root->data, max(left.maxVal, right.maxVal));
    int minVal = min(root->data, min(left.minVal, right.minVal));
    bool isBST = left.isBST && right.isBST && (root->data > left.maxVal) && (root->data < right.minVal);
    return Triplet(maxVal, minVal, isBST);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    pair<int, int> ans = sizeSum(root);
    cout << "Size of tree: " << ans.first << endl;
    cout << "Sum of tree: " << ans.second << endl;
    return 0;
}