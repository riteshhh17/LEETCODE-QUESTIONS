class Solution {
public:
    int numSquares(int n) {
        int a = sqrt(n);

        vector<int> vec;

        for (int i = 1; i <= a; i++) {
            vec.push_back(i * i);
        }

        int b = vec.size();

        vector<vector<int>> dp(b + 1, vector<int>(n + 1, INT_MAX));

        // Sum 0 needs 0 squares
        for (int i = 0; i <= b; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= n; j++) {

                
                dp[i][j] = dp[i - 1][j];

                
                if (vec[i - 1] <= j) {
                    dp[i][j] = min(
                        dp[i][j],
                        1 + dp[i][j - vec[i - 1]]
                    );
                }
            }
        }

        return dp[b][n];
    }
};