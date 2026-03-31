class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> dupSet(nums.begin(), nums.end());
        return nums.size() != dupSet.size();
    }
};