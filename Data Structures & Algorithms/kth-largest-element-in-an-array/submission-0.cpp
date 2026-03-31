class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 2 3 1 5 4
        // 2 
        // 2 3
        // 2 3
        // 2 3 5
        // 3 5
        // 3 4 5
        // 4 5
        priority_queue<int,vector<int>, greater<int>> p;
        for(auto i : nums) {
            p.push(i);
            if(p.size() > k) {
                p.pop();
            }
        }
        return p.top();
    }
};
