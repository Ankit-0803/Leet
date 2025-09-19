class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int leftmax=0, rightmax=0;
        int j=height.size()-1;
        int maxwater=0;
        while(i<j){
            if(height[i]<height[j]){
                if(leftmax>height[i]){
                    maxwater+=leftmax-height[i];
                }
                else{
                    leftmax=height[i];
                }
                i++;
            }
            else{
                if(rightmax>height[j]){
                    maxwater+=rightmax-height[j];
                }
                else{
                    rightmax=height[j];
                }
                j--;
            }
        }
        return maxwater;  
    }
};