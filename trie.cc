class TrieNode {
    public:
        unordered_map<char,TrieNode*> map;
        bool isEnd;
    TrieNode(){
        isEnd = false;
    }
};
class Trie {
    private:
        TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto const& c : word){
            if(node->map.find(c)!=node->map.end()){
                node = node->map[c];
            } else {
                node->map[c] = new TrieNode();
                node = node->map[c];
            }
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(auto const& c : word){
            if(node->map.find(c)==node->map.end()){
                return false;
            } 
            node = node->map[c];
        }
        if(node->isEnd) return true;
        return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto const& c : prefix){
            if(node->map.find(c)==node->map.end()){
                return false;
            }
            node = node->map[c];
        }
            return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
