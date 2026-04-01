class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if(q.size() > k)
                q.pop();
        }
        K = k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > K) 
            q.pop();
        return q.top();
    }
};
