class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int arr[255];
        fill(arr, arr + 255 ,-1);
        int len = 0;
        for(r; r < s.length(); r++) {
            if(arr[s[r]] != -1) {
                l = max(l,arr[s[r]]+1);
            }
            len = max(r-l+1,len);
                        arr[s[r]] = r;

        }
        return len;
    }
};
