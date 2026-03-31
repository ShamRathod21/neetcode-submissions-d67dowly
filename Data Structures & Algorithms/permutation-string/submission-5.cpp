class Solution {
public:
    bool matchArr(int arr1[],int arr2[]) {
        for(int i = 0; i < 26; i++) {
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};
        for(auto i : s1) {
            arr1[i - 'a']++;
        }
        bool match = false;
        int arr2[26] = {0};
        int r = s1.length(), l =0;
        for(int i = 0; i < s1.length(); i++) {
            arr2[s2[i]-'a']++;
        }
        if(matchArr(arr1,arr2))
            return true;
        for(int i = s1.length(); i < s2.length(); i++) {
            arr2[s2[l] - 'a']--;
            arr2[s2[r] - 'a']++;
            r++;
            l++;
            if(matchArr(arr1,arr2))
                    return true;
        }
        return false;    
    }
};
