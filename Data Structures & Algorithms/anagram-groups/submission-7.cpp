class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> umap;
        for(int i= 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(),key.end());
            umap[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i : umap) {
            res.push_back(i.second);
        }
        return res;
    }
};
