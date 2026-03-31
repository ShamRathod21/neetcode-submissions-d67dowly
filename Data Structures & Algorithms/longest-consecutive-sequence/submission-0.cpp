class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       set<int> s(nums.begin(),nums.end());
       int count = 0;
       int prev = 0;
       int count1 = 0;
       for(auto i : s) {
        if(count == 0) { 
            prev = i;
            count = 1;
            count1++;
        } else {
            if(i - prev == 1) {
                count1++;
            } else {
                count1 = 1;
            }
            prev = i;
            count = max(count,count1);
        }
       }
       return count;
    }
};
