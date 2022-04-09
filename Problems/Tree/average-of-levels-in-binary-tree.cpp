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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averageValueByLevels;
        queue<TreeNode*> levelNodes;
        levelNodes.push(root);
        while(!levelNodes.empty()){
            int currentLevelSize = levelNodes.size();
            double currentLevelSum = 0;
            for(int i=0;i<currentLevelSize;++i){
                TreeNode* currentNode = levelNodes.front();
                levelNodes.pop();
                currentLevelSum += (double)currentNode->val;
                if(currentNode->left) levelNodes.push(currentNode->left);
                if(currentNode->right) levelNodes.push(currentNode->right);
            }
            averageValueByLevels.push_back(currentLevelSum/currentLevelSize);
        }
        return averageValueByLevels;
    }
};
