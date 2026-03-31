class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int i = 0, j = heights.size() - 1;
        while(i < j) {
            int height = min(heights[i],heights[j]);
            int width = j - i;
            maxArea = max(maxArea, height*width);
            if(heights[i] < heights[j]) {
                i++;
            } else  {
                j--;
            }
        }
        return maxArea;

    }
};
