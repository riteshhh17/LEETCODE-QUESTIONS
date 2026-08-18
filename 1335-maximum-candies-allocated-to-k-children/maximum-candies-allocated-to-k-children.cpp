class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        long long left = 0;
        long long right = 0;

        for (int val : candies) {
            right += val;
        }

        right /= k;

        while (left < right) {

            long long mid = left + (right - left + 1) / 2;

            long long ans = 0;

            for (int val : candies) {
                ans += val / mid;
            }

            if (ans >= k) {
                left = mid;       
            }
            else {
                right = mid - 1;  
            }
        }

        return left;
    }
};