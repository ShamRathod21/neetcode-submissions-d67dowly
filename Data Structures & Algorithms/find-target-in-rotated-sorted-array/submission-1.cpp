class Solution {
public:
    int search(vector<int>& a, int target) {
        int l = 0, r = a.size() - 1;
        while(l <= r) {

            int mid = l + (r - l)/2;
            if(a[mid] == target) {
                return mid;
            }
            // left sorted array
            if(a[mid] >= a[l]) {
                if(target > a[mid] || target < a[l]) {
                    l = mid+1;
                } else 
                    r = mid - 1;
            } else {
                if(target < a[mid] || target > a[r]) {
                    r = mid - 1;
                } else 
                    l = mid+1;

            }
        }
        return -1;
    }
};
