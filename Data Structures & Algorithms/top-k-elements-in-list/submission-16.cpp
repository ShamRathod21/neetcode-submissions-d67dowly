class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        for(auto i : mp) {
            q.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
