class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[255];
        fill(arr,arr+255,-1);
        int len = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            if(arr[s[r]] != -1) {
                l = max(l, arr[s[r]]+1);
            }
            len = max(len, r - l + 1);
            arr[s[r]] = r;
        }
        return len;
    }
};
