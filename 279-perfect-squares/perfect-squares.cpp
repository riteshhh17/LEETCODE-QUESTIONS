class Solution {
public:
    int numSquares(int n) {
        int a = sqrt(n);

        vector<int> vec;
        for (int i = 1; i <= a; i++) {
            vec.push_back(i * i);
        }

        int b = vec.size();

        vector<vector<int>> dp(n + 1, vector<int>(b + 1, INT_MAX));

        // 0 sum requires 0 squares
        for (int j = 0; j <= b; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= b; j++) {

                
                dp[i][j] = dp[i][j - 1];

                
                if (vec[j - 1] <= i) {
                    dp[i][j] = min(
                        dp[i][j],
                        1 + dp[i - vec[j - 1]][j]
                    );
                }
            }
        }

        return dp[n][b];
    }
};