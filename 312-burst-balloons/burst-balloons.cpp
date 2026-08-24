class Solution {
public:
    int solve(int i,int j,vector<int>&vec,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];


        }
        int result=0;
        for(int k=i;k<=j;k++){
            int ans=solve(i,k-1,vec,dp)+solve(k+1,j,vec,dp)+
                    vec[i-1]*vec[k]*vec[j+1];
            result=max(ans,result);
                  
        }
        dp[i][j]=result;
        return dp[i][j];
       

    }
    int maxCoins(vector<int>& nums) {
        vector<int>vec;
        vec.push_back(1);
        for(int val:nums){
            vec.push_back(val);
        }
        vec.push_back(1);
        vector<vector<int>>dp(vec.size()+2,vector<int>(vec.size()+2,-1));
         return solve(1,vec.size()-2,vec,dp);


    }
};