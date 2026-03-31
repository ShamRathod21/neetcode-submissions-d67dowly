class Solution {
public:
    bool isAlphaDigit(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right ) {
            while(left < s.length() && !isAlphaDigit(s[left]) ) {
                left++;
            }
            while(right > 0 && !isAlphaDigit(s[right]) ) {
                right--;
            }
               if(tolower(s[left]) != tolower(s[right]) && left < right) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};
