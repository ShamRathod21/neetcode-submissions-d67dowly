class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(auto i : strs) {
            result += to_string(i.length());
            result += "#";
            result += i;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp, len;
        int i = 0;
        while(i < s.length()) {
            while(s[i] != '#') {
                len += s[i];
                i++;
            }
            i++;
            for(int j = 0; j < stoi(len); j++) {
                temp += s[i];
                i++;
            }
            result.push_back(temp);
            temp = "";
            len = "";
        }
        return result;
    }
};
