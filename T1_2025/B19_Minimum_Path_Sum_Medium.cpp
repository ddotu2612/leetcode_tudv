class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 201));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else if(i > 0 && j > 0) {
                    dp[i][j] = min(dp[i][j-1] + grid[i][j],dp[i-1][j] + grid[i][j]);
                } else if (i == 0) {
                    dp[0][j] = dp[0][j-1] + grid[0][j];
                } else {
                    dp[i][0] = dp[i-1][0] + grid[i][0];
                }
            }
        }

        return dp[n-1][m-1];
    }
};
