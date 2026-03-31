class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> umap;
        int len = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            if(umap.find(s[r]) != umap.end()) {
                l = max(l,umap[s[r]] + 1);
            }
            umap[s[r]] = r;
            len = max(len,r-l+1);

        }
        return len;
    }
};
