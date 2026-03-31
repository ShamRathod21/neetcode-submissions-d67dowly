class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size,1),postfix(size,1);
        prefix[0] = nums[0];
        postfix[size - 1] = nums[size - 1];
        
        for(int i = 1; i < size; i++) {
            prefix[i] =  nums[i]*prefix[i - 1];
            postfix[size - i - 1] =  nums[size - i - 1]*postfix[size - i];
        }
        vector<int> result(size,0);
        for(int i = 0; i < size; i++) {
            if(i == 0) {
                result[i] = postfix[i+1];
            } else if(i == size - 1) {
                 result[i] = prefix[i-1];
            } else {
                result[i] = prefix[i-1]*postfix[i+1];
            }
        }
        return result;
    }
};
