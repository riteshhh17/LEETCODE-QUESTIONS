class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;
        vector<int> arr = heights;

        for (int i = 0; i < arr.size() - 1; ++i) {
            bool swapped = false;

            for (int j = 0; j < arr.size() - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) {
                break;
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != heights[i]) {
                res++;
            }
        }

        return res;
    }
};