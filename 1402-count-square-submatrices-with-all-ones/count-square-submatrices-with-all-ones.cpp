class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 1) {
                
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 1 + min({
                            dp[i-1][j],
                            dp[i][j-1],
                            dp[i-1][j-1]
                        });
                    }
                    ans=ans+dp[i][j];

                
                }
            }
        }

        return ans;
    }

    int countSquares(vector<vector<int>>& matrix) {
         int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        return solve(m, n, matrix, dp);
        
    }
};
