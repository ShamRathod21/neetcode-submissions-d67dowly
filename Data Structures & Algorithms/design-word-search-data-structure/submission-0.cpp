class TrieNode {
    public: 
        unordered_map<char,TrieNode*> umap;
        bool isLast = false;
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto i : word) {
            if(curr->umap.find(i) == curr->umap.end()) {
                curr->umap[i] = new TrieNode();
            }
            curr = curr->umap[i];
        }
        curr->isLast = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }


    bool dfs(string word,int j, TrieNode* root) {
        TrieNode* curr = root;
        for(int i = j; i < word.length(); i++) {
            if(word[i] != '.') {
                if(curr->umap.find(word[i]) == curr->umap.end()) {
                    return false;
                }
                curr = curr->umap[word[i]];
            } else {
                unordered_map<char,TrieNode*> umap = curr->umap;
                for(auto it = umap.begin(); it != umap.end(); it++) {
                    if(it->second != nullptr && dfs(word,i+1,it->second)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->isLast;
    }
};
