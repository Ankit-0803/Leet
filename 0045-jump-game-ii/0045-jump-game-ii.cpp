class Solution {
public:
    int jump(vector<int>& nums) {
    int jumps = 0;       // Total number of jumps taken so far
    int currEnd = 0;     // The end of the current jump range
    int farthest = 0;    // The farthest index we can reach so far

    // Loop through the array up to the second-last index
    // (No need to jump from the last index)
    for (int i = 0; i < nums.size() - 1; ++i) {
        // Update the farthest we can reach from current or previous indices
        farthest = max(farthest, i + nums[i]);

        // If we have come to the end of the current jump range
        if (i == currEnd) {
            ++jumps;            // Make a jump
            currEnd = farthest; // Update the end of the next jump range
        }
    }

    return jumps; // Return the minimum number of jumps required
}

};