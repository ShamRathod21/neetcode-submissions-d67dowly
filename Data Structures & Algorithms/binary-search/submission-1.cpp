class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = n/2;
        while(left <= right) {
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right)/2;
        }
        return -1;
    }
};
