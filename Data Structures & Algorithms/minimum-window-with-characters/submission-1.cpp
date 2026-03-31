class Solution {
public:
    
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        unordered_map<char,int> srcMap,tarMap;
        for(auto i : t) {
            tarMap[i]++;
        }
        int need = tarMap.size();
        int have = 0;
        int l = 0;
        int minLen = INT_MAX;
        int startIndex = 0;
        for(int r = 0; r < s.length(); r++) {
            // Expand
            srcMap[s[r]]++;
            if(srcMap[s[r]] == tarMap[s[r]]) {
                have++;
            }
            // Shrink 
            while(have == need) {
                int newMinLen = min(minLen, r - l + 1);
                if(newMinLen != minLen) {
                    startIndex = l;
                    minLen = newMinLen;
                }
                if(srcMap[s[l]] == tarMap[s[l]]) {
                    have--;
                }
                srcMap[s[l]]--;
                l++;
                
            }
        }
        if(minLen == INT_MAX)  return "";
        else return s.substr(startIndex,minLen);

    }
};
