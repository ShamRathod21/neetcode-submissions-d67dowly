class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto i : nums){
            int idx = abs(i) - 1;
            if(nums[idx] < 0){
                return idx+1;
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};
