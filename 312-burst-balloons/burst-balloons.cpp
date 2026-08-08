class Solution {
public:
    int solve(int i, int j, vector<int>& arr,
              vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {

            int cost = solve(i, k - 1, arr, dp)
                     + solve(k + 1, j, arr, dp)
                     + arr[i - 1] * arr[k] * arr[j + 1];

            ans = max(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {

        vector<int> arr;

        arr.push_back(1);

        for (int x : nums)
            arr.push_back(x);

        arr.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n + 2,
                               vector<int>(n + 2, -1));

        return solve(1, n, arr, dp);
    }
};