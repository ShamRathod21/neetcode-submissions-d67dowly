class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map <string,vector<int>> map;
       for(int i = 0; i < strs.size(); i++) {
        string str1 = strs[i];
        sort(str1.begin(),str1.end());
        map[str1].push_back(i);
       }
       vector<vector<string>> result;
       for(auto it : map) {
        vector<string> count;
        for(int i = 0; i < it.second.size(); i++) {
            count.push_back(strs[it.second[i]]);
        }
        result.push_back(count);
       }
       return result;
    }
};
