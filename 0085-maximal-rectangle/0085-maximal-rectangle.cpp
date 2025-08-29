class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxAr = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop(); 
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxAr = max(maxAr, (nse - pse - 1) * heights[element]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop(); 
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxAr = max(maxAr, (nse - pse - 1) * heights[element]);
        }

        return maxAr;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();        
        int m = matrix[0].size();     
        vector<int> heights(m, 0);    
        int maxAr = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxAr = max(maxAr, largestRectangleArea(heights));
        }

        return maxAr;
    }
};