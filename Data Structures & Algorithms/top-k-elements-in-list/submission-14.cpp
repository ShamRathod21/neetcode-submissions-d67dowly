class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(auto i : nums) {
            umap[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i : umap) {
            pq.push({i.second,i.first});
        }
        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
