class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto i : strs) {
            res += to_string(i.length()) + "#" + i;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()) {
            string len;
            while(s[i] != '#') {
                len += s[i];
                i++;
            }
            i++;
            int length = stoi(len);
            res.push_back(s.substr(i,length));
            i += length;
        }
        return res;
    }
};
