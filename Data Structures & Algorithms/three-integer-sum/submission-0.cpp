class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> numSet;
        int target = 0;
        for(int i = 0; i < nums.size(); i++) {
            target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                if(nums[j] + nums[k] < target) {
                    j++;
                } else if(nums[j] + nums[k] > target) {
                    k--;
                } else {
                    numSet.insert({nums[j],nums[k],-target});
                    k--,j++;
                }
            }
        }
        return vector<vector<int>>(numSet.begin(),numSet.end());
    }
};
