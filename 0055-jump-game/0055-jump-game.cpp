class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0; //farthest index we can reach so far
        for(int i=0; i<nums.size(); i++){
            if(i>maxReach)return false;
            maxReach=max(maxReach, i+nums[i]);
        }
        return true; //loop completed successfully
    }
};
// At i = 4, we find that the index 4 is beyond the farthest reachable position (maxReach = 3).
// This means we cannot get to index 4, so we return false.