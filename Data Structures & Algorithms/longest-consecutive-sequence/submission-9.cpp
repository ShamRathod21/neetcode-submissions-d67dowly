class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> umap;
        for(auto i : nums) {
            umap[i] = false;
        }
        int count = 0;
        for(auto i : nums) {
            int k = i;
            int value = 0;
            while(umap.find(k) != umap.end() ) {
                value++;
                // umap[k] = true;
                k++;
            }
            count = max(count,value);
        }
        return count;
    }
};
