class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //    sort(nums.begin(),nums.end());
    //    set<int> s(nums.begin(),nums.end());
    //    int count = 0;
    //    int prev = 0;
    //    int count1 = 0;
    //    for(auto i : s) {
    //     if(count == 0) { 
    //         prev = i;
    //         count = 1;
    //         count1++;
    //     } else {
    //         if(i - prev == 1) {
    //             count1++;
    //         } else {
    //             count1 = 1;
    //         }
    //         prev = i;
    //         count = max(count,count1);
    //     }
    //    }
    //    return count;
    unordered_set<int> numSet(nums.begin(),nums.end());
    int count = 0;
    for(int n : numSet) {
        if (numSet.find(n - 1) == numSet.end()) {
        int length = 1;
        while(numSet.find(n+length) != numSet.end()) {
            length++;
        }
        count = max(count, length);
        }
        
    }
    return count;
    }
};
