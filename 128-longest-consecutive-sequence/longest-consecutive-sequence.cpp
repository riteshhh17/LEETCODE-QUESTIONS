class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        vector<int> vec(nums.size());
        vector<int> res(nums.size());

        int a = 0;

        vec[a] = nums[0];
        res[a] = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1]) {
                continue;
            }

            if (vec[a] == nums[i] - 1) {
                vec[a] = nums[i];
                res[a]++;
            }
            else {
                a++;
                vec[a] = nums[i];
                res[a] = 1;
            }
        }

        return *max_element(res.begin(), res.begin() + a + 1);
    }
};