class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            int complementary=target-nums[i];
            if(mpp.find(complementary)!=mpp.end()){
                return {mpp[complementary], i};
            }
                mpp[nums[i]]=i;
            }
        return {-1, -1};
    }
};