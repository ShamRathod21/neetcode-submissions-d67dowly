class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> res;
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i+1; j < nums.size(); j++) {
        //         if(nums[i]+nums[j] == target && i != j) {
        //             res.push_back(i);
        //             res.push_back(j);
        //         }
        //     }
        // }
        // return res;
        unordered_map<int,int> umap;
        for(int i = 0; i < nums.size(); i++) {
            if(umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
