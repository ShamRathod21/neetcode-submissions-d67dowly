class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero = 0;
        for(auto i : nums) {
            if(i == 0) {
                zero++;
            } else {
                product *= i;
            }
        }
        if(zero > 1) {
            vector<int> temp(nums.size(),0);
            return temp;
        }
        vector<int> result;
        for(auto i : nums) {
           if(i == 0) {
            result.push_back(product);
           } else {
            if(zero == 1)
                result.push_back(0);
            else 
                result.push_back(product/i);
           }
        }
        return result;
    }
};
