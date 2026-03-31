class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(string str : strs ) {
            string temp = str;
            sort(str.begin(),str.end());
            umap[str].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto i : umap) {
            res.push_back(i.second);
        }
        return res;
        
    }
};
