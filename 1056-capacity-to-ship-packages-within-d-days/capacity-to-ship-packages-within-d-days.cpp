class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());

        int right = 0;
        for (int val : weights) {
            right += val;
        }

        while (left < right) {

            int mid = left + (right - left) / 2;

            int daysNeeded = 1;
            int sum = 0;

            for (int val : weights) {

                if (sum + val > mid) {
                    daysNeeded++;
                    sum = 0;
                }

                sum += val;
            }

            if (daysNeeded <= days) {
                
                right = mid;
            }
            else {
                
                left = mid + 1;
            }
        }

        return left;
    }
};