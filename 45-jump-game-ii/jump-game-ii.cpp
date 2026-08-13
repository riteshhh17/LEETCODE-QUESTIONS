class Solution {
public:
    int jump(vector<int>& nums) {
        int str = 0;
        int maxjump = 0;
        int currentEnd = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            maxjump = max(maxjump, i + nums[i]);

            if (i == currentEnd) {
                str++;
                currentEnd = maxjump;
            }
        }

        return str;
    }
};