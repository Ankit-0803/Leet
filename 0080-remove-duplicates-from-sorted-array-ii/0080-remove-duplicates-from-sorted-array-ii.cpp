class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;  // Start writing from index 2 (first two elements are always allowed)

        // If array has 2 or fewer elements, all are allowed
        if (nums.size() <= 2) return nums.size();

        // Start checking from the 3rd element
        for (int i = 2; i < nums.size(); i++) {
            // Compare current element with the element at position k - 2
            // If they are different, the current element can stay
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];  // Overwrite the element at index k
                k++;                // Move k to next valid spot
            }
            // Else: skip current element (it's a third or further duplicate)
        }

        return k;  // Length of array with at most two duplicates allowed
    }
};
