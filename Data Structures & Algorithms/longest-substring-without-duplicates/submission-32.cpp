class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char,int> umap;
        for(r; r < s.length(); r++) {
            if(umap.find(s[r]) != umap.end()) {
                l = max(umap[s[r]]+1,l);
            }
            umap[s[r]] = r;
res = max(res, r - l + 1);          }
return res;
    }
};
