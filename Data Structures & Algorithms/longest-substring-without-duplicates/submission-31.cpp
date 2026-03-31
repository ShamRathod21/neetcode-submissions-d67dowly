class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxL = 0;
        if(s.length() <= 1) {
            return s.length();
        }
        unordered_map<char,int> umap;
        while(r < s.length()) {
            if(umap.find(s[r]) != umap.end()) {
                l = max(l,umap[s[r]] + 1);
            }
            umap[s[r]] = r;

            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
