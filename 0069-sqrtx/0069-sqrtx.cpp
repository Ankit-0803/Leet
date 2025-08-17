class Solution {
public:
    int mySqrt(int x) {
        // Edge case: sqrt(0) = 0
        if (x == 0) return 0;
        int low = 1, high = x, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;  // avoid overflow
            long long sq = mid * mid;
            if (sq == x) {
                return mid; // perfect square
            }
            else if (sq < x) {
                ans = mid;   // mid is a valid candidate
                low = mid + 1; // try for a bigger value
            }
            else {
                high = mid - 1; // sq > x → reduce search space
            }
        }
            return ans; // floor of sqrt(x)
    }
};
