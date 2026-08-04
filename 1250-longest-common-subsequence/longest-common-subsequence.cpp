class Solution {
public:
   int lcs(string text1, string text2,vector<vector<int>>&vec1){
    for(int i=1;i<=text1.size();i++){
     for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                vec1[i][j]=1+vec1[i-1][j-1];
            }
            else{
                vec1[i][j] = max(vec1[i-1][j],vec1[i][j-1]);
            }

        }

        }
        return vec1[text1.size()][text2.size()];
    
    
   }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>vec1(1001,vector<int>(1001,-1));
       
        for(int i=0;i<=text1.size();i++){
            vec1[0][i]=0;

        }
         for(int i=0;i<=text2.size();i++){
            vec1[i][0]=0;

        }
        return lcs(text1,text2,vec1);
        
    }
};