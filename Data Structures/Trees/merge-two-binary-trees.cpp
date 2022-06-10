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
    TreeNode* mergeTrees(TreeNode* tree1, TreeNode* tree2) {
        if (!tree1 && !tree2) return nullptr;
        int currNodeSum = 0;
        currNodeSum += tree1 ? tree1->val : 0;
        currNodeSum += tree2 ? tree2->val : 0;
        TreeNode* newTreeNode = new TreeNode(currNodeSum);
        newTreeNode->left = mergeTrees(tree1 ? tree1->left : nullptr, 
                             tree2 ? tree2->left : nullptr);
        newTreeNode->right = mergeTrees(tree1 ? tree1->right : nullptr, 
                              tree2 ? tree2->right : nullptr);
        return newTreeNode;
    }
};
