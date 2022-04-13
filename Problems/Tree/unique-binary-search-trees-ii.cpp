class Solution {
private:
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> allUniqueBSTs;
        if(start>end){
            allUniqueBSTs.push_back(nullptr);
            return allUniqueBSTs;
        }
        for(int i=start;i<=end;++i){
            vector<TreeNode*> leftTrees = generateTrees(start,i-1);
            vector<TreeNode*> rightTrees = generateTrees(i+1,end);
            for(auto leftTree:leftTrees){
                for(auto rightTree:rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    allUniqueBSTs.push_back(root);
                }
            }
        }
        return allUniqueBSTs;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> allUniqueBSTs;
        if(n!=0){
            allUniqueBSTs = generateTrees(1, n);
        }
        return allUniqueBSTs;
    }
};
