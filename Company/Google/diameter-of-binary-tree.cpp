class Solution {
private:
    int getDiameterOfBinaryTree(TreeNode* root, int &dim){
        if(!root){
            return 0;
        }
        int rightRadius = getDiameterOfBinaryTree(root->right, dim);
        int leftRadius = getDiameterOfBinaryTree(root->left, dim);
        dim = max(dim, rightRadius + leftRadius);
        return max(rightRadius, leftRadius) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dim = 0;
        getDiameterOfBinaryTree(root, dim);
        return dim;
    }
};
