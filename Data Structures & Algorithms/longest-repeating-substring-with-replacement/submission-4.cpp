class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            unordered_map<char,int> up;
            int maxf = 0;
            for(int j = i; j < s.length(); j++) {
                up[s[j]]++;
                maxf = max(up[s[j]],maxf);
                if((j-i+1) - maxf <= k) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
