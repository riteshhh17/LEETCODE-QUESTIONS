class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);
        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                int diff = nums[i] - nums[j];

                int prev = dp[j].count(diff) ? dp[j][diff] : 1;

                dp[i][diff] = max(dp[i][diff], prev + 1);

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};