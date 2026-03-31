class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int r = 0; r < nums.size(); r++) {
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);
             if(r >= k - 1)
                res.push_back(nums[q.front()]);
            if(r-k+1 == q.front()) {
                q.pop_front();
            }
           
        }
        return res;
    }
};
