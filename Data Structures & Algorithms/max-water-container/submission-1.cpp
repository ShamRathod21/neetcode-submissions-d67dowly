class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int area = 0;
        while(i < j) {
            int tempArea = (j - i)*min(heights[i],heights[j]);
            if(heights[i] < heights[j]) {
                i++;
            } else 
                j--;
            area = max(area,tempArea);
        }
        return area;
    }
};
