class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    if(nums.size()==0) return 0;
    int a=nums[0];
    int feq=1;
    int ans=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==a) continue;
        if(nums[i]== a+1){
            a=nums[i];
            feq++;
        }
        else{
            a=nums[i];
            feq=1;
        }
       ans=max(ans,feq);
    }

    return ans;

    }
};