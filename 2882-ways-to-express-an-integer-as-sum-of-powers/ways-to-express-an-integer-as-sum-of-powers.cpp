class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        vector<int> nums;


        for(long long i = 1; ; i++) {
            long long val = 1;

            for(int j = 0; j < x; j++) {
                val *= i;
                if(val > n) break;
            }

            if(val > n) break;

            nums.push_back((int)val);
        }

        int m = nums.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= m; i++) {
            for(int sum = 0; sum <= n; sum++) {

               
                dp[i][sum] = dp[i-1][sum];

                if(sum >= nums[i-1]) {
                    dp[i][sum] =
                        (dp[i][sum] + dp[i-1][sum - nums[i-1]]) % MOD;
                }
            }
        }

        return dp[m][n];
    }
};