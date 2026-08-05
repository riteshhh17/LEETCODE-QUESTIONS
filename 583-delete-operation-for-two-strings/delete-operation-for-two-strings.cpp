class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m = word2.size();
        vector<vector<int>>vec1(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    vec1[i][j]= 1+vec1[i-1][j-1];

                }
                else{
                    vec1[i][j]= max(vec1[i][j-1],vec1[i-1][j]);
                }
            }
            
        

        }
        int lcs=vec1[n][m];
        int ans=0;
        if(word1.size()>lcs) ans=ans+word1.size()-lcs;
        if(word2.size()>lcs) ans=ans+word2.size()-lcs;
        return ans;       
        
    }
};