class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i =0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()) {
            res.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()) {
            res.push_back(nums2[j]);
            j++;
        }
        int med = res.size();
        return med%2 == 0 ? (res[(med/2)]+res[(med/2)-1])/(double)2 : res[ceil(med/2)];
    }
};
