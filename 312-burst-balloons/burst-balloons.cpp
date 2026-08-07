class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        arr.push_back(1);

        for (int x : nums)
            arr.push_back(x);

        arr.push_back(1);

        int m = arr.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        
        for (int len = 1; len <= n; len++) {

            for (int i = 1; i + len - 1 <= n; i++) {

                int j = i + len - 1;

                for (int k = i; k <= j; k++) {

                    int cost = dp[i][k - 1]
                             + dp[k + 1][j]
                             + arr[i - 1] * arr[k] * arr[j + 1];

                    dp[i][j] = max(dp[i][j], cost);
                }
            }
        }

        return dp[1][n];
    }
};