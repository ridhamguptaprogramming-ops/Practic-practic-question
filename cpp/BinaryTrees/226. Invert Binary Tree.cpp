#include <iostream>
using namespace std;

void inver(TreeNode* root){
    
    if(root == nullptr){
        return;
    }
    swap(root->left, root->right);
    inver(root->left);
    inver(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
        
    }