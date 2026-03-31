class Solution {
public:
    bool isAnagram(string s, string t) {
        int countArray[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            countArray[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            countArray[t[i] - 'a']--;
        }
        for(int i = 0; i < 26 ; i++) {
            if(countArray[i] != 0) {
                return false;
            }
        }
        return true;
       
    }
};
