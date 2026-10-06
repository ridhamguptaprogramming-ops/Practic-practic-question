#include <iostream>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL   && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);          
}
int main(){
    treeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

}