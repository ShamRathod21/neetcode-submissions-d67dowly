class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> que;
       unordered_map<int,int> umap;
       for(auto i : nums) {
        umap[i]++;
       }
       for(auto i : umap) {
        que.push({i.second,i.first});
       }
        vector<int> res;
        while(k > 0) {
            res.push_back(que.top().second);
            que.pop();
            k--;
        }
        return res;
    }
};
