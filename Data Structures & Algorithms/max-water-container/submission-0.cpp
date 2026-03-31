class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int maxArea = 0;
        while(i < j) {
            maxArea = max(maxArea,min(heights[i],heights[j])*(j - i));
            heights[i] < heights[j] ? i++ : j--;
        }
        return maxArea;
    }
};
