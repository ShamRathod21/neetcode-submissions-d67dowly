class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int product = 1;
        // int zero = 0;
        // for(auto i : nums) {
        //     if(i == 0) {
        //         zero++;
        //     } else {
        //         product *= i;
        //     }
        // }
        // if(zero > 1) {
        //     vector<int> temp(nums.size(),0);
        //     return temp;
        // }
        // vector<int> result;
        // for(auto i : nums) {
        //    if(i == 0) {
        //     result.push_back(product);
        //    } else {
        //     if(zero == 1)
        //         result.push_back(0);
        //     else 
        //         result.push_back(product/i);
        //    }
        // }
        // return result;
        int n = nums.size();
        vector<int> prefix(n,1),postfix(n,1);
        prefix[0] = nums[0];
        postfix[n-1] = nums[n-1];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i]*prefix[i-1];
        }
        for(int i = n-2; i >= 0; i--) {
            postfix[i] = nums[i]*postfix[i+1];
        }
        vector<int> result(n,0);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                result[i] = postfix[i+1];
            } else if(i == n - 1) {
                 result[i] = prefix[i-1];
            } else {
                result[i] = prefix[i-1]*postfix[i+1];
            }
        }
        return result;

    }
};
