class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        priority_queue<pair<int,int>>pq;
        for(auto i : nums) {
            umap[i]++;
        }
        for(auto i : umap) {
            pq.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            pair<int,int> mp = pq.top();
            pq.pop();
            res.push_back(mp.second);
        }
        return res;

    }
};
