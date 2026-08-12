class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);

        for(auto &log : logs) {
            diff[log[0] - 1950]++;
            diff[log[1] - 1950]--;
        }

        int population = 0;
        int maxPopulation = 0;
        int answer = 1950;

        for(int i = 0; i <= 100; i++) {
            population += diff[i];

            if(population > maxPopulation) {
                maxPopulation = population;
                answer = 1950 + i;
            }
        }

        return answer;
    }
};