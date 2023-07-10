class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int count;

    TrieNode() : isEndOfWord(false), count(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            (curr->children[c])->count++;
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

    string getCommonLongestPrefixString(int strSz) {
        string commonLongestPrefixString = "";
        TrieNode* curr = root;
        bool done = true;
        while (done) {
            done = false;
            for (auto trieNode : curr->children) {
                if (trieNode.second->count == strSz) {
                    commonLongestPrefixString += trieNode.first;
                    curr = trieNode.second;
                    done = true;
                    break;
                }
            }
        }
        return commonLongestPrefixString;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strSz = strs.size();
        Trie trie;
        for (const auto& str : strs) {
            trie.insert(str);
        }
        return trie.getCommonLongestPrefixString(strSz);
    }
};