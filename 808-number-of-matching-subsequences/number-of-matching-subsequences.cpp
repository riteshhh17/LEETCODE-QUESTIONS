class Solution {
public:

    bool isSubsequence(string word, vector<vector<int>>& pos) {

        int prev = -2;

        for(char ch : word) {

            int c = ch - 'a';
            auto it = upper_bound(pos[c].begin(), pos[c].end(), prev);

            if(it == pos[c].end())
                return false;

            prev = *it;
        }

        return true;
    }


    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i++) {
            pos[s[i]-'a'].push_back(i);
        }


        int count = 0;

        for(string word : words) {

            if(isSubsequence(word, pos))
                count++;
        }

        return count;
    }
};