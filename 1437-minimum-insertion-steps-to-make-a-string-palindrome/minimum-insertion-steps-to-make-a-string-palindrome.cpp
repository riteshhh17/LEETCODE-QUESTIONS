class Solution {
public:
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        int m = s2.size();
        vector<vector<int>>vec1(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1]){
                    vec1[i][j]= 1+vec1[i-1][j-1];

                }
                else{
                    vec1[i][j]= max(vec1[i][j-1],vec1[i-1][j]);
                }
            }

            
        

        }
        int lcs=vec1[n][m];
         return s.size()-lcs;
        
    }
};