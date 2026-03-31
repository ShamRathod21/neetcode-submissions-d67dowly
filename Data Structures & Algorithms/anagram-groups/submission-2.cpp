class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(auto i : strs) {
            string key = i;
            sort(key.begin(),key.end());
            umap[key].push_back(i);
        } 
        vector<vector<string>> result;
        for(auto i = umap.begin(); i != umap.end(); i++) {
            result.push_back(i->second);
        }
        return result;
    }
};
