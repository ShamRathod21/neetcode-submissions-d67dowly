class TrieNode {
    public: 
        unordered_map<char,TrieNode*> umap;
        bool lastWord;

        TrieNode() {
            lastWord = false;
        }


};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto i : word) {
            if(curr->umap.find(i) == curr->umap.end()) {
                curr-> umap[i] = new TrieNode();
            }
            curr = curr->umap[i];
        }
        curr->lastWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto i : word) {
            if(curr->umap.find(i) != curr->umap.end()) {
                curr = curr->umap[i];
            } else {
                return false;
            }
        }
        return curr->lastWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto i : prefix) {
            if(curr->umap.find(i) != curr->umap.end()) {
                curr = curr->umap[i];
            } else {
                return false;
            }
        }
        return true;
    }
};
