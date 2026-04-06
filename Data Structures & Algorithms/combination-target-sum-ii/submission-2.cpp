class Solution {
public:
    set<vector<int>> s;
    void backTrack(int index,int sum, int target, vector<int> &nums, vector<int>& curr) {
        if(sum == target) {
            s.insert(curr);
            return;
        }
        if(sum > target || index >= nums.size()) {
            return;
        }
        // choose 
        curr.push_back(nums[index]);
        backTrack(index+1, nums[index]+sum, target,nums,curr);
        // unchoose
        curr.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        backTrack(index+1, sum, target, nums, curr);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backTrack(0,0,target,candidates,curr);
        vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};
