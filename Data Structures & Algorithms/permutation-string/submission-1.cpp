class Solution {
public:
    bool isString(int len, string s2, int i, int countFreq[]) {
        int count[26] = {0};
        if(s2.length() - i < len) {
            return false;
        }
        for(int j = 0; j < len; j++) {
            count[s2[i+j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            if(count[j] != countFreq[j])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int countFreq1[26] = {0};
        for(auto i : s1) {
            countFreq1[i - 'a']++;
        }
        for(int i = 0; i < s2.length(); i++) {
            if(countFreq1[s2[i] - 'a']) {
                if(isString(s1.length(),s2,i,countFreq1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
