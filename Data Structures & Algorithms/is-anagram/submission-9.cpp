class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(auto i : s) {
            arr[i - 'a']++;
        }
        for(auto i : t) {
            arr[i - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};
