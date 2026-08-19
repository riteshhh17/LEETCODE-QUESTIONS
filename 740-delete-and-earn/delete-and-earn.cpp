class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    int a= *max_element(nums.begin(),nums.end());
    vector<int>vec(a+1);
    vector<int>dp(a+1,0);
    for(int val:nums){
        vec[val]+=val;
    }  
    dp[1]=vec[1];
    for(int i=2;i<=a;i++){
        dp[i]=max(dp[i-2]+vec[i], dp[i-1]);


    }
        
       return dp[a]; 
    }
};