class Solution {
public:
    int findClosest(int num1, int num2, int target) {
        int diff1 = abs(num1 - target);
        int diff2 = abs(num2 - target);

        // 0 → equal distance, 1 → num1 closer, 2 → num2 closer
        return (diff1 != diff2) << (diff1 > diff2);
    }
};
