class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        if(stones.size() < 2)
            return stones[0];
        for(auto i : stones)
            q.push(i);
        while(q.size() != 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push(abs(y-x));
        }
        return q.top();
    }
};
