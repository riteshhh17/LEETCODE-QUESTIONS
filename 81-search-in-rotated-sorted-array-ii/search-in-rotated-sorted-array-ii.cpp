class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int>st(nums.begin(),nums.end());
        if(st.count(target)) return true;
        return false;
        
    }
};