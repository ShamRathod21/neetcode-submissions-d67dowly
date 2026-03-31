class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int val = size;
        for(int i = 0; i < size; i++) {
            val ^= i ^ nums[i];
        }
        return val;
    }
};
