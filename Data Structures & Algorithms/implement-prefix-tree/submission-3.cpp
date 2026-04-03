class TrieNode{
    public:
    unordered_map<char, TrieNode*> mp;
    bool last = false;
};
class PrefixTree {
public:
    TrieNode* head;
    PrefixTree() {
        head = new TrieNode();
        head->last = true;
    }
    
    void insert(string word) {
        TrieNode* curr = head;
        for(auto i : word) {
            if(curr->mp.find(i) == curr->mp.end()) {
                curr->mp[i] = new TrieNode();
            }               
            curr = curr->mp[i];

        }
        curr->last = true;
    }
    
    bool search(string word) {
        TrieNode* curr = head;
        for(auto i : word) {
            if(curr->mp.find(i) == curr->mp.end())
                return false;
            curr = curr->mp[i];
        }
        return curr->last;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = head;
        for(auto i : prefix) {
            if(curr->mp.find(i) == curr->mp.end())
                return false;
            curr = curr->mp[i];
        }
        return true;
    }
};
