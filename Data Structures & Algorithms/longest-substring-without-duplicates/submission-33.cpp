class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> umap;
        int l=0,r = 1;
        int len =0;
        for(int i = 0; i < s.length(); i++) {
            if(umap.find(s[i]) != umap.end()) {
                l = max(l,umap[s[i]]+1);
            }
            len = max(len,r-l);
            r++;
            umap[s[i]] = i;
        }
        return len;

    }
};
