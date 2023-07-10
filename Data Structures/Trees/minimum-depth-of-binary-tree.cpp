class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        int minimumDepth = (leftDepth == 0 || rightDepth == 0) ?
            max(leftDepth, rightDepth) :
            min(leftDepth, rightDepth);
        return 1 + minimumDepth;
    }
};