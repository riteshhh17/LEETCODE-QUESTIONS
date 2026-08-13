class Solution { 
public: 
    int largestSumAfterKNegations(vector<int>& nums, int k) { 
        sort(nums.begin(), nums.end()); 
        
        int sum = 0; 
        int negc = 0; 
        
        for(int val : nums) { 
            sum += val; 
            if(val < 0) negc++; 
        } 
        
        int i = 0; 
        
        while(negc-- && k > 0) { 
            sum -= 2 * nums[i]; 
            k--; 
            i++; 
        } 
        
        if(k % 2 == 0) 
            return sum; 
        
        int mn = INT_MAX;

        if(i < nums.size())
            mn = min(mn, abs(nums[i]));

        if(i > 0)
            mn = min(mn, abs(nums[i-1]));

        return sum - 2 * mn;
    } 
};