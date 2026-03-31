class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = *max_element(piles.begin(),piles.end());
        int low = 1, high = maxK;
        int ans = 1;
        while(low <= high) {
            int mid = (low + (high - low)/2);
            long long hr = 0;
            for(int j = 0; j < piles.size(); j++) {
                hr += ceil((double)piles[j]/mid);
            }
            if(hr <= h) {
                ans = mid;
                high = mid - 1;
                
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};
