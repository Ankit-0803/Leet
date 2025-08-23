class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // O(n) insert
        int longest = 0;
        for (int num : numSet) {
            // Only start counting if 'num' is the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                // Update longest streak
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
