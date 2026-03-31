class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(),piles.end());
        int l = 1;
        int k;
        while(l <= r) {
            int mid = (l + r)/2;
            int totalTime = 0;
            for(auto i : piles) {
                totalTime += ceil(static_cast<double>(i)/mid);
            }
            if(totalTime <= h){
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;

    }
};
