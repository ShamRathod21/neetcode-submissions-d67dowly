class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> q;
        for(auto i : points) {
            int dist = pow(i[0],2) + pow(i[1],2);
            q.push(make_pair(dist,i));
            if(q.size() > k) {
                q.pop();
            }
        }
        vector<vector<int>> res;
        while(!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
