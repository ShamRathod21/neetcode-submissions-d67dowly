class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1), postfix(n,1);
        prefix[0] = nums[0];
        postfix[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1]*nums[i];
            postfix[n-i-1] = postfix[n-i]*nums[n-i-1];
        }
        vector<int> prod;
        prod.push_back(postfix[1]);
        for(int i = 1; i < n - 1; i++) {
            prod.push_back(prefix[i-1]*postfix[i+1]);
        }
        prod.push_back(prefix[n-2]);
        return prod; 
    }
};
