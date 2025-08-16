class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0; // left pointer of the window
        int sum = 0;  // current window sum
        int minLength = INT_MAX; // result (infinity initially)

        // expand the window with right pointer
        for (int right = 0; right < n; right++) {
            sum += nums[right]; // include current element in window

            // shrink window until sum < target
            while (sum >= target) {
                minLength = min(minLength, right - left + 1); // update result
                sum -= nums[left]; // remove leftmost element
                left++; // shrink window
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength; // if no valid subarray
    }
};
