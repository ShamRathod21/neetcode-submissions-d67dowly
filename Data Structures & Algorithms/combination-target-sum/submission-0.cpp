class Solution {
public:
    vector<vector<int>> res;
    void generateArr(int index, int target, int sum, vector<int> &nums,vector<int> &s) {
        if(sum == target) {
            res.push_back(s);
            return;
        }
        if(sum > target || index >= nums.size())
            return;
        s.push_back(nums[index]);
        generateArr(index, target, nums[index]+ sum,nums,s);
        s.pop_back();
        generateArr(index+1, target, sum,nums,s);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        generateArr(0, target, 0, nums, cur);
        return res;
    }
};
