class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int n=height.size();
        int i=0, j=n-1;
        while(i<j){
        //choosing the minimum height to store the water efficiently
        int Area=min(height[i], height[j])*(j-i);
        //moving the shorter height so that area might increase
        maxArea=max(maxArea, Area);
        if(height[i]<height[j])i++;
        else j--;
        }
        return maxArea;
    }
};