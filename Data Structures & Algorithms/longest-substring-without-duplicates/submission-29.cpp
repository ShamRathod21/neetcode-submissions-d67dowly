class Solution {
public:
    int lengthOfLongestSubstring(string s) {
               if(s.empty()) return 0;
        vector<int> indexMap(256,-1);
        indexMap[s[0]] = 0;
        int k = 1;
        int i = 0;
        int maxLen = 1;
        for(k; k < s.length(); k++) {
            if(indexMap[s[k]] != -1 && indexMap[s[k]] >= i) {
                i =max(i,  indexMap[s[k]] + 1);
                indexMap[s[k]] = k;
            } else {
                indexMap[s[k]] = k;
            }
                            maxLen = max(maxLen, k - i+ 1);

        }
        return maxLen;
    }
};
