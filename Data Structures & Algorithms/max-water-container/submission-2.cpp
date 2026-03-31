class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0, r = heights.size() - 1;
        int maxArea = 0;
        while(l < r) {
            int area = min(heights[l],heights[r])* (r - l);
            if(heights[l] < heights[r]) {
                l++;
            } else if(heights[l] > heights[r]) {
                r--;
            } else {
                l++,r--;
            }
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
