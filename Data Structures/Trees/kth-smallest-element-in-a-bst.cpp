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
class BSTIterator{
    stack<TreeNode*> values;
    void addNodes(TreeNode* root){
        if(root){
            values.push(root);
            addNodes(root->left);
            
        }
    }
public:
    BSTIterator(TreeNode* root){
        addNodes(root);
    }
    
    int nextNode(){
        auto currNode = values.top();
        values.pop();
        addNodes(currNode->right);
        return currNode->val;
    }
    
    bool hasNext(){
        return !values.empty();
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator * bstIterator = new BSTIterator(root);
        while(k>1){
            bstIterator->nextNode();
            --k;
        }
        return bstIterator->nextNode();
    }
};
