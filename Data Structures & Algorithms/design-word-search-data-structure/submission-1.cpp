class TrieNode {
    public:
        unordered_map<char,TrieNode*> mp;
        bool lastWord;
};
class WordDictionary {
public:
    TrieNode* head;
    WordDictionary() {
        head = new TrieNode();
        head->lastWord = true;
    }
    
    void addWord(string word) {
        TrieNode* curr = head;
        for(auto i : word) {
            if(curr->mp.find(i) == curr->mp.end()) {
                curr->mp[i] = new TrieNode();
            }
            curr = curr->mp[i];
        }
        curr->lastWord = true;
    }

    bool search(string word) {
        return dfs(word,0,head);
    }
    
    bool dfs(string word,int j, TrieNode* root) {
        TrieNode* curr = root;
        for(int i = j; i < word.length(); i++) {
            if(word[i] != '.') {
                if(curr->mp.find(word[i]) == curr->mp.end()) {
                    return false;
                }
                curr = curr->mp[word[i]];
            } else {
                unordered_map<char,TrieNode*> umap = curr->mp;
                for(auto it = umap.begin(); it != umap.end(); it++) {
                    if(it->second != nullptr && dfs(word,i+1,it->second)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->lastWord;
    }
};
