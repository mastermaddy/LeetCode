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
public:
    bool isNodeLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
    
    int sumRootToLeaf(TreeNode* root, int childSum=0) {
        if(!root) return 0;
        int currentSum = 2*childSum + root->val;
        if(isNodeLeaf(root)){
            return currentSum;
        }
        return sumRootToLeaf(root->left,currentSum) + sumRootToLeaf(root->right, currentSum);
    }
};
