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
    void postOrderUtil(Node* root, vector<int> &post_order){
        if(!root) return;
        for(auto child:root->children){
            postOrderUtil(child, post_order);
        }
        post_order.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> post_order;
        postOrderUtil(root, post_order);
        return post_order;
    }
};
