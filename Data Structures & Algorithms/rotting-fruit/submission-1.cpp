class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int min = 0;
        while(fresh > 0 && !q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                pair<int,int> node = q.front();
                q.pop();
            if(node.second + 1 < n && !visited[node.first][node.second + 1] && grid[node.first][node.second + 1] != 0) {
                q.push(make_pair(node.first, node.second + 1));
                grid[node.first][node.second + 1] = 2;
                visited[node.first][node.second + 1] = true;
                fresh--;
            }
            if(node.second - 1 >= 0 && !visited[node.first][node.second - 1] && grid[node.first][node.second - 1] != 0) {
                q.push(make_pair(node.first, node.second - 1));
                grid[node.first][node.second - 1] = 2;
                visited[node.first][node.second - 1] = true;
                                fresh--;

            }
            if(node.first + 1 < m && !visited[node.first+ 1][node.second] && grid[node.first+ 1][node.second] != 0) {
                q.push(make_pair(node.first + 1, node.second) );
                grid[node.first + 1][node.second] = 2;
                visited[node.first + 1][node.second] = true;
                                fresh--;

            }
            if(node.first - 1 >= 0 && !visited[node.first - 1][node.second] && grid[node.first - 1][node.second] != 0) {
                q.push(make_pair(node.first - 1, node.second));
                grid[node.first - 1][node.second] = 2;
                visited[node.first - 1][node.second] = true;
                                fresh--;

            }
            }
            min++;
        }
        return fresh == 0 ? min : -1;
    }
};
