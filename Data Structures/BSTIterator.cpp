class BSTIterator{
private:
    stack<TreeNode*> minStack;
    
    void inOrder(TreeNode* root){
        if(root){
            minStack.push(root);
            inOrder(root->left);
        }
    }
    
public:
    BSTIterator(TreeNode* root){
        inOrder(root);
    }
    
    int next(){
        TreeNode* currNode = minStack.top();
        minStack.pop();
        if(currNode->right){
            inOrder(currNode->right);
        }
        return currNode->val;
    }
    
    int currentTop(){
        return minStack.top()->val;
    }
    
    bool hasNext(){
        return minStack.size() != 0;
    }  
};
