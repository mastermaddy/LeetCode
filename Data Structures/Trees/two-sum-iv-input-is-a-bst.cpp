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
private:
    stack<TreeNode*> elementsInOrder;
    bool order;
    
    void inOrder(TreeNode* root){
        if(root){
            elementsInOrder.push(root);
            if(this->order){
                inOrder(root->left);
            }
            else{
                inOrder(root->right);
            }
        }
    }
    
public:
    BSTIterator(TreeNode* root, bool order){
        this->order = order;
        inOrder(root);
    }
    
    TreeNode* next(){
        TreeNode* currentElement = elementsInOrder.top();
        elementsInOrder.pop();
        order?inOrder(currentElement->right):inOrder(currentElement->left);
        return currentElement;
    }
    
    bool hasNext(){
        return this->elementsInOrder.size() != 0;    
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        BSTIterator* left = new BSTIterator(root,true);
        BSTIterator* right = new BSTIterator(root,false);
        
        TreeNode* leftNumber = left->next();
        TreeNode* rightNumber = right->next();
        while(true){
            if(leftNumber==rightNumber) {
                return false;
            }
            if(target == (leftNumber->val + rightNumber->val)){
                return true;
            }
            else if(target > (leftNumber->val + rightNumber->val)){
                leftNumber = left->next();
            }
            else{
                rightNumber = right->next();
            }
        }
        return false;
    }
};
