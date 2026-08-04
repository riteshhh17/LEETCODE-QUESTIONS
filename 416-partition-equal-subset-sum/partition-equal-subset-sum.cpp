class Solution {
public:
    bool solution(vector<int>&nums,int target,vector<vector<bool>>&vec,int n){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0){
                    vec[i][j]=false;
                }
                if(j==0) vec[i][j]=true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(j>=nums[i-1]){
                    vec[i][j]= vec[i-1][j-nums[i-1]] || vec[i-1][j];

                }
                else{
                    vec[i][j]=vec[i-1][j];
                }
            }
        }
        return vec[n][target];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int val:nums){
        sum+=val;
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        
        int n=nums.size();
        vector<vector<bool>>vec(n+1,vector<bool>(target+1,false));
        return solution(nums,target,vec,n);



        
    }
};