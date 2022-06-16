/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxPathSumValue = INT_MIN;
    int DFS(TreeNode* root){
        if(!root) return 0;
        int leftSum = max(DFS(root->left), 0);
        int rightSum = max(DFS(root->right), 0);
        int currPathSum = root->val + leftSum + rightSum;
        maxPathSumValue = max(maxPathSumValue, currPathSum);
        return root->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return maxPathSumValue;
    }
};
