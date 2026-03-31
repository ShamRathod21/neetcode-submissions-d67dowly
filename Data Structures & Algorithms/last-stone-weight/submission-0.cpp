class Solution {
public:
    priority_queue<int> q;
    void init(vector<int> stones) {
        for(auto i : stones) {
            q.push(i);
        }
    }
    int lastStoneWeight(vector<int>& stones) {
        init(stones);
        while(q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            y = abs(x-y);
            if(y != 0) {
                q.push(y);
            }
        }
        if(q.size() == 1)
            return q.top();
        return 0;
    }
};
