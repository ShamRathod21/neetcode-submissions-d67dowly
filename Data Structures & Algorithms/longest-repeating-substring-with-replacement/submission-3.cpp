class Solution {
public:
    // int conLength(string s, int k) { 
    //     vector<int> index;
    //     char ch = s[0];
    //     index.push_back(0);
    //     for(int i = 1; i < s.length(); i++) {
    //         if(ch != s[i]) {
    //             index.push_back(i);
    //             ch = s[i];
    //         }
    //     }
    //     int maxLen = 0;
    //     for(int i = 0; i < index.size(); i++) {
    //         char ch = s[index[i]];
    //         int k1 = k;
    //         int len = 0;
    //         int j = index[i];
    //         while(j < s.length()) { 
    //             if(ch == s[j]) {
    //                 len++;
    //                 j++;
    //             } else if(k1 > 0 && ch != s[j]) {
    //                 len++;
    //                 k1--;
    //                 j++;
    //             } else break;
    //         }
    //         maxLen = max(maxLen,len);
    //     }
    //     return maxLen;
    // }
    int maxFreq(int arr[]) {
        int maxNum = 0;
        for(int i = 0; i < 26 ; i++) {
            maxNum = max(maxNum,arr[i]);
        }
        return maxNum;
    }
    int characterReplacement(string s, int k) {
        // int len1 = conLength(s,k);
        // reverse(s.begin(),s.end());
        // int len2 = conLength(s,k);
        // return max(len1,len2);
        int count[26] = {0};
        int left = 0, right = 0;
        int maxLen = 0;
        while(right < s.length()) {
            count[s[right] - 'A']++;
            int maxNum = maxFreq(count);
            if(right - left + 1 - maxNum <= k) {
                int len = right - left + 1;
                maxLen = max(len,maxLen);
            } else {
                count[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return maxLen;
    }
};
