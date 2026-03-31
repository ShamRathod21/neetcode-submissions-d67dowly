class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Iterate through matrix
        // if a[i][j] == 1 then 
        //
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        int m = grid.size(), n = grid[0].size();
        int islandCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = 1;
                    q.push(make_pair(i,j));
                    while(!q.empty()) {
                        pair<int,int> node =  q.front();
                        q.pop();
                        // ->
                        if(node.second + 1 < n && !visited[node.first][node.second + 1] &&  grid[node.first][node.second + 1] == '1') {
                             visited[node.first][node.second + 1] = 1;
                            q.push(make_pair(node.first, node.second + 1));
                        }
                        // <-
                        if(node.second - 1 >= 0 && !visited[node.first][node.second - 1] &&  grid[node.first][node.second - 1] == '1') {
                            visited[node.first][node.second - 1] = 1;
                            q.push(make_pair(node.first, node.second - 1));
                        }
                        // ^
                        // |
                        if(node.first - 1 >= 0 && !visited[node.first - 1][node.second]&&  grid[node.first - 1][node.second] == '1') {
                            visited[node.first - 1][node.second] = 1;
                            q.push(make_pair(node.first - 1, node.second));
                        }
                        if(node.first + 1 < m && !visited[node.first + 1][node.second]  && grid[node.first + 1][node.second] == '1') {
                            visited[node.first + 1][node.second] = 1;
                            q.push(make_pair(node.first + 1, node.second));
                        }
                    }
                    islandCount++;
                }
            }
        }
        return islandCount;
        }
    };
