class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid= left+(right-left)/2;
            long long ans=0;
            for(const auto &val:nums){
                ans+= (val+mid-1)/mid;
            }
                if(ans<=threshold) right=mid;
                else
                    left=mid+1;

            
        }

        return left;
    }
};