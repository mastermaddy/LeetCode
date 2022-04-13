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
    unordered_map<string, int> countOfSubtrees;
    vector<TreeNode*> duplicateList;
    string postOrder(TreeNode* root){
        if(!root){
            return "";        
        }
        else{
            string leftSubtree = postOrder(root->left);
            string rightSubtree = postOrder(root->right);
            string thisSubtree = to_string(root->val) + "_" + leftSubtree + "_" + rightSubtree;
            if(countOfSubtrees[thisSubtree]==1){
                duplicateList.push_back(root);
            }
            countOfSubtrees[thisSubtree]++;
            return thisSubtree;
        }
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postOrder(root);
        return duplicateList;
    }
};
