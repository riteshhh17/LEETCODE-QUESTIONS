class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    int a= *max_element(nums.begin(),nums.end());
    vector<int>vec(a+1);
    vector<int>ans(a+1,0);
    for(int val:nums){
        vec[val]+=val;
    }  
    ans[1]=vec[1];
    for(int i=2;i<=a;i++){
        ans[i]=max(ans[i-2]+vec[i], ans[i-1]);


    }
        
       return ans[a]; 
    }
};