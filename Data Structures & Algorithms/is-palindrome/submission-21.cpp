class Solution {
public:
    
    bool isPalindrome(string s) {
        int len = s.length();
        int low = 0, high = len - 1;
        while(low < high) {
            while(low < high && !isalnum(s[low])) {
                low++;
            }
            while(high > low && !isalnum(s[high])) {
                high--;
            }
            if(low > high) {
                return true;
            }
            char lh = tolower(s[low]);
            char sh = tolower(s[high]);
            if(lh != sh)
                return false;
            low++;
            high--;
        }
        return true;
    }
};
