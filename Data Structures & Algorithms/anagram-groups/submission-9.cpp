class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(auto i : strs) {
            string temp = i;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i : umap) {
            res.push_back(i.second);
        }
        return res;
    }
};
