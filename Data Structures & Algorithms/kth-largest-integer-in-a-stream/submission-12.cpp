class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    // 1 2 3 4 5 6 7 k = 3 q size = 3
    // 1
    // 1 2
    // 1 2 3
    //  2 3 4
    //  3 4 5
    //  4 5 6
    //  5 6 7


    // 1 2 3 3  k = 3
    // 3 3 2 1
    // 3 3 3 2 1
    int k;
    KthLargest(int k, vector<int>& nums) {
        int i = 0;
        for(auto i : nums) {
            q.push(i);
            if(q.size() > k) {
                q.pop();
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};
