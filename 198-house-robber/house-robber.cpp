class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> vec(n, 0);

        vec[0] = nums[0];
        vec[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            vec[i] = max(vec[i-1], nums[i] + vec[i-2]);
        }

        return vec[n-1];
    }
};