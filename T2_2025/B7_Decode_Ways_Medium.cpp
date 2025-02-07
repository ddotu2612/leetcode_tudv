// class Solution {
// public:
//     int numDecodings(string s) {
//         map<string, int> m;
//         for(int i = 1; i <= 26; i++) {
//             m[to_string(i)] = 1;
//         }
//         int res = 0;

//         Try(0, m, s, res);
//         return res;
//     }

//     void Try(int i, map<string, int> m, string s, int& res) {
//         int n = s.length();
//         if(i == n) res++;
//         if(m[s.substr(i, 1)] && i <= n - 1) Try(i + 1, m, s, res);
//         if(m[s.substr(i, 2)] && i <= n - 2) Try(i + 2, m, s, res);
//     }
// };
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2, 2));

            if (1 <= one && one <= 9) {
                dp[i] += dp[i - 1];
            }
            if (10 <= two && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];        
    }
};

