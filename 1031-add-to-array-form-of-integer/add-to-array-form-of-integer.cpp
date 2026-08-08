class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        int i = num.size() - 1;
        std::vector<int> result;

       
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
                i--;
            }
            result.push_back(k % 10); 
            k /= 10;                 
        }


        std::reverse(result.begin(), result.end());
        return result;
    }
};
