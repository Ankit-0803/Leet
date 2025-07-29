class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        // Step 1: Sort the array to apply two-pointer strategy
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element and find two other numbers
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;       // Second element
            int right = n - 1;      // Third element

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for second and third numbers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++; // Increase sum
                }
                else {
                    right--; // Decrease sum
                }
            }
        }

        return result;
    }
};
