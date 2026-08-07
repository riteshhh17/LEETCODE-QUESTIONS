class Solution {
public:

    int solve(int i, int j, vector<int>& values,
              vector<vector<int>>& dp) {

        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k = i; k < j; k++) {

            int leftMax = 0;
            int rightMax = 0;

            for(int x = i; x <= k; x++)
                leftMax = max(leftMax, values[x]);

            for(int x = k+1; x <= j; x++)
                rightMax = max(rightMax, values[x]);


            int cost = solve(i,k,values,dp)
                     + solve(k+1,j,values,dp)
                     + leftMax * rightMax;


            ans = min(ans,cost);
        }

        return dp[i][j] = ans;
    }


    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n,
                               vector<int>(n,-1));

        return solve(0,n-1,arr,dp);
    }
};