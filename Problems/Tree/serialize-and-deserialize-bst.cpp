class Codec {
private:
    void doSerialization(TreeNode* root, string &serializedOutput){
        if(!root){
            serializedOutput+="*,";
            return;
        }
        serializedOutput+=to_string(root->val)+",";
        doSerialization(root->left, serializedOutput);
        doSerialization(root->right, serializedOutput);
    }
    
    TreeNode* doDeserialization(vector<string> &data, int &index){
        if(data[index]=="*"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data[index]));
        index++;
        root->left = doDeserialization(data,index);
        index++;
        root->right = doDeserialization(data,index);
        return root;
    }
    
public:
    vector<string> splitString(string inputString){
        stringstream ss(inputString);
        vector<string> result;
        while( ss.good() ){
            string substr;
            getline(ss, substr, ',' );
            result.push_back( substr );
        }
        return result;
    }
    
    string serialize(TreeNode* root) {
        string serializedOutput = "";
        doSerialization(root, serializedOutput);
        return serializedOutput;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splitedData = splitString(data);
        int index = 0, sz = splitedData.size();
        return doDeserialization(splitedData, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
