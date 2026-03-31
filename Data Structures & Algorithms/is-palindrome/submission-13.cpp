class Solution {
public:

    bool isAlphaNum(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(!isAlphaNum(s[i]) && i < j) {
                i++;
            }
            char leftChar = s[i];
            while(!isAlphaNum(s[j]) && i < j) {
                j--;
            }
            char rightChar = s[j];
            // Convert to lowercase for comparison
            if(leftChar >= 'A' && leftChar <= 'Z') {
                leftChar = leftChar + 32; // Convert to lowercase
            }
            if(rightChar >= 'A' && rightChar <= 'Z') {
                rightChar = rightChar + 32; // Convert to lowercase
            }
            
            // Check if characters match
            if(leftChar != rightChar) {
                return false;
            }
            
            // IMPORTANT: Move pointers forward
            i++;
            j--;
        }
        return true;
    }

};
