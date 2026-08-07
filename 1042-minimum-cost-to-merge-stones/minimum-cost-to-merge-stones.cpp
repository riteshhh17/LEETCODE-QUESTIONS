class Solution {
public:

    int solve(int i, int j, vector<int>& stones,
              vector<vector<int>>& dp,
              vector<int>& prefix, int K) {

        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int mid = i; mid < j; mid += K - 1) {

            int left = solve(i, mid, stones, dp, prefix, K);
            int right = solve(mid + 1, j, stones, dp, prefix, K);

            if (left == INT_MAX || right == INT_MAX)
                continue;

            int cost = left + right;

            // Can this interval be merged into one pile?
            if ((j - i) % (K - 1) == 0) {
                cost += prefix[j + 1] - prefix[i];
            }

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }


    int mergeStones(vector<int>& stones, int K) {

        int n = stones.size();

        if ((n - 1) % (K - 1) != 0)
            return -1;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = solve(0, n - 1, stones, dp, prefix, K);

        return ans;
    }
};