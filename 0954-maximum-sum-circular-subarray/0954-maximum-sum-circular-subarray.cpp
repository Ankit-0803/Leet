class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];
        for (int n : nums) {
            totalSum += n;
            // Kadane for max subarray
            curMax = max(n, curMax + n);
            maxSum = max(maxSum, curMax);
            // Kadane for min subarray
            curMin = min(n, curMin + n);
            minSum = min(minSum, curMin);
        }
        // Case 1: All negative numbers → return maxSum
        if (maxSum < 0) return maxSum;
        // Case 2: Either normal Kadane max or circular max
        return max(maxSum, totalSum - minSum);
    }
};
