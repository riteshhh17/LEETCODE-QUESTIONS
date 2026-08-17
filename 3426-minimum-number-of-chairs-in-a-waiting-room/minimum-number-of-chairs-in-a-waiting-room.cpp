class Solution {
public:
    int minimumChairs(string s) {
        int room=0;
        int state=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E')state++;
            else
               state--;
            if(state>room)room++;
        }
        return room;
    }
};