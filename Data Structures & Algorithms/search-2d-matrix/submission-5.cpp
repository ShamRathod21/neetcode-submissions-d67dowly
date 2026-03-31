class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix[0].size();
      int n = matrix.size();
      int left = 0, right = m*n - 1;
      while(left <= right) {
        int mid = (left + right) / 2;
        if(target == matrix[mid/m][mid%m]) {
            return true;
        } else  if(target < matrix[mid/m][mid%m]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
      }
      return false; 
    }
};
