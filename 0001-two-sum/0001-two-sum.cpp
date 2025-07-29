class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>numsmap;
    int n=nums.size();
    for(int i=0; i<n; i++){
        int complement=target-nums[i];
        //finding the complement in the hashmap, if it is present 
        if(numsmap.find(complement)!=numsmap.end()){
        return {numsmap[complement], i};
    }
    //or else store the current element with its index in the hash map
    numsmap[nums[i]]=i; //value, key 
    }return {};
    }
};