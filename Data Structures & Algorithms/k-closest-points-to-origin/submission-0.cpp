class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> p;
        for(auto i : points) {
            p.push(make_pair(i[0]*i[0]+i[1]*i[1],i));
            if(p.size() > k) {
                p.pop();
            }
        }
        vector<vector<int>> res;
        while(!p.empty()) {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};
