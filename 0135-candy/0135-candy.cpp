class Solution {
public:
    int candy(vector<int>& ratings, int cnt = 0) {
        int n = ratings.size();
         // Step 1: Initialize a candies array, each child gets at least 1 candy
        vector<int> candies(n, 1);
        // Step 2: Left to Right Pass
        for (int i = 1; i < n; i++) 
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
         // Step 3: Right to Left Pass
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            cnt += candies[i - 1];
        }
        //Step 4: Add candies of the last child (not included in loop sum)
        return cnt + candies[n - 1];
    }
};