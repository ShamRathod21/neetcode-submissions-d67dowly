class Solution {
public:
 //   4 5 6 7 1 2
    int binarySearch(vector<int> res, int l,int r,int target) {
        while(l <= r) {
            int mid = (l + r)/2;
            if(res[mid] == target) {
                return mid;
            } else if(res[mid] < target) {
                l = mid + 1;
            } else 
                r = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r)/2;
            if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int pivot = l;
        int index = binarySearch(nums,0,pivot - 1,target);
        index = index == -1 ? binarySearch(nums,pivot,nums.size() - 1,target) : index;
        return index;
    }
};
