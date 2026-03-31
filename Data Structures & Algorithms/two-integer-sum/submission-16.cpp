class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i = 0; i < nums.size();i++) {
            umap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(umap.find(target - nums[i]) != umap.end() && umap[target - nums[i]] != i) {
                return {i, umap[target - nums[i]]};
            }
            
        }
        return {-1,-1};
    }
};
