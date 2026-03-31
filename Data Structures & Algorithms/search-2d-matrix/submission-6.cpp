class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix[0].size(),n = matrix.size();
      int i = 0, j = m*n - 1;
      while(i <= j) {
              int mid = (i + j)/2;

        int row = mid/m, col = mid%m;
        if(matrix[row][col] == target) {
            return true;
        } else if(target < matrix[row][col]) {
           j = mid - 1;
        } else {
            i = mid + 1;
        }
      }
      return false;
    }
};
