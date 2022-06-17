class Trie {
private:
    unordered_map<char, Trie*> children;
    bool isEnd = false;
public:
    Trie() {
    }
    void insert(string word1) {
        Trie* node = this;
        for(auto c:word1){
            if(node->children.find(c)==node->children.end()){
                node->children[c] = new Trie();    
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word1) {
        Trie* node = this;
        for(auto c:word1){
            if(node->children.find(c)==node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto c:prefix){
            if(node->children.find(c)==node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
