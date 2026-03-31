class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = *max_element(piles.begin(),piles.end());
        for(int i = 1; i <= maxK; i++) {
            long long hr = 0;
            for(int j = 0; j < piles.size(); j++) {
                hr += ceil((double)piles[j]/i);
            }
            if(hr <= h) {
                return i;
            }
        }
        return -1;
    }
};
