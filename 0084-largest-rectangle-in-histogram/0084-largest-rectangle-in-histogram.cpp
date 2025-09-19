class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        //find NSL for all the elements
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())left[i]=-1;
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //find NSL for all the elements
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())right[i]=n;
            else{
                right[i]=st.top();
            }
            st.push(i);

        }
        //calculate max area
        int maxarea=0;
        for(int i=0; i<n; i++){
            int width=right[i]-left[i]-1;
            int area=width*heights[i];
            maxarea=max(area, maxarea);
        }
        return maxarea;
        
    }
};