class Solution {
public:

    long long solve(vector<vector<long long>>& dp,
                    int m,
                    int n,
                    vector<vector<int>>& Grid) {

        dp[m-1][n-1] = Grid[m-1][n-1];

        for(int i = m-1; i >= 0; i--) {

            for(int j = n-1; j >= 0; j--) {

                if(i == m-1 && j == n-1)
                    continue;

                if(i == m-1) {
                
                    dp[i][j] = Grid[i][j] + dp[i][j+1];
                }
                else if(j == n-1) {
                
                    dp[i][j] = Grid[i][j] + dp[i+1][j];
                }
                else {
                    // Both directions available
                    dp[i][j] = Grid[i][j] +
                               min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(
            m,
            vector<long long>(n, 0)
        );

        return solve(dp, m, n, grid);
    }
};
