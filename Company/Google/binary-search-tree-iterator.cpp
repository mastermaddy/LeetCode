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
class BSTIterator {
private:
    stack<TreeNode*> inOrderTraversalStack;
    void insertNodeInStack(TreeNode* root){
        if(root){
            inOrderTraversalStack.push(root);
            root = root->left;
            insertNodeInStack(root);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        if(root){
            insertNodeInStack(root);
        }
    }
    
    int next() {
        TreeNode* currentNode = inOrderTraversalStack.top();
        inOrderTraversalStack.pop();
        insertNodeInStack(currentNode->right);
        return currentNode->val;
    }
    
    bool hasNext() {
        return !inOrderTraversalStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
