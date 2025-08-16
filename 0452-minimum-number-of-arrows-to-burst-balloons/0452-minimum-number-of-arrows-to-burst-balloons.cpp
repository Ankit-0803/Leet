class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty()) return 0;
        // Step 1: Sort balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 1; // at least one arrow needed
        long long arrowPos = points[0][1]; // place arrow at the end of the first balloon
        // Step 2: Traverse balloons
        for (int i = 1; i < points.size(); i++) {
            // If the next balloon starts after current arrow position, need a new arrow
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1]; // update arrow position to this balloon's end
            }
            // else: current arrow bursts this balloon as well
        }return arrows;
    }
};