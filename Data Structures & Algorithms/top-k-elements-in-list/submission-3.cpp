class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> map1;
       map<int,vector<int>> revMap;
       for(auto i : nums) {
        map1[i]++;
       }
       for(auto i : map1) {
        revMap[i.second].push_back(i.first);
       }
       vector<int> result;
       int count = 0;
       for(auto it = revMap.rbegin(); it != revMap.rend(); it++) {
        vector<int> temp = it->second;
        if(count < k) {
            for(auto i : temp)
            {
                result.push_back(i);
                count++;
            }
        }
       }
       return result;
    }
};
