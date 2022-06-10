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
    bool isValidRange(int number, int lowerBound, int higherBound){
        return (number <= higherBound) && (number >= lowerBound);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        if(root){
            if(root->val > high){
                rangeSum += rangeSumBST(root->left, low, high);
            }
            if(root->val < low){
                rangeSum += rangeSumBST(root->right, low, high);
            }
            if(isValidRange(root->val,low,high)){
                rangeSum += root->val + rangeSumBST(root->left, low, high) 
                    + rangeSumBST(root->right, low, high);
            }
        }
        return rangeSum;
    }
};
