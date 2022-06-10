class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideViewNodes;
        if(root){
            queue<TreeNode*> levelQueue;
            levelQueue.push(root);
            while(!levelQueue.empty()){
                int queueSize = levelQueue.size();
                for(int i=0;i<queueSize;++i){
                    TreeNode* currNode = levelQueue.front();
                    levelQueue.pop();
                    if(i==0){
                        rightSideViewNodes.push_back(currNode->val);
                    }
                    if(currNode->right){
                        levelQueue.push(currNode->right);
                    }
                    if(currNode->left){
                        levelQueue.push(currNode->left);
                    }
                }
            }    
        }
        return rightSideViewNodes;
    }
};
