class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int maxLen = 0;
        int i = 0, j = 0;
        while(j < s.length()) {
            if(umap.find(s[j]) != umap.end()) {
                maxLen = max(j-i,maxLen);
                i = max(umap[s[j]] + 1,i);
            }
            umap[s[j]] = j;
            j++;
        }

        return max(maxLen,j-i);
    }
};
