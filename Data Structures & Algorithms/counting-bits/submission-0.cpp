class Solution {
public:
int count(int n) {
    int count = 0;
    while(n) {
        count += (n&1);
        n = n >> 1;
    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            res.push_back(count(i));
        }
        return res;
    }
};
