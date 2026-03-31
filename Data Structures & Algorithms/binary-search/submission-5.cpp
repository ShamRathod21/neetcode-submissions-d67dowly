class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(nums[mid] > target) {
                cout << "Index mid : " << mid << " LValue " << nums[mid] << endl;
                right = mid - 1;
            } else if(nums[mid] < target) {
                cout << "Index mid : " << mid << " RValue " << nums[mid] << endl;
                left = mid + 1;
            } else 
                return mid;
        }
        return -1;
    }
};
