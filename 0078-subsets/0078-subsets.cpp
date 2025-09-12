class Solution {
public:
    void recursesubset(vector<int>&nums,  int ind, vector<vector<int>>& res, vector<int>& ds){
    //base case
    int n=nums.size();
    if(ind==n){
        res.push_back(ds);
        return;
    }
    //take element or not take element
    ds.push_back(nums[ind]);
    recursesubset(nums, ind+1, res, ds);
    ds.pop_back();
    recursesubset(nums, ind+1, res, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>ds;
        recursesubset(nums, 0, res, ds);
        return res;
    }
};