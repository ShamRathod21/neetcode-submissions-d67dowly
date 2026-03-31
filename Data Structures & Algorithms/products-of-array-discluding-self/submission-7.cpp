class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lprod,rprod(nums.size(),0);
        lprod.push_back(nums[0]);
        rprod[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++) {
            lprod.push_back(lprod[i-1]*nums[i]);
        }
        for(int i = nums.size() - 2; i > 0; i--) {
            rprod[i] = (rprod[i+1]*nums[i]);
        }
        vector<int> res;
        res.push_back(rprod[1]);
        for(int i = 1; i < nums.size() - 1; i++) {
            res.push_back(lprod[i-1]*rprod[i+1]);
        }
                res.push_back(lprod[nums.size() - 2]);
                return res;

    }
};
