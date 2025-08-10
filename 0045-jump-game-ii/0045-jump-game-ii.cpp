class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0, currend=0, farthest=0;
        for(int i=0; i<n-1; i++){
            farthest=max(farthest, i+nums[i]);
            if(i==currend){
                jumps++;
                currend=farthest;
            }
        }
        return jumps;
        
    }
};
// farthest is the farthest point we could reach if we jumped from the best index seen so far.
// currEnd is the boundary of our current jump.
// When i reaches currEnd, we must make another jump, and our next currEnd becomes farthest.
// This greedy approach ensures minimal jumps because we always extend our range as far as possible before jumping.