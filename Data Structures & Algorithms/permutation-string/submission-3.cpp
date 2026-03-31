class Solution {
public:
    bool matchStr(string a, string b) {
        int arr[26] = {0};
        for(auto i : a) {
            arr[i - 'a']++;
        }
        for(auto i : b) {
            arr[i - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int arr[26] = {0};
        for(auto i : s1) {
            arr[i - 'a']++;
        }
        bool match = false;
        for(int i = 0; i < s2.length(); i++) {
            if(arr[s2[i] - 'a'] != 0 && s2.length() - i >= s1.length()) {
                match = matchStr(s1, s2.substr(i,s1.length()));
                if(match)
                    return true;
            }
        }
        return false;    
    }
};
