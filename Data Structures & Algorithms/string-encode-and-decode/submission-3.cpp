class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for(auto i : strs) {
            int len = i.length();
            enc += to_string(len) + "*" + i;
        }
        return enc;
    }

    vector<string> decode(string s) {
        string length;
        vector<string> res;
        int i = 0;
        while(i < s.length()) {
            while(s[i] != '*' && i < s.length()) {
                length += s[i];
                i++;
            }
            int len = stoi(length);
            length.clear();
            // for '*'
            i++;
            res.push_back(s.substr(i,len));
            i += len;
        }
        return res;
    }
};
