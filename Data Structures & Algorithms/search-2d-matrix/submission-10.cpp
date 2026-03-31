class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size(), n = matrix.size();
        int l = 0, r = m*n - 1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(matrix[mid/m][mid%m] == target) {
                return true;
            } else if (matrix[mid/m][mid%m] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
