#include <iostream>
using namespace std;

int diameterOfBinaryTree(TreeNode* root) {
       TreeNode* current = root;
        int diameter = 0;

        function<int(TreeNode*)> depth = [&](TreeNode* node) {
            if (!node) return 0;
            int leftDepth = depth(node->left);
            int rightDepth = depth(node->right);
            diameter = max(diameter, leftDepth + rightDepth);
            return max(leftDepth, rightDepth) + 1;
        };

        depth(current);
        return diameter; 
}
int main(){

}