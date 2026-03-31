class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t res = 0;
       int i = 0;
       while(n != 0) {
        int bit = n & 1;
        cout << bit << endl;
        res = res | bit << (31 - i);
        std::cout << std::bitset<32>(res) << std::endl;
        i++;
        n = n >> 1;
       } 
       std::cout << std::bitset<32>(res) << std::endl;
       return res;
    }
};
