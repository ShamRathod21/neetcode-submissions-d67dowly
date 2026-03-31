class Solution {
public:
    int characterReplacement(string str, int k) {
        int res = 0;
        set<char> s(str.begin(),str.end());
        for(auto i : s) {
            int l = 0; 
            int count = 0;
            int r = 0;
            while(r < str.length()) {
                if(str[r] == i) {
                    count++;
                }
                while ((r - l + 1) - count > k) {
                    if (str[l] == i) {
                        count--;
                    }
                    l++;
                }

                res = std::max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};
