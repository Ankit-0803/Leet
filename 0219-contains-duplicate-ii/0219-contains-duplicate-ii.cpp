class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Hashmap to store the last index of each number
        unordered_map<int, int> lastIndex;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // If num was seen before
            //if (lastIndex.find(num) != lastIndex.end()) or if (lastIndex.count(num)), both are right
            if (lastIndex.count(num)) {
                // Check distance
                if (i - lastIndex[num] <= k) {
                    return true; // Duplicate found within range k
                }
            }
            // Update latest index of this number
            lastIndex[num] = i;
        }
        return false; // No such duplicates found
    }
};
