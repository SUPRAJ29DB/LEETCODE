class Solution {
public:

    vector<string> ans;

    bool valid(string s) {

        // Leading zero
        if (s.size() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void solve(int i, int parts, string &s, string temp) {

        // 4 parts formed
        if (parts == 4) {

            if (i == s.size()) {

                temp.pop_back();      // Remove last '.'
                ans.push_back(temp);
            }

            return;
        }

        // Generate substring of length 1,2,3
        for (int len = 1; len <= 3; len++) {

            if (i + len > s.size())
                break;

            string part = s.substr(i, len);

            if (valid(part)) {

                solve(i + len,
                      parts + 1,
                      s,
                      temp + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(0, 0, s, "");

        return ans;
    }
};