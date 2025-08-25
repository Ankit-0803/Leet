class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int complementary=0;
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
           complementary=target-nums[i];
        if(mpp.find(complementary)!=mpp.end()){
            return {i, mpp[complementary]};
        }
        mpp[nums[i]]=i;
    }
    return {-1, -1};
   }
};