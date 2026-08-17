class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<stones.size();i++){
            
            if(jewels.contains(stones[i])) count++;
    
        }
        return count;
        
    }
};