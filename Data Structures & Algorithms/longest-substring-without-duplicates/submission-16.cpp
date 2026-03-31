class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> count;
        int lastIndex = 0;
        int maxLen = 0;
        if(s.length() == 1) {
            return 1;
        }
        for(int i = 0; i < s.length(); i++) {
            if(count.find(s[i]) == count.end()) {
                count[s[i]] = i;
            } else {                
                maxLen = max(maxLen, i - lastIndex);
                if(s[i-1] == s[i]) {
                    lastIndex = i;
                } else {
                    lastIndex = lastIndex > count[s[i]] + 1 ? lastIndex : count[s[i]] + 1;
                }
                count[s[i]] = i;
            }
        }
        int last = s.length() - lastIndex;
        maxLen = max(maxLen, last);
        return maxLen;
    }
};
