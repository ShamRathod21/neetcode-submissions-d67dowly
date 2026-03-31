class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        for(auto i : nums) {
            m[i]++;
        }
        for(auto i : m) {
            pq.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        for(int i = 0 ; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
