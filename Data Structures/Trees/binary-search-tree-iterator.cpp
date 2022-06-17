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
    stack<TreeNode*> inOrder;
    void InsertInStack(TreeNode* root){
        while(root){
            inOrder.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        InsertInStack(root);
    }
    
    int next() {
        if(hasNext()){
            TreeNode* currTop = inOrder.top();
            inOrder.pop();
            InsertInStack(currTop->right);
            return currTop->val;
        }
        return -1;
    }
    
    bool hasNext() {
        return !inOrder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
