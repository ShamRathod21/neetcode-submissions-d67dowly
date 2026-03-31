class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabetArray[26] = {0};
        if(s.length() != t.length()) {
            return false;
        }
        for(int i = 0; i < s.length(); i++) {
            alphabetArray[s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            alphabetArray[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(alphabetArray[i] != 0)
                return false;
        }
        return true;
    }
};
