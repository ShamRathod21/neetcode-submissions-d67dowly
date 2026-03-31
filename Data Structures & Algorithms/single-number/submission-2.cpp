class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(auto i : nums) {
            val ^= i;
        }
        return val;
    }
};
