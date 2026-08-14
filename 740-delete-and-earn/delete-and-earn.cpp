class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> points(mx + 1, 0);

        // Calculate total points for each number
        for(int x : nums) {
            points[x] += x;
        }

        // House Robber DP
        vector<int> dp(mx + 1, 0);

        dp[0] = 0;
        if(mx >= 1)
            dp[1] = points[1];

        for(int i = 2; i <= mx; i++) {
            dp[i] = max(dp[i-1], points[i] + dp[i-2]);
        }

        return dp[mx];
    }
};