class Solution {
    public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        int res = right;
        while(left <= right) {
            long long hour = 0;
            int mid = floor((left + right)/2);
            for(int i : piles) {
                hour += ceil(static_cast<double>(i)/mid);
            }
            if(hour <= h) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};
