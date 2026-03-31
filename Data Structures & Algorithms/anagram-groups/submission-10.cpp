class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(auto i : strs) {
            string key = i;
            sort(key.begin(), key.end());
            m[key].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i : m) {
            res.push_back(i.second);
        }
        return res;
    }
};
