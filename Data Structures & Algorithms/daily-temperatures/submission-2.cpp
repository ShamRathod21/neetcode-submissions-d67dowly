class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> sp;
        for(int i = 0; i < n; i++) {
            if(sp.empty()) {
                sp.push(make_pair(temperatures[i],i));
            } else {
                pair<int,int> temp = sp.top();
                if(temp.first >= temperatures[i]) {
                    sp.push(make_pair(temperatures[i],i));
                } else {
                    while(temp.first < temperatures[i] && !sp.empty()) {
                        res[temp.second] = i - temp.second;
                        sp.pop();
                        if(!sp.empty()) {
                            temp = sp.top();
                        }
                    }
                    sp.push(make_pair(temperatures[i],i));
                }
            }
        }
        return res;
    }
};
