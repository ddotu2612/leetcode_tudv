class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> comb;
        Try(1, 0, s, comb, res);
        return res;
    }

    void Try(int i, int j, string s, vector<string>& comb, vector<string>& res) {
        int n = s.length();
        if(i == 5 && j == n) {
            string temp = "";
            for(int k = 0; k < 4; k++) {
                if(k < 3) {
                    temp = temp + comb[k] + ".";
                } else {
                    temp = temp + comb[k];
                }
            }
            res.push_back(temp);
        }
        if(i == 5 && j < n) return;
        if(j < n && stoi(s.substr(j, 1)) >= 0 && stoi(s.substr(j, 1)) <= 255) {
            comb.push_back(s.substr(j, 1));
            Try(i + 1, j + 1, s, comb , res);
            comb.pop_back();
        }
        if(j < n - 1 && s[j] != '0' && stoi(s.substr(j, 2)) >= 0 && stoi(s.substr(j, 2)) <= 255) {
            comb.push_back(s.substr(j, 2));
            Try(i + 1, j + 2, s, comb , res);
            comb.pop_back();
        }
        if(j < n - 2 && s[j] != '0' && stoi(s.substr(j, 3)) >= 0 && stoi(s.substr(j, 3)) <= 255) {
            comb.push_back(s.substr(j, 3));
            Try(i + 1, j + 3, s, comb , res);
            comb.pop_back();
        }
    }
};
