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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> processingNodes;
        vector<int> inorderTraversalValue;
        TreeNode* currentNode = root;
        while(true){
            if(currentNode){
                processingNodes.push(currentNode);
                currentNode = currentNode->left;
            }
            else{
                if(processingNodes.empty()){
                    break;
                }
                TreeNode* node = processingNodes.top();
                inorderTraversalValue.push_back(node->val);
                processingNodes.pop();
                currentNode = node->right;
            }
        }
        return inorderTraversalValue;
    }
};
