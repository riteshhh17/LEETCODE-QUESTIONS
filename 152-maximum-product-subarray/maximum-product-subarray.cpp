class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        vector<int> mn(n);

        mx[0] = nums[0];
        mn[0] = nums[0];

        for(int i = 1; i < n; i++) {
            mx[i] = max({
                nums[i],
                nums[i] * mx[i-1],
                nums[i] * mn[i-1]
            });

            mn[i] = min({
                nums[i],
                nums[i] * mx[i-1],
                nums[i] * mn[i-1]
            });
        }

        int ans = mx[0];

        for(int i = 1; i < n; i++) {
            ans = max(ans, mx[i]);
        }

        return ans;
    }
};