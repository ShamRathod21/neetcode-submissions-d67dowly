class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(auto i : nums) {
            umap[i]++;
        }
        vector<pair<int,int>> arr;
        for(auto i : umap) {
            arr.push_back({i.second,i.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(arr[i].second);
        }
        return result;
    }
};
