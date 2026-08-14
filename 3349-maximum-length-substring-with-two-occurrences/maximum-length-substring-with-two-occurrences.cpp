class Solution {
public:
    int maximumLengthSubstring(string s) {
        set<char> st(s.begin(), s.end());

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            map<char, int> mp;

            int a = i - 1;
            int b = i + 1;

            mp[s[i]]++;
            int count = 1;

            while (a >= 0 || b < s.size()) {

                if (a >= 0 && mp[s[a]] < 2) {
                    mp[s[a]]++;
                    count++;
                    a--;
                }

                if (b < s.size() && mp[s[b]] < 2) {
                    mp[s[b]]++;
                    count++;
                    b++;
                }

                ans = max(ans, count);

                if ((a < 0 || mp[s[a]] >= 2) &&
                    (b >= s.size() || mp[s[b]] >= 2)) {
                    break;
                }
            }
        }

        return ans;
    }
};