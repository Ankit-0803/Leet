class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currend=0;
        int count=0;
        int maxreach=0;
        for(int i=0; i<n-1; i++){
            maxreach=max(maxreach, i+nums[i]);
            if(i==currend){
              count++;
              currend=maxreach;
            if(currend>=n-1)break;
            }
          
       }
       return count;
        
    }
};