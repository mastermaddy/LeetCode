/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void preOrderUtil(Node* root, vector<int> &pre_order){
        if(!root) return;
        pre_order.push_back(root->val);
        for(auto child:root->children){
            preOrderUtil(child, pre_order);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> pre_order;
        preOrderUtil(root, pre_order);
        return pre_order;
    }
};
