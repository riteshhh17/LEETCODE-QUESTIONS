class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(char val:s){
            mp[val]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;

        });
        string ans="";
        for(const auto &val:v){
            int a=0;
            while(a<val.second){
                ans+=val.first;
                a++;
            }

        }
        return ans;
    }
};