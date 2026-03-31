class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m,vector<bool>(n,false));
        queue<pair<int,int>> gridQ;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    gridQ.push(make_pair(i,j));
                    visited[i][j] = true;
                }
            }
        }
        while(!gridQ.empty()) {
            pair<int,int> node = gridQ.front();
            gridQ.pop();
            // ->
            if(node.second + 1 < n && grid[node.first][node.second + 1] != -1 && !visited[node.first][node.second + 1]) {
                gridQ.push(make_pair(node.first,node.second+1));
                visited[node.first][node.second + 1] = true;
                grid[node.first][node.second + 1] = grid[node.first][node.second] + 1;
            }
            // <-
            if(node.second - 1 >= 0 && grid[node.first][node.second - 1] != -1 && !visited[node.first][node.second - 1]) {
                gridQ.push(make_pair(node.first,node.second-1));

                visited[node.first][node.second - 1] = true;
                grid[node.first][node.second - 1] = grid[node.first][node.second] + 1;
            }
            if(node.first - 1 >= 0 && grid[node.first - 1][node.second] != -1 && !visited[node.first - 1][node.second]) {
                gridQ.push(make_pair(node.first - 1,node.second));

                visited[node.first- 1][node.second ] = true;
                grid[node.first- 1][node.second] = grid[node.first][node.second] + 1;
            }
            if(node.first + 1 < m && grid[node.first + 1][node.second] != -1 && !visited[node.first  + 1][node.second]) {
                gridQ.push(make_pair(node.first + 1,node.second));

                visited[node.first + 1][node.second] = true;
                grid[node.first + 1][node.second] = grid[node.first][node.second] + 1;
            }
        }
    }
};
