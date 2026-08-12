class Solution {
public:
    long long solve(int m, int n, vector<vector<int>>& grid,
                    vector<vector<long long>>& mx,
                    vector<vector<long long>>& mn) {
        const long long MOD = 1000000007;
        mx[m-1][n-1] = grid[m-1][n-1];
        mn[m-1][n-1] = grid[m-1][n-1];

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(i == m-1 && j == n-1)
                    continue;

                long long maxVal = LLONG_MIN;
                long long minVal = LLONG_MAX;

                // Move right
                if(j + 1 < n) {
                    maxVal = max(maxVal, grid[i][j] * mx[i][j+1]);
                    maxVal = max(maxVal, grid[i][j] * mn[i][j+1]);

                    minVal = min(minVal, grid[i][j] * mx[i][j+1]);
                    minVal = min(minVal, grid[i][j] * mn[i][j+1]);
                }

                // Move down
                if(i + 1 < m) {
                    maxVal = max(maxVal, grid[i][j] * mx[i+1][j]);
                    maxVal = max(maxVal, grid[i][j] * mn[i+1][j]);

                    minVal = min(minVal, grid[i][j] * mx[i+1][j]);
                    minVal = min(minVal, grid[i][j] * mn[i+1][j]);
                }

                mx[i][j] = maxVal;
                mn[i][j] = minVal;
            }
        }

        return (mx[0][0] >= 0) ? mx[0][0] % 1000000007 : -1;
    }

    int maxProductPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> mx(
            m, vector<long long>(n, LLONG_MIN)
        );

        vector<vector<long long>> mn(
            m, vector<long long>(n, LLONG_MAX)
        );

        return solve(m, n, grid, mx, mn);
    }
};