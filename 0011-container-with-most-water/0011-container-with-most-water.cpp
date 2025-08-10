class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int n=height.size();
        int i=0, j=n-1;
        while(i<j){
        int Area=min(height[i], height[j])*(j-i);
        maxArea=max(maxArea, Area);
        if(height[i]<height[j])i++;
        else j--;
        }
        return maxArea;
    }
};