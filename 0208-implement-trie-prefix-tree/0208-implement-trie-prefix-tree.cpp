class TrieNode {
public:
    TrieNode* children[26];  // pointers to children (a-z)
    bool isEnd;              // marks end of a word
    TrieNode() {
        // Initialize children as NULL
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;  // root node of the Trie
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'a';  // convert character to index (0-25)
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();  // create node if not exists
            }
            node = node->children[idx];  // move to next node
        }
        node->isEnd = true;  // mark end of word
    }
    
    // Search a complete word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(node->children[idx] == nullptr) return false;  // path doesn't exist
            node = node->children[idx];
        }
        return node->isEnd;  // must be an exact word
    }
    
    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(node->children[idx] == nullptr) return false;  // prefix path not found
            node = node->children[idx];
        }
        return true;  // prefix path exists
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */