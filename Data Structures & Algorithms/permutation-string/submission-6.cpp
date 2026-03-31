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
        int n1 = s1.length(), n2 = s2.length();

        if(n1 > n2)
            return false;
        
        int arr1[26] = {0};
        int arr2[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }

        if(matchArr(arr1,arr2))
            return true;
        
        for(int i = n1; i < s2.length(); i++) {
            arr2[s2[i - n1] - 'a']--;
            arr2[s2[i] - 'a']++;
            if(matchArr(arr1,arr2))
                return true;
        }
        return false;    
    }
};
