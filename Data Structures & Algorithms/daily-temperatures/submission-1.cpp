class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        int n = temperatures.size();
        for(int i = 0; i < n; i++) {
            int j = i+1;
            while(temperatures[i] >= temperatures[j] && j < n) {
                j++;
            }
            if(j != n) 
             res.push_back(j-i);
            else res.push_back(0);
        }
        return res;
    }
};
