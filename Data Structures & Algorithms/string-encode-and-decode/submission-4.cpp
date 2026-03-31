class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto i : strs) {
            int len = i.length();
            res += to_string(len) + "#" + i;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        string len;
        vector<string> res;
        while(i < s.length()) {
            if(s[i] != '#') {
                len += s[i];
                i++;
            } else {
                int length = stoi(len);
                // Move i past the '#' to the start of the actual string
                i++; 
                // Use 'length' as the second parameter for substr
                res.push_back(s.substr(i, length));
                // Move i forward by the length of the string
                i += length;
                // Reset len for the next word
                len = "";
            }
        }
        return res;
    }
};
