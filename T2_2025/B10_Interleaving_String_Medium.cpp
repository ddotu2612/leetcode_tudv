class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if(n + m != l) return false;

        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        dp[0][0]  = true;

        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1];
        }
        for(int j = 1; j <= m; j++){
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[n][m];
    }
};
