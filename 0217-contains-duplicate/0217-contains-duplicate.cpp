class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(nums[i])!=mpp.end())return true;
            mpp[nums[i]]=i;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         vector<int>freq(26,0);
//         for(int num:nums){
//             freq[num]++;
//             if(freq[num]>1)return false;
//         }
//         return true;
//     }
// };