class Solution {
public:
    int countBit(int val) {
        int count = 0;
        while(val != 0) {
            count += (val & 1);
            val = val >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            res.push_back(countBit(i));
        }
        return res;
    }
};
