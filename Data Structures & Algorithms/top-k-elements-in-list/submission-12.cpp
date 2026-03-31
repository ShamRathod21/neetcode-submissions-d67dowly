class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(auto i : nums) {
            umap[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i : umap) {
            pq.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        while(!pq.empty() && k > 0) {
            int top = pq.top().second;
            pq.pop();
            k--;
            res.push_back(top);
        }
        return res;

    }
};
