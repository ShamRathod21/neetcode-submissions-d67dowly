class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0;
        int high = heights.size() - 1;
        int maxArea = 0;
        while(low < high) {
            int area = min(heights[low],heights[high])*(high-low);
            maxArea = max(area,maxArea);
            if(heights[low] < heights[high]){
                low++;
            } else if(heights[low] > heights[high]) {
                high--;
            } else {
                low++,high--;
            }
        }
        return maxArea;
    }
};
