class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxLen = 0;
       int l = 0;
       unordered_map<char,int> mp;
       for(int r = 0; r < s.length(); r++) {
            if(mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1,l);
            }
            mp[s[r]] = r;
            maxLen = max(maxLen, r-l +1);
       }
       return maxLen;
    }
};
