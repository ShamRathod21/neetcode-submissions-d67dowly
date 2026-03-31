class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1 = nums1.size(), n2 = nums2.size();
        int i =0, j = 0;
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1 ) {
            res.push_back(nums1[i]);
            i++;
        }
        while(j < n2) {
            res.push_back(nums2[j]);
            j++;
        }
        if(res.size()%2) {
            int med = res.size()/2;
            return (double)res[med];
        } else {
            int med = res.size()/2;
            cout << res[med] << " " << res[med - 1];
            return (double)((res[med]+res[med - 1])/(double)2);
        }


    }
};
