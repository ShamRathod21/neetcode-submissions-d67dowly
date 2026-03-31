class TrieNode {
    public: 
        unordered_map<char,TrieNode*> umap;
        bool endWord = false;
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
            if(curr->umap.find(i) != curr->umap.end()) {
                curr = curr->umap[i];
                continue;
            }
            curr->umap[i] = new TrieNode();
            curr = curr->umap[i];
        }
        curr->endWord = true;
   
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto i : word) {
            if(curr->umap.find(i) == curr->umap.end())
                return false;
            curr = curr->umap[i];
        }
        return curr->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto i : prefix) {
            if(curr->umap.find(i) == curr->umap.end())
                return false;
            curr = curr->umap[i];
        }
        return true;
    }
};
