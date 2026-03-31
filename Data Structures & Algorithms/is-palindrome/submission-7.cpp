class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(auto i : s) {
            if(isalnum(i)) {
                temp+= tolower(i);
            }
        } 
        int i = 0, j = temp.length() - 1;

        while(i < j) {
            
            if(tolower(temp[i]) != tolower(temp[j]))
            {
                // cout << "s[i]" << s[i] << " s[j]" << s[j] <<endl;
                return false;
            }
            i++,j--;
            
        }
        return true;
    }
};
