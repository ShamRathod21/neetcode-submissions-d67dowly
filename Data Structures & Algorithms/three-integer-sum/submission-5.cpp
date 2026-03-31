class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> sres;
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int low = i+1;
            int high = nums.size()-1;
            while(low < high) {
                if(nums[low]+nums[high] == target) {
                    sres.insert({nums[low],nums[high],-target});
                    low++;
                }
                else if(nums[low]+nums[high] < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        vector<vector<int>> res(sres.begin(),sres.end());
        return res;
    }
};
