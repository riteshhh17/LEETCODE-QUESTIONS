class Solution {
public:
    int solve(vector<vector<long long>>&dp,int m,int n,vector<vector<int>>&Grid){
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    continue;
                }
                if(Grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                    
                }
                
                if(i+1 < m)
                    dp[i][j] += dp[i+1][j];

                if(j+1 < n)
                    dp[i][j] += dp[i][j+1];
            }
        }
         return dp[0][0];
        
        
        

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<long long>>dp(m,vector<long long>(n,0));
        
         return solve(dp,m,n,obstacleGrid);
        
    }
};
