class Solution {
public:

    long long solve(vector<vector<long long>>& dp,
                    int m,
                    vector<vector<int>>& Grid) {

        dp[0][0] = Grid[0][0];

        for(int i = 1; i < m; i++) {

            for(int j = 0; j <= i; j++) {

            
                if(j == 0) {
                    dp[i][j] =
                        Grid[i][j] + dp[i-1][j];
                }

    
                else if(j == i) {
                    dp[i][j] =
                        Grid[i][j] + dp[i-1][j-1];
                }

        
                else {
                    dp[i][j] =
                        Grid[i][j] +
                        min(dp[i-1][j-1],
                            dp[i-1][j]);
                }
            }
        }

        long long ans = LLONG_MAX;

        for(int j = 0; j < m; j++) {
            ans = min(ans, dp[m-1][j]);
        }

        return ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        vector<vector<long long>> dp(
            m,
            vector<long long>(m, 0)
        );

        return solve(dp, m, triangle);
    }
};