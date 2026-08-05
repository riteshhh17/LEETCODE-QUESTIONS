class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m = t.size();
        vector<vector<unsigned long long>>vec1(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<vec1.size();i++){
            vec1[i][0]=1;

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    vec1[i][j]= vec1[i-1][j-1]+vec1[i-1][j];

                }
                else{
                    vec1[i][j]= vec1[i-1][j];
                }
            }

            
        

        }
        return vec1[n][m];
    }
};